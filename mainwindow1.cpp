#include "mainwindow1.h"
#include "ui_mainwindow1.h"
#include "map.h"

MainWindow1::MainWindow1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow1)
{
    ui->setupUi(this);

    f_initElement();

    setCentralWidget(m_mapcanvas);
    f_create_actions();
    f_create_menus();
    f_create_tools_bar();
    f_create_status_bar();

}

MainWindow1::~MainWindow1()
{
    delete ui;
}
void MainWindow1::f_create_actions()
{
    //--------------------- file actions
    action_file_close = new QAction(tr("Close"),this);
    action_file_close->setStatusTip(tr("Close file"));
    connect(action_file_close,SIGNAL(triggered(bool)),this,SLOT(s_file_close()));

    action_file_open = new QAction(tr("Open"),this);
    action_file_open->setStatusTip(tr("Open file"));
    connect(action_file_open,SIGNAL(triggered(bool)),this,SLOT(s_file_open()));

    action_file_new = new QAction(tr("New"),this);
    action_file_new->setStatusTip(tr("New file"));
    connect(action_file_new,SIGNAL(triggered(bool)),this,SLOT(s_file_new()));

    action_file_save = new QAction(tr("Save"),this);
    action_file_save->setStatusTip(tr("Save file"));
    connect(action_file_save,SIGNAL(triggered(bool)),this,SLOT(s_file_save()));
    //----------------------------- tools actions
    action_tool_GPS = new QAction(tr("GPS log"),this);
    action_tool_GPS->setStatusTip(tr("GPS log"));
    connect(action_tool_GPS,SIGNAL(triggered(bool)),this,SLOT(s_tool_gps()));
    //---------------------- draw actions
    action_draw_line = new QAction(tr("Line"),this);
    action_draw_line->setStatusTip(tr("Draw line"));
    connect(action_draw_line,SIGNAL(triggered(bool)),this,SLOT(s_draw_line()));

    action_draw_circle = new QAction(tr("Circle"),this);
    action_draw_circle->setStatusTip(tr("Draw circle"));
    connect(action_draw_circle,SIGNAL(triggered(bool)),this,SLOT(s_draw_circle()));

    action_draw_rectangle = new QAction(tr("Rectangle"),this);
    action_draw_rectangle->setStatusTip(tr("Draw rectangle"));
    connect(action_draw_rectangle,SIGNAL(triggered(bool)),this,SLOT(s_draw_rectangle()));

    //--------------------- map actions

    action_zoomIn_mode = new QAction(tr("Zoom in"),this);
    action_zoomIn_mode->setStatusTip(tr("Zoom in mode"));
    connect(action_zoomIn_mode,SIGNAL(triggered(bool)),this,SLOT(s_map_zoomInMode()));

    action_zoomOut_mode = new QAction(tr("Zoom out"),this);
    action_zoomOut_mode->setStatusTip(tr("Zoom out mode"));
    connect(action_zoomOut_mode,SIGNAL(triggered(bool)),this,SLOT(s_map_zoomOutMode()));

    action_pan_mode = new QAction(tr("Pan"),this);
    action_pan_mode->setStatusTip(tr("Pan mode"));
    connect(action_pan_mode,SIGNAL(triggered(bool)),this,SLOT(s_map_panMode()));

    action_select_mode = new QAction(tr("Select"),this);
    action_select_mode->setStatusTip(tr("Select mode"));
    connect(action_select_mode,SIGNAL(triggered(bool)),this,SLOT(s_map_selectMode()));

}
void MainWindow1::f_create_menus()
{
    menu_bar = menuBar()->addMenu("File");
    menu_bar->addAction(action_file_new);
    menu_bar->addAction(action_file_open);
    menu_bar->addAction(action_file_save);
    menu_bar->addAction(action_file_close);

    menu_tools = menuBar()->addMenu("Tools");
    menu_tools->addAction(action_tool_GPS);

}
void MainWindow1::f_create_status_bar()
{

}
void MainWindow1::f_create_tools_bar()
{
    //---------------------------------------------- draw tool bar
    tool_bar_draw = addToolBar(tr("Draw tools"));
    tool_bar_draw->addAction(action_draw_line);
    tool_bar_draw->addAction(action_draw_circle);
    tool_bar_draw->addAction(action_draw_rectangle);
    //----------------------------------------------- map tool bar
    tool_bar_map = addToolBar(tr("Map tools"));
    tool_bar_map->addAction(action_select_mode);
    tool_bar_map->addAction(action_pan_mode);
    tool_bar_map->addAction(action_zoomIn_mode);
    tool_bar_map->addAction(action_zoomOut_mode);

}
void MainWindow1::s_draw_circle()
{

}
void MainWindow1::s_draw_line()
{

}
void MainWindow1::s_draw_rectangle()
{

}
void MainWindow1::s_file_close()
{

}
void MainWindow1::s_file_new()
{

}

void MainWindow1::s_tool_gps()
{
    m_gpgwidget->show();
}
void MainWindow1::s_file_save()
{

}
void MainWindow1::s_file_open()
{

}
void MainWindow1::s_map_panMode()
{
    QApplication::setOverrideCursor(Qt::OpenHandCursor);
    m_mapcanvas->sl_pan();
}
void MainWindow1::s_map_zoomInMode()
{
    m_mapcanvas->sl_zoomIn();
}
void MainWindow1::s_map_zoomOutMode()
{
    m_mapcanvas->sl_zoomOut();
}
void MainWindow1::s_map_selectMode()
{
    QApplication::setOverrideCursor(Qt::ArrowCursor);
}

void MainWindow1::s_gpsReceive()
{
    qDebug("Timer is started ");
    QByteArray buffer;
//    buffer.resize(200);
    buffer = m_serialPort->f_ReceiveData();
    int k = buffer.size();
    qDebug("Receiver data: %d \n",k);
    m_gpgwidget->f_appendData(buffer);
//    qDebug("Receiver data \n");
}

void MainWindow1::s_chose_color()
{

}
void MainWindow1::s_chose_pen()
{

}
void MainWindow1::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

}

void MainWindow1::f_initElement()
{
    m_mapcanvas = new mapcanvas;
    m_gpgwidget = new CGPSlogWidget;
    m_serialPort = new CSerialPort;

    m_RxTimer = new QTimer(this);
    connect(m_RxTimer,SIGNAL(timeout()),this,SLOT(s_gpsReceive()));
    m_RxTimer->start(500);


}
void MainWindow1::f_create_mapcanvas()
{

}

void MainWindow1::f_GPSRecv()
{

}

void MainWindow1::f_GPSRecvStop()
{

}

void MainWindow1::f_drawTrack()
{

}
