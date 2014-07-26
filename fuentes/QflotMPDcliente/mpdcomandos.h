#ifndef MPDCOMANDOS_H
#define MPDCOMANDOS_H

#include <QObject>
#include <QStringList>

/**********************************************************
 *  cuando se lea o se escriba en la base de datos, lanzar un hilo con la petición, el hilo actualizará la barra de mensajes de la aplicación mientras realiza la tarea

cuando actualice la barra de mensajes, cambiar de color el mensaje

cuando termine la tarea se avisará en la barra de mensajes durante un corto tiempo

antes de salir de la aplicación se finalizarán las tareas
si una tarea sale mal, repetirla tres veces, si sigue saliendo mal, preguntarle al usuario qué quiere hacer

 **********************************************************/

//---------------------------------------------------------

enum MPDrespuesta
{
    _MPD_RSP_,
    _MPD_RSP_BIENVENIDO_
};

enum MPDpeticion
{
    _MPD_PET_,
    _MPD_PET_status_,
    _MPD_PET_stats_
};

//·························································

struct PeticionMPD
{
    MPDpeticion     tipo;
    QString         comando;
    QString         parametro;
    QStringList     parametros;
    QByteArray      byteArray;

    PeticionMPD(void)
    {
        tipo        = _MPD_PET_;
    }
};


struct RespuestaMPD
{
    MPDrespuesta    tipo;
    QStringList     lineas;

    RespuestaMPD(void)
    {
        tipo        = _MPD_RSP_;
    }
};

//---------------------------------------------------------

class ProtocoloMPD : public QObject
{
    Q_OBJECT

public: //·················································

    explicit ProtocoloMPD(QObject *parent = 0);
    explicit ProtocoloMPD(QByteArray recibido,
                         QObject *parent = 0);

    static QByteArray armarPeticion( QString comando );

private: //················································

    PeticionMPD         _peticion;
    RespuestaMPD        _respuesta;


    bool cargarRespuesta(QStringList _strlRespuesta );

signals: //················································

    void respuestaProcesada(RespuestaMPD _prm_RespuestaMPD);

public slots: //··········································

    void procesarRespuesta(QByteArray _prm_baRespuesta );
};

//---------------------------------------------------------

#endif // MPDCOMANDOS_H
