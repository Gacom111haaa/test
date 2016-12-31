#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{

}

void MyWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawEllipse(80, 80, 100, 100);
}
