#include "cserialport.h"
int fd;
CSerialPort::CSerialPort()
{
    if( wiringPiSetup()== -1)
    {
        qDebug("Unable to start wiringPi\n");
        return;
    }
    fd = serialOpen ("/dev/ttyS0", 9600);

    if (fd <0)
    {
        qDebug("cannot open serial port \n");
    }
}

int CSerialPort::f_TransmitData(QByteArray *)
{

}

QByteArray CSerialPort::f_ReceiveData()
{
    QByteArray rx;
    while(serialDataAvail(fd)>0)
    {
        rx.append(serialGetchar(fd));
    }

    if(rx.size())
    {
//        ui->textEdit_data_log->append(QString::fromUtf8(rd));
//        //showStatus("Device ready");
        qDebug("Size of receivedata in serialport: %d \n",rx.size());
        return rx;
    }
    else
    {
        return 0;
    }
}
