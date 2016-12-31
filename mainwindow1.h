#ifndef MAINWINDOW1_H
#define MAINWINDOW1_H
// include qgis
#include "qgis/qgsmapcanvas.h"
#include "qgis/qgsvectorlayer.h"
#include "qgis/qgsproviderregistry.h"
#include "qgis/qgsmaplayerregistry.h"
#include "qgis/qgssinglesymbolrendererv2.h"

#include "qgis/qgsmaptoolpan.h"
#include "qgis/qgsmaptoolzoom.h"

#include "qgis/qgslabel.h"
#include "qgis/qgslabelattributes.h"
#include "qgis/qgsfield.h"
#include "qgis/qgspallabeling.h"
#include "qgis/qgscomposershape.h"
#include "qgis/qgscomposition.h"
#include "qgis/qgsannotationitem.h"
#include "qgis/qgslinesymbollayerv2.h"
#include "qgis/qgsmarkersymbollayerv2.h"
#include "qgis/qgsvectordataprovider.h"
#include "qgis/qgsfeature.h"
#include "qgis/qgsgeometry.h"
#include "qgis/qgsmapcanvasitem.h"
#include "qgis/qgsrectangle.h"
#include "qgis/qgslinesymbollayerv2.h"
#include "qgis/qgsvertexmarker.h"
#include "qgis/qgscategorizedsymbolrendererv2.h"
#include "qgsdialog.h"
#include "qgsmaptoolzoom.h"
#include "qtoolbar.h"
#include "qgsmaptoolemitpoint.h"
#include "qgsmaptoolidentify.h"
// include qt
#include "QString"
#include <QMainWindow>
#include "mapcanvas.h"
#include "cserialport.h"
#include "QTimer"
#include "QByteArray"
#include "cgpslogwidget.h"
namespace Ui {
class MainWindow1;
class CGPSlog;
}

class MainWindow1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow1(QWidget *parent = 0);
    ~MainWindow1();


protected:
    void paintEvent(QPaintEvent *event);
private:
    Ui::MainWindow1 *ui;
    CGPSlogWidget *m_gpgwidget;
    //---------------------------------- serial reader
    QTimer *m_RxTimer;
    CSerialPort *m_serialPort;
    //---------------------------- centre widget of window


    mapcanvas *m_mapcanvas;

    //----------------------------- file actions
    QAction *action_file_new;
    QAction *action_file_close;
    QAction *action_file_open;
    QAction *action_file_save;
    //------------------------------ tools action
    QAction *action_tool_GPS;
    //------------------------------ draw tool actions
    QAction *action_draw_line;
    QAction *action_draw_circle;
    QAction *action_draw_rectangle;
    QAction *action_chose_pen;
    QAction *action_chose_color;
    //------------------------------ map tool actions
    QAction *action_select_mode;
    QAction *action_pan_mode;
    QAction *action_zoomIn_mode;
    QAction *action_zoomOut_mode;
    //------------------------------- menu bar + tools bar
    QMenu *menu_bar;
    QMenu *menu_tools;
    QToolBar *tool_bar_draw;
    QToolBar *tool_bar_map;
    QStatusBar *status_bar;
    //--------------------------------- functions
    void f_initElement();
    void f_create_menus();
    void f_create_actions();
    void f_create_tools_bar();
    void f_create_status_bar();
    void f_create_mapcanvas();
    void f_GPSRecv();
    void f_GPSRecvStop();
    void f_drawTrack();

private slots:
    void s_file_open();
    void s_file_save();
    void s_file_close();
    void s_file_new();

    void s_tool_gps();
    void s_draw_line();
    void s_draw_circle();
    void s_draw_rectangle();

    void s_chose_pen();
    void s_chose_color();

    void s_map_panMode();
    void s_map_zoomInMode();
    void s_map_zoomOutMode();
    void s_map_selectMode();

    void s_gpsReceive();
};

#endif // MAINWINDOW1_H
