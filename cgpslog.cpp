#include "cgpslog.h"
#include "ui_cgpslog.h"

CGPSlog::CGPSlog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CGPSlog)
{
    ui->setupUi(this);
}

CGPSlog::~CGPSlog()
{
    delete ui;
}

