#ifndef MAP_H
#define MAP_H

#include "citem.h"
#include <QGraphicsScene>
#include <QGraphicsView>

#include <QWidget>
#include <QMainWindow>
#include "QHBoxLayout"
#include "QLineEdit"
#include "QAbstractButton"
#include "QPushButton"
#include "QAction"
#include "QToolBar"

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

class map : public QMainWindow
{
    Q_OBJECT
private:

    QgsMapCanvas *canvas;
    QgsVectorLayer *layer_ranhgioi;
    QgsVectorLayer *layer_CoastLines;
    QLineEdit *lat_long;
    QLineEdit *x_pixel;
    QLineEdit *y_pixel;

public:
    explicit map(QWidget *parent = 0);

signals:

public slots:
    void get_coordiante(QgsPoint p);
    void zoomInMode();
    void zoomOutMode();
    void panMode();
    void pointMode();
    void IdentifyMode();
    void addlayer(QString name);
private:
    QgsMapCanvas * mypMapCanvas;
         QVBoxLayout  * mpLayout;
         QToolBar * mpMapToolBar;
         QgsMapTool * mpPanTool;
         QgsMapTool * mpZoomInTool;
    QgsMapTool * mpZoomOutTool;
    QgsMapTool * mpEmitPoint;
    QgsMapTool * mpIdentify;
    QList <QgsMapCanvasLayer> myLayerSet;
    QDir *dir;
};

#endif // MAP_H
