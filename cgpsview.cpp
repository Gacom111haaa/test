#include "cgpsview.h"
#include "ui_cgpsview.h"

CGPSView::CGPSView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CGPSView)
{
    ui->setupUi(this);
}

CGPSView::~CGPSView()
{
    delete ui;
}
