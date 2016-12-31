#ifndef TEST_H
#define TEST_H

#include <QWidget>
#include <stdio.h>

namespace Ui {
class test;
}

class test : public QWidget
{
    Q_OBJECT

public:
    explicit test(QWidget *parent = 0);
    ~test();

private:
    Ui::test *ui;
private slots:
    int onRecvUART();
};

#endif // TEST_H
