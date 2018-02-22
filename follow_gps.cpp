#include "follow_gps.h"
#include<QDebug>

follow_gps::follow_gps(QObject *parent) : QObject(parent)
{

}
struct gps_log {

    uint8_t     msgtype;

    uint32_t    rfu0; // buslineId

    uint32_t    rfu1; // stationId

    time_t      tm;

    double      lat;

    double      lon;

    uint8_t     sig;

    uint8_t     satcc;

    uint16_t    speed;

    uint16_t    direction;

    int16_t     height;

    uint8_t     igsw;

    uint32_t  dev_id;

};
QString lon_deg;
QString lon_min;
QString lat_deg;
QString lat_min;
QStringList lon;
QStringList lat;
void follow_gps::take_device_id(QString device_id)
{

    lon<<"28.72240697841678";
    lon<<"28.72153754614704";
    lon<<"28.72252569182762";
    lon<<"28.72359938781506";
    lon<<"28.72363714205827";
    lon<<"28.72251304742508";
    lon<<"28.72204182160114";
    lon<<"28.72127311329151";
    lon<<"28.72135165707153";
    lon<<"28.72238140092278";
    lon<<"28.72272184036486";
    lon<<"28.72264164529759";
    lon<<"28.72236565048013";
    lon<<"28.7220518823142";
    lon<<"28.72237231553875";
    lon<<"28.72261768211633";
    lon<<"28.72245817547941";
    lon<<"28.72203443821611";
    lon<<"28.7216403371911";
    lon<<"28.72153500124531";


    lat<<"40.99431155033471";
    lat<<"40.99351242120727";
    lat<<"40.99246990006552";
    lat<<"40.99109776258788";
    lat<<"40.99037817009581";
    lat<<"40.98939410060945";
    lat<<"40.98907856855106";
    lat<<"40.98904074261611";
    lat<<"40.98847531173909";
    lat<<"40.98776737103842";
    lat<<"40.9872933250093";
    lat<<"40.98640328944296";
    lat<<"40.9858330831446";
    lat<<"40.98486708351312";
    lat<<"40.98413912059728";
    lat<<"40.98354999274505";
    lat<<"40.98310018454988";
    lat<<"40.98300697933539";
    lat<<"40.98308557886173";
    lat<<"40.98272759820983";



    dev_id=device_id;
    qDebug()<<device_id;


    if(Connect())
    {
       socket->write("hello server \r\n");
       socket->waitForBytesWritten(1000);

    }

}
bool follow_gps::Connect()
{
    socket = new QTcpSocket(this);
    connect(socket,SIGNAL(readyRead()),this,SLOT(Read_Data()));
    socket->connectToHost("192.168.0.16",30146);
    if(socket->waitForConnected(3000))
    {
        qDebug()<<"connected";
        return true;
    }
    else
    {

        qDebug()<<socket->errorString();
        return false;
    }
}
static int repeat=0;
void follow_gps::Read_Data()
{



  QByteArray ba=socket->readAll();

//  if (ba.size() >=44)
  gps_log n;
  const char *ptr = ba.constData() + 1;
  n.msgtype = *ptr;
  ptr++;
  memcpy(&n.rfu0, ptr, 4);
  ptr += 4;
  memcpy(&n.rfu1, ptr, 4);
  ptr += 4;
  memcpy(&n.tm, ptr, 4);
  ptr += 4;
  memcpy(&n.lat, ptr, 8);
  ptr += 8;
  memcpy(&n.lon, ptr, 8);
  ptr += 8;
  memcpy(&n.sig, ptr, 1);
  ptr += 1;
  memcpy(&n.satcc, ptr, 1);
  ptr += 1;
  memcpy(&n.speed, ptr, 2);
  ptr += 2;
  memcpy(&n.direction, ptr, 2);
  ptr += 2;
  memcpy(&n.height, ptr, 1);
  ptr += 1;
  memcpy(&n.igsw, ptr, 1);
  ptr += 1;
  memcpy(&n.dev_id, ptr, 4);
  ptr += 4;

 qDebug()<<ba.toHex();

 qDebug()<< "Device id : " << n.dev_id << "igsw"<< n.igsw;
  if(n.dev_id==53)
  {
      send_gps(QString::number(convertToDecimal(n.lat)),QString::number(convertToDecimal(n.lon)));
  }

//      send_gps(lat[repeat],lon[repeat]);
//      repeat++;


}

 double follow_gps::convertToDecimal(double val)
 {

    int degree = (int)(val/100);
    //qDebug()<<degree;
    double minutes = val - (degree *100);
    //qDebug()<<minutes;
    return degree + (minutes/60);
}
