#include "cgpslogwidget.h"

CGPSlogWidget::CGPSlogWidget(QWidget *parent) :
    QWidget(parent)
{
    ui.setupUi(this);
    m_log = new CLogFile;
}

void CGPSlogWidget::f_appendData(QByteArray buff)
{
    QString str_buff = QString::fromUtf8(buff);
    ui.textEdit->append(str_buff);

    QStringList str_list;
    str_list = str_buff.split("$");
    for(int index = 0; index <str_list.length();index++)
    {
        QString str = str_list.at(index);
        if(str.contains("*"))
        {
        ui.textEdit_2->append(str);
        }
        if(str.contains("GPGGA"))
        {
            QStringList list = str.split(",");
            ui.m_time->setText(list.at(1));
            ui.m_lon->setText(list.at(2)+list.at(3));
            ui.m_lat->setText(list.at(4)+list.at(5));
            ui.m_alt->setText(list.at(9)+list.at(10));

            m_log->f_writeToFile(str);
        }
    }

}
