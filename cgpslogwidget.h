#ifndef CGPSLOGWIDGET_H
#define CGPSLOGWIDGET_H

#include <QWidget>
#include "QtGui"
#include "QByteArray"
#include "ui_cgpslog.h"
#include "clogfile.h"
class CGPSlogWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CGPSlogWidget(QWidget *parent = 0);
    void f_appendData(QByteArray buff);
private:
    Ui::CGPSlog ui;
    CLogFile *m_log;

signals:

public slots:

};

#endif // CGPSLOGWIDGET_H
