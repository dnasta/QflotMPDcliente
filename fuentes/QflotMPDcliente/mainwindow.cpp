#include "mainwindow.h"
#include "ui_mainwindow.h"

/******************************************************************************
 *  cuando se envie o se reciba desde el servidor mpd, lanzar un hilo con la petición,
 *  el hilo actualizará la barra de mensajes de la aplicación mientras realiza la tarea
 *
 *  cuando actualice la barra de mensajes, cambiar de color el mensaje
 *
 *  cuando termine la tarea se avisará en la barra de mensajes durante un corto tiempo
 *
 *  antes de salir de la aplicación se finalizarán las tareas
 *  si una tarea sale mal, repetirla tres veces, si sigue saliendo mal,
 *  preguntarle al usuario qué quiere hacer
 *
 *·············································································
 *  cuando la clase reciba una peticion desde la aplicacion, la pondra en la cola
 *  enviará ordenadamente cada peticion al servidor, esperara una respuesta y la
 *  asociara a la peticion de la lista, la aplicacion podra consultar el estado
 *  de cada peticion desde la lista
 *
 *  cada peticion informara de sus cambios mediante señales
 *
 *  cada peticion sera un hilo que lanzara la clase, este hilo enviara la peticion
 *  y almacenara la respuesta
 *
 *  la aplicacion sera la responsable de matar al hilo
 ******************************************************************************/

//-----------------------------------------------------------------------------

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), networkSession(0)
{
    ui->setupUi(this);

    tcpSocket = new QTcpSocket(this);

    conectarSignalSlots();
}

//·············································································

MainWindow::~MainWindow()
{
    tcpSocket->abort();
    delete ui;
}

//-----------------------------------------------------------------------------

void MainWindow::conectarSignalSlots()
{
    conectarSignalSlots_TCP();
    conectarSignalSlots_botones();
}

//·············································································

void MainWindow::conectarSignalSlots_TCP()
{
    connect(
                tcpSocket,
                SIGNAL(readyRead()),
                this,
                SLOT(tcpRedyRead())
                );
    connect(
                tcpSocket,
                SIGNAL(error(QAbstractSocket::SocketError)),
                this,
                SLOT(tcpError(QAbstractSocket::SocketError))
                );
}

void MainWindow::conectarSignalSlots_botones()
{
    connect(
                ui->btnEsperarCambios,
                SIGNAL(clicked()),
                this,
                SLOT(botonEsperarCambios())
                );
    connect(    /* MainWindow::botonEsperarCambios() */
                ui->btnConectar,
                SIGNAL(clicked()),
                this,
                SLOT(botonConectar())
                );
    connect(    /* MainWindow::botonEsperarCambios() */
                ui->btnEstado,
                SIGNAL(clicked()),
                this,
                SLOT(botonEstado())
                );
    connect(    /* MainWindow::botonEsperarCambios() */
                ui->btnEstadisticas,
                SIGNAL(clicked()),
                this,
                SLOT(botonEstadisticas())
                );
    connect(    /* MainWindow::botonEsperarCambios() */
                ui->btnItemActual,
                SIGNAL(clicked()),
                this,
                SLOT(botonItemActual())
                );
    connect(    /* MainWindow::botonEsperarCambios() */
                ui->btnInfoLista,
                SIGNAL(clicked()),
                this,
                SLOT(botonInfoLista())
                );
    connect(    /* MainWindow::botonEsperarCambios() */
                ui->btnListaComandos,
                SIGNAL(clicked()),
                this,
                SLOT(botonListaDeComandos())
                );
    connect(
                ui->btnTiposTags,
                SIGNAL(clicked()),
                this,
                SLOT(botonTiposTags())
                );
}

//-----------------------------------------------------------------------------

void MainWindow::tcpRedyRead()
{
    QByteArray baRecibido;

    ui->plainTextEdit->appendPlainText( "----------------------------------------" );

    ui->plainTextEdit->appendPlainText( QString("tcpSocket->bytesAvailable( %1 )").arg(
                                            tcpSocket->bytesAvailable()) );

    // si leo antes de bytesAvailable, retorna 0 porque cuando lee vacia el buffer
    baRecibido = tcpSocket->readAll();

    QString recibido( baRecibido );

    //******** Protocolo MPD ********
    // http://www.musicpd.org/doc/protocol/

    ui->plainTextEdit->appendPlainText( recibido );

    ui->plainTextEdit->appendPlainText( "----------------------------------------" );
}

//·············································································

void MainWindow::tcpError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        ui->plainTextEdit->appendPlainText( "The host was not found. Please check the "
                                            "host name and port settings.");
        break;
    case QAbstractSocket::ConnectionRefusedError:
        ui->plainTextEdit->appendPlainText( "The connection was refused by the peer. "
                                            "Make sure the fortune server is running, "
                                            "and check that the host name and port "
                                            "settings are correct.");
        break;
    default:
        ui->plainTextEdit->appendPlainText( QString("The following error occurred: %1.").arg(
                                                tcpSocket->errorString()) );
    }
}

//-----------------------------------------------------------------------------

void MainWindow::botonConectar()
{
    tcpSocket->abort();
    tcpSocket->connectToHost( "192.168.0.110", 6688 );
    /*
        tcpSocket->bytesAvailable( 14 )
        OK MPD 0.16.0\n
    */
}

void MainWindow::botonEsperarCambios()
{
    if ( tcpSocket->isOpen() )
    {
        if ( ui->btnConectar->isEnabled() )
        {
            ui->plainTextEdit->appendPlainText( "esperando cambios de estado..." );

            tcpSocket->write( ProtocoloMPD::armarPeticion( "idle" ) );
            /*

             */

            ui->btnConectar->setEnabled( false );
            ui->btnEstadisticas->setEnabled( false );
            ui->btnEstado->setEnabled( false );
            ui->btnItemActual->setEnabled( false );
            ui->btnInfoLista->setEnabled( false );
            ui->btnListaComandos->setEnabled( false );
            ui->btnTiposTags->setEnabled( false );
        }
        else
        {
            ui->plainTextEdit->appendPlainText( "finalizando espera de "
                                                "cambios de estado..." );

            tcpSocket->write( ProtocoloMPD::armarPeticion( "noidle" ) );
            /*

             */
            ui->btnConectar->setEnabled( true );
            ui->btnEstadisticas->setEnabled( true );
            ui->btnEstado->setEnabled( true );
            ui->btnItemActual->setEnabled( true );
            ui->btnInfoLista->setEnabled( true );
            ui->btnListaComandos->setEnabled( true );
            ui->btnTiposTags->setEnabled( true );
        }
    }
    else
        ui->plainTextEdit->appendPlainText( "desconectado" );
}

//·············································································

void MainWindow::botonEstado()
{
    if ( tcpSocket->isOpen() )
    {
        ui->plainTextEdit->appendPlainText( "pidiendo estado..." );

        tcpSocket->write( ProtocoloMPD::armarPeticion( "status" ) );
        /*
            tcpSocket->bytesAvailable( 191 )
            volume: 14
            repeat: 0
            random: 1
            single: 0
            consume: 0
            playlist: 2
            playlistlength: 13
            xfade: 0
            mixrampdb: 0.000000
            mixrampdelay: nan
            state: stop
            song: 12
            songid: 12
            nextsong: 3
            nextsongid: 3
            OK
         */
    }
    else
        ui->plainTextEdit->appendPlainText( "desconectado" );
}

//·············································································

void MainWindow::botonEstadisticas()
{
    if ( tcpSocket->isOpen() )
    {
        ui->plainTextEdit->appendPlainText( "pidiendo estadisticas..." );

        tcpSocket->write( ProtocoloMPD::armarPeticion( "stats" ) );
        /*
            tcpSocket->bytesAvailable( 111 )
            artists: 290
            albums: 1337
            songs: 15165
            uptime: 18238
            playtime: 0
            db_playtime: 3889678
            db_update: 1401733338
            OK
         */
    }
    else
        ui->plainTextEdit->appendPlainText( "desconectado" );
}

void MainWindow::botonItemActual()
{
    if ( tcpSocket->isOpen() )
    {
        ui->plainTextEdit->appendPlainText( "pidiendo datos del ítem..." );

        tcpSocket->write( ProtocoloMPD::armarPeticion( "currentsong" ) );
        /*
            tcpSocket->bytesAvailable( 230 )
            file: Al Jarreau/2004 Accentuate the Positive/01 Al Jarreau - cold duck.mp3
            Last-Modified: 2012-11-07T13:54:33Z
            Time: 227
            Artist: Al Jarreau
            Title: Cold Duck
            Album: Accentuate the Positive
            Date: 2004
            Genre: Blues
            Pos: 1
            Id: 25
            OK
         */
    }
    else
        ui->plainTextEdit->appendPlainText( "desconectado" );
}

void MainWindow::botonInfoLista()
{
    if ( tcpSocket->isOpen() )
    {
        ui->plainTextEdit->appendPlainText( "pidiendo datos de la lista..." );

        tcpSocket->write( ProtocoloMPD::armarPeticion( "playlistinfo" ) );
        /*
            tcpSocket->bytesAvailable( 2552 )
            file: Al Jarreau/2004 Accentuate the Positive/02 Al Jarreau - the nearness of you.mp3
            Last-Modified: 2012-11-07T13:54:34Z
            Time: 224
            Artist: Al Jarreau
            Title: The Nearness Of You
            Album: Accentuate the Positive
            Date: 2004
            Genre: Blues
            Pos: 0
            Id: 24
            [...]
            file: Al Jarreau/2004 Accentuate the Positive/05 Al Jarreau - midnight sun.mp3
            Last-Modified: 2012-11-07T13:54:32Z
            Time: 362
            Artist: Al Jarreau
            Title: Midnight Sun
            Album: Accentuate the Positive
            Date: 2004
            Genre: Blues
            Pos: 10
            Id: 34
            OK
         */
    }
    else
        ui->plainTextEdit->appendPlainText( "desconectado" );
}

void MainWindow::botonListaDeComandos()
{
    if ( tcpSocket->isOpen() )
    {
        ui->plainTextEdit->appendPlainText( "pidiendo lista de comandos permitidos..." );

        tcpSocket->write( ProtocoloMPD::armarPeticion( "commands" ) );
        /*
            tcpSocket->bytesAvailable( 1323 )
            command: add
            command: addid
            command: clear
            command: clearerror
            command: close
            command: commands
            [...]
            command: stats
            command: status
            command: sticker
            command: stop
            command: swap
            command: swapid
            command: tagtypes
            command: update
            command: urlhandlers
            OK
         */

        ui->plainTextEdit->appendPlainText( "pidiendo lista de comandos negados..." );

        tcpSocket->write( ProtocoloMPD::armarPeticion( "notcommands" ) );
        /*
            tcpSocket->bytesAvailable( 3 )
            OK
         */
    }
    else
        ui->plainTextEdit->appendPlainText( "desconectado" );
}

void MainWindow::botonTiposTags()
{
    if ( tcpSocket->isOpen() )
    {
        ui->plainTextEdit->appendPlainText( "pidiendo tipos de tags permitidos..." );

        tcpSocket->write( ProtocoloMPD::armarPeticion( "tagtypes" ) );
        /*
            tcpSocket->bytesAvailable( 347 )
            tagtype: Artist
            tagtype: ArtistSort
            tagtype: Album
            tagtype: AlbumArtist
            tagtype: AlbumArtistSort
            tagtype: Title
            tagtype: Track
            tagtype: Name
            tagtype: Genre
            tagtype: Date
            tagtype: Composer
            tagtype: Performer
            tagtype: Disc
            tagtype: MUSICBRAINZ_ARTISTID
            tagtype: MUSICBRAINZ_ALBUMID
            tagtype: MUSICBRAINZ_ALBUMARTISTID
            tagtype: MUSICBRAINZ_TRACKID
            OK
         */
    }
    else
        ui->plainTextEdit->appendPlainText( "desconectado" );
}

//-----------------------------------------------------------------------------
