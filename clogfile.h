#ifndef CLOGFILE_H
#define CLOGFILE_H
#include <QtGui>
#include "QDateTime"
#include "QTextStream"
#include "QFile"
class CLogFile
{
public:
    CLogFile();
    void f_createNewFile();
    void f_writeToFile(QString line_text);
    void f_readFromFile(QString filename);
    void f_setFileName(QString filename);
private:
    QString m_pathDir;
    QString m_fileName;
//    QTextStream m_textStream;
//    QFile m_file;
};

#endif // CLOGFILE_H
