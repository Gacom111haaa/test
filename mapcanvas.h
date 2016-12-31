#ifndef MAPCANVAS_H
#define MAPCANVAS_H

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
#include <QtGui>
#include "QString"
#include "QAction"
class mapcanvas : public QWidget
{
    Q_OBJECT
public:
    explicit mapcanvas(QWidget *parent = 0);
    void f_addlayer(QString layername);
    void f_showlayer(QString layername);
    void f_hidelayer(QString layername);
    void f_createMapTools();

private:
    QgsMapCanvas * m_mapCanvas;
    QVBoxLayout  * m_layout;
//    QToolBar * mpMapToolBar;
    QgsMapTool * m_PanTool;
    QgsMapTool * m_ZoomInTool;
    QgsMapTool * m_ZoomOutTool;
    QgsMapTool * m_selectTool;

    QAction *m_actionPan;
    QAction *m_actionZoomIn;
    QAction *m_actionZoomOut;

    QList <QgsMapCanvasLayer> m_layerSet;
    QDir *dir;

signals:

public slots:
    void sl_zoomIn();
    void sl_zoomOut();
    void sl_pan();
    void sl_select();
};

#endif // MAPCANVAS_H
