#include "test.h"
#include "ui_test.h"
#include "wiringPi.h"
#include "wiringSerial.h"
#include <QTimer>
QTimer *rxTimer;

int fd;
test::test(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::test)
{
    ui->setupUi(this);
    if (wiringPiSetup () == -1)
    {
        printf ( "Unable to start wiringPi\n") ;
        return ;
    }
    if ((fd = serialOpen ("/dev/ttyS0", 9600)) < 0)
    {
        //printf(ui->lineEdit->text().toStdString().data());
        //fflush (stdout) ;
        printf("Not connected") ;
        return ;
    }
    rxTimer = new QTimer(this);
    connect(rxTimer, SIGNAL(timeout()), this, SLOT(onRecvUART()));
    rxTimer->start(20);
}
int test::onRecvUART()
{
    QByteArray rd;
#ifndef Q_OS_WIN
    while(serialDataAvail(fd)>0)
    {

        rd.append(serialGetchar (fd));
        //printf (rd.data());
    }
#endif
    if(rd.size())
    {
        ui->textEdit->append(QString::fromUtf8(rd));
        //showStatus("Device ready");
        return rd.size();
    }
    else
    {
        return 0;
    }

    //fflush(stdout);
    //if(rd.size()>0)ui->lineEdit->setText(ui->lineEdit->text() + rd.toHex());
    //ui->lineEdit->

}
test::~test()
{
    delete ui;
}
