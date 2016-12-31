#ifndef CSERIALPORT_H
#define CSERIALPORT_H
#include "wiringPi.h"
#include "wiringSerial.h"
#include "stdio.h"
#include <QByteArray>

class CSerialPort
{
public:
    CSerialPort();
    void f_InitSerialPort();
    int f_TransmitData(QByteArray *);
    QByteArray f_ReceiveData();
private:
    int m_check;
    bool m_status;
};

#endif // CSERIALPORT_H
