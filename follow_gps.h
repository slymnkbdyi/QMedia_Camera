#ifndef FOLLOW_GPS_H
#define FOLLOW_GPS_H
#include<QTcpSocket>
#include <QObject>
#include<QAbstractSocket>

class follow_gps : public QObject
{
    Q_OBJECT
public:
    explicit follow_gps(QObject *parent = 0);

    bool Connect();
    QString dev_id;
double convertToDecimal(double val);
signals:

    void send_gps(QString lati,QString longi);
public slots:
    void take_device_id(QString device_id);
    void Read_Data();
  private:
    QTcpSocket *socket;
};

#endif // FOLLOW_GPS_H
