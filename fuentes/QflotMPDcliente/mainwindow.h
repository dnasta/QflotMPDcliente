#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QtNetwork>

#include <mpdcomandos.h>

namespace Ui {
class MainWindow;
}

//---------------------------------------------------------

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public: //·················································

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
    //········ public ·····································

protected: //··············································



    //········ protected ··································

private: //················································

    Ui::MainWindow *ui;

    QTcpSocket          *tcpSocket;
    QNetworkSession     *networkSession;


    void conectarSignalSlots(void);
    void  conectarSignalSlots_TCP(void);
    void  conectarSignalSlots_botones(void);

    //········ private ····································

private slots: //··········································

    void tcpRedyRead(void);
    void tcpError(QAbstractSocket::SocketError socketError);

    void botonConectar(void);
    void botonEsperarCambios(void);
    void botonEstado(void);
    void botonEstadisticas(void);
    void botonItemActual(void);
    void botonInfoLista(void);
    void botonListaDeComandos(void);
    void botonTiposTags(void);

    //········ private slots ······························

signals: //················································



    //········ signals ····································
};

//---------------------------------------------------------

#endif // MAINWINDOW_H
