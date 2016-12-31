#include "mapcanvas.h"

mapcanvas::mapcanvas(QWidget *parent) : QWidget(parent)
{

    m_layout = new QVBoxLayout;

    QString myPluginsDir        = "/usr/lib/qgis/plugins";
    QgsProviderRegistry * preg = QgsProviderRegistry::instance(myPluginsDir);

    m_mapCanvas = new QgsMapCanvas(0,0);
    m_mapCanvas->enableAntiAliasing(true);
    m_mapCanvas->setCanvasColor(QColor(255, 255, 255));
    m_mapCanvas->freeze(false);

    f_addlayer("CoastLines");
    f_addlayer("mainroad");
    f_addlayer("waterline");
    f_addlayer("ranhgioi");

    // Set the Map Canvas Layer Set
    m_mapCanvas->setLayerSet(m_layerSet);
    m_mapCanvas->setVisible(true);
    m_mapCanvas->refresh();

//    m_layout->addWidget(m_mapCanvas);
    m_layout->addWidget(m_mapCanvas);
    setLayout(m_layout);
    //----------------------- connects

    f_createMapTools();
    connect(m_actionPan,SIGNAL(triggered(bool)),this,SLOT(sl_pan()));
    connect(m_actionZoomIn,SIGNAL(triggered(bool)),this,SLOT(sl_zoomIn()));
    connect(m_actionZoomOut,SIGNAL(triggered(bool)),this,SLOT(sl_zoomOut()));

}

void mapcanvas::f_addlayer(QString layername)
{
    QString layer_path         = dir->currentPath()+ "/data/"+layername+".shp";
    //QString layer_name = name;

    QgsVectorLayer *layer =  new QgsVectorLayer(layer_path, layername, "ogr");

    QgsSingleSymbolRendererV2 *render = new QgsSingleSymbolRendererV2(QgsSymbolV2::defaultSymbol(layer->geometryType()));
    /*
    // set color for layer
    QgsSymbolV2List list_symbol;
    list_symbol = render->symbols();
    QgsSymbolV2 *symbol;
    symbol = render->symbol();
    symbol->setColor(QColor::fromRgb(255,0,0));
    */
    layer->setRendererV2(render);
    if (layer->isValid())
    {
        qDebug("Layer is valid");
    }
    else
    {
        qDebug("Layer is NOT valid");
    }

    // Add the Vector Layer to the Layer Registry
    QgsMapLayerRegistry::instance()->addMapLayer(layer, TRUE);
    // Add the Layer to the Layer Set
    m_layerSet.append(QgsMapCanvasLayer(layer, TRUE));
    m_mapCanvas->setExtent(layer->extent());
    //m_mapCanvas->setLayerSet(myLayerSet);
    //m_mapCanvas->setVisible(true);
    //m_mapCanvas->refresh();
}

void mapcanvas::f_showlayer(QString layername)
{

}

void mapcanvas::f_hidelayer(QString layername)
{

}

void mapcanvas::f_createMapTools()
{
    //------------- create actions for maptool
    m_actionPan = new QAction("Pan",this);
    m_actionZoomIn = new QAction("Zoom in",this);
    m_actionZoomOut = new QAction("Zoom out",this);

    m_PanTool = new QgsMapToolPan(m_mapCanvas);
    m_PanTool->setAction(m_actionPan);

    m_ZoomInTool = new QgsMapToolZoom(m_mapCanvas,false);
    m_ZoomInTool->setAction(m_actionZoomIn);

    m_ZoomOutTool = new QgsMapToolZoom(m_mapCanvas,true);
    m_ZoomOutTool->setAction(m_actionZoomOut);

}

void mapcanvas::sl_zoomIn()
{
    m_mapCanvas->setMapTool(m_ZoomInTool);
}

void mapcanvas::sl_zoomOut()
{
    m_mapCanvas->setMapTool(m_ZoomOutTool);

}

void mapcanvas::sl_pan()
{
    m_mapCanvas->setMapTool(m_PanTool);

}

void mapcanvas::sl_select()
{

}

