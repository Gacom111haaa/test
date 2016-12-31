#ifndef CGPSLOG_H
#define CGPSLOG_H

#include <QWidget>
#include <QtGui>
#include <QByteArray>
namespace Ui {
class CGPSlog;
}

class CGPSlog : public QWidget
{
    Q_OBJECT

public:
    explicit CGPSlog(QWidget *parent = 0);
    ~CGPSlog();    
private:
    Ui::CGPSlog *ui;
};

#endif // CGPSLOG_H
