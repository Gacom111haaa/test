#include "clogfile.h"

CLogFile::CLogFile()
{
    QDateTime time_now = QDateTime::currentDateTime();
    QString str_time_current = time_now.toString("hh:mm:ss.zzz");
    QString str_date_current = time_now.toString("dd.MM.yyyy");
    QString str_date_time = str_date_current + ":" +str_time_current;
    f_setFileName(str_date_time);
    f_createNewFile();
//    f_writeToFile("helllllo!");
}

void CLogFile::f_createNewFile( )
{
    QFile file(m_fileName);
    file.open((QFile::ReadWrite));
}

void CLogFile::f_writeToFile(QString line_text)
{
    QFile file(m_fileName);
    file.open((QFile::Append));
    QTextStream out(&file);
    out<<line_text<<"\n";
}

void CLogFile::f_readFromFile(QString filename)
{

}

void CLogFile::f_setFileName(QString filename)
{
    QDir dir;
    m_fileName = dir.currentPath() + "/logs/" + filename +".txt";
}
