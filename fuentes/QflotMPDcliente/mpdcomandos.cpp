#include "mpdcomandos.h"

//-----------------------------------------------------------------------------

ProtocoloMPD::ProtocoloMPD(QObject *parent) :
    QObject(parent)
{
}

//·············································································

ProtocoloMPD::ProtocoloMPD(QByteArray recibido, QObject *parent) :
    QObject(parent)
{
    procesarRespuesta( recibido );
}

//-----------------------------------------------------------------------------
// static
QByteArray ProtocoloMPD::armarPeticion(QString comando)
{
    QByteArray ba;

    ba = comando.toUtf8();
    ba.append('\n');

    return ba;
}

//·············································································
// private:
bool ProtocoloMPD::cargarRespuesta(QStringList strlRespuesta)
{
    /*
        tcpSocket->bytesAvailable( 14 )
        OK MPD 0.16.0\n
    */
    if ( strlRespuesta.size() > 0 )
    {
        /* si la respuesta recibida comienza con "OK MPD" */
        if ( strlRespuesta.at(0).indexOf( "OK MPD" ) == 0 )
        {
            /*  */
            _respuesta.tipo = _MPD_RSP_BIENVENIDO_;

            return true;
        }
        else
            return false;
    }
    else
        return false;
}

//·············································································

void ProtocoloMPD::procesarRespuesta(QByteArray _prm_baRespuesta)
{
    QString respuesta( _prm_baRespuesta );

    _respuesta.lineas = respuesta.split( "\n" );

    cargarRespuesta( _respuesta.lineas );

    emit respuestaProcesada( _respuesta );
}

//-----------------------------------------------------------------------------
