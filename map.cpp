#include "map.h"

map::map(QWidget *parent) : QMainWindow(parent)
{

    QWidget *widget_map;
    widget_map = new QWidget;

    QHBoxLayout *layout;
    layout = new QHBoxLayout;


    QString myPluginsDir        = "/usr/lib/qgis/plugins";
    QgsProviderRegistry * preg = QgsProviderRegistry::instance(myPluginsDir);
    mypMapCanvas = new QgsMapCanvas(0, 0);
    //--------------------------------- add new layer
    addlayer("CoastLines");
    //addlayer("district");
    //addlayer("borderline");
    addlayer("mainroad");
    addlayer("waterline");
    addlayer("ranhgioi");


    /*
    QString myLayerBaseName     = "vietnam";
    QString myProviderName      = "ogr";
    QString myLayerPath         = dir->currentPath()+ "/data/ranhgioi.shp";



    QgsVectorLayer * mypLayer =  new QgsVectorLayer(myLayerPath, myLayerBaseName, myProviderName);

    QgsSingleSymbolRendererV2 *mypRenderer = new QgsSingleSymbolRendererV2(QgsSymbolV2::defaultSymbol(mypLayer->geometryType()));

    // set color for layer
    QgsSymbolV2List list_symbol;
    list_symbol = mypRenderer->symbols();
    QgsSymbolV2 *symbol;
    symbol = mypRenderer->symbol();
    symbol->setColor(QColor::fromRgb(255,0,0));    

    mypLayer->setRendererV2(mypRenderer);
    if (mypLayer->isValid())
    {
        qDebug("Layer is valid");
    }
    else
    {
        qDebug("Layer is NOT valid");
    }

    // Add the Vector Layer to the Layer Registry
    QgsMapLayerRegistry::instance()->addMapLayer(mypLayer, TRUE);
    // Add the Layer to the Layer Set
    myLayerSet.append(QgsMapCanvasLayer(mypLayer, TRUE));
    */
    // Create the Map Canvas


    //------------------------------------------------------------------------------labels-OKE
    /*
    QgsPalLayerSettings label;
    //label = QgsPalLayerSettings();
    label.readFromLayer(mypLayer);
    label.enabled= true;
    label.fieldName = "hello";
    label.placement = QgsPalLayerSettings::AroundPoint;
    label.setDataDefinedProperty(QgsPalLayerSettings::Size,true,true,"8","vnvn");

    //label.setDataDefinedProperty(QgsPalLayerSettings.Size,True,True,’8′,”);
    label.writeToLayer(mypLayer);

    //mypLayer->enableLabels(true);
    */
    //--------------------------------------------------------------


    layout->addWidget(mypMapCanvas);
    //setLayout(layout);
    widget_map->setLayout(layout);
    widget_map->setParent(this);
    widget_map->setGeometry(50,0,1300,700);
    //------------------------------------------------------------

    lat_long = new QLineEdit();
    lat_long->setParent(this);
    lat_long->setGeometry(100,700,250,30);
    //lat_long->show();

    //-------------------------------------------------------------

    x_pixel = new QLineEdit();
    x_pixel->setParent(this);
    x_pixel->setGeometry(350,700,100,30);

    y_pixel = new QLineEdit();
    y_pixel->setParent(this);
    y_pixel->setGeometry(450,700,100,30);


    connect(mypMapCanvas,SIGNAL(xyCoordinates(QgsPoint)),this,SLOT(get_coordiante(QgsPoint)));
    //connect(mypMapCanvas,SIGNAL(xyCoordinates(QgsPoint)),this,Slot
    //------------------------------------------------------------


    //create image

    QImage *img;
    img  = new QImage(QSize(800, 600),QImage::Format_ARGB32_Premultiplied);
    //QImage *img = new QImage(QSize(600,800),QImage.Format_ARGB32_Premultiplied)
    QColor *color = new QColor(255, 0, 255);
    img->fill(color->rgb());

    //create painter
    QPainter *p = new  QPainter();
    p->begin(img);
    p->setRenderHint(QPainter::Antialiasing);

    QgsMapRenderer *render = new QgsMapRenderer();

    QStringList *layer;
    //layer =
    layer = new QStringList;
    layer->append("vietnam");
    render->setLayerSet(*layer);

    QgsRectangle *rect = new QgsRectangle(render->fullExtent());
    rect->scale(1.1);
    render->setExtent(*rect);
    //set output size
    render->setOutputSize(img->size(), img->logicalDpiX());
    render->render(p);
    p->end();
    img->save("render.png","png");

    //---------------------------------------------------------------
    /*
    QGraphicsScene *s = mypMapCanvas->scene();
    s->addRect(10,10,50,200);
    */
    //---------------------------------------------------------------

    //------------------------create new feature and add to vector layer oke with diadiem.shp
    /*
    QgsFields fields;
    fields = mypLayer->pendingFields();
    QgsFeature feat;
    feat = QgsFeature(mypLayer->pendingFields());
    feat.setAttribute(0,150);
    feat.setAttribute(1,150);
    feat.setAttribute(2,"phan");
    feat.setGeometry(QgsGeometry::fromPoint(QgsPoint(124, 456)));
    QgsFeatureList feat_list;
    feat_list.append(feat);
    mypLayer->dataProvider()->addFeatures(feat_list);
    */
    //------------------------------------------- create new memory layer OKE
    /*
    QgsVectorLayer *memory_layer = new QgsVectorLayer("Polygon","pointbuffer","memory");
    QgsFeature feature;
    feature.setGeometry(QgsGeometry::fromPoint(QgsPoint(105,23))->buffer(1,0));
   // QgsProviderRegistry

    QgsFeatureList feature_list;
    feature_list.append(feature);
    QgsVectorDataProvider *provider;
    provider= memory_layer->dataProvider();


    memory_layer->startEditing();
    provider->addFeatures(feature_list);
    memory_layer->commitChanges();



     QgsMapLayerRegistry::instance()->addMapLayer(memory_layer, TRUE);
     myLayerSet.append(QgsMapCanvasLayer(memory_layer, TRUE));
     */
    //-----------------------------------------------
    //---------------------------------------------- create QgsSvgMarkerSymbolLayerV2 Oke
    QString layer_path         = dir->currentPath()+ "/data/diadiem.shp";
    QString layer_name     = "airports"; //图层名称;
    QString path_svg         = dir->currentPath()+ "/data/face.svg";
    QgsVectorLayer* veclayer = new QgsVectorLayer( layer_path, layer_name, "ogr", false );

    QgsSvgMarkerSymbolLayerV2 *svgMarker = new QgsSvgMarkerSymbolLayerV2();
    svgMarker->setPath(path_svg);
    QgsSymbolLayerV2List symList;
    symList.append( svgMarker );
    QgsMarkerSymbolV2* markSym = new QgsMarkerSymbolV2( symList );
    QgsSingleSymbolRendererV2* symRenderer = new QgsSingleSymbolRendererV2( markSym );
    svgMarker->setSize( 10 );
    veclayer->setRendererV2( symRenderer );

    QgsMapLayerRegistry::instance()->addMapLayer(veclayer, TRUE);
    // Add the Layer to the Layer Set
    myLayerSet.append(QgsMapCanvasLayer(veclayer, TRUE));


    //---------------------------------------------- create virtual vector layer and add feature
    QgsVectorLayer *vector_layer = new QgsVectorLayer("Point","airport","memory");
    QgsFeature feature1;
    feature1 = QgsFeature(vector_layer->pendingFields());
    feature1.setGeometry(QgsGeometry::fromPoint(QgsPoint(105,20)));
    QgsFeatureList feature_list;
    feature_list.append(feature1);
    QgsVectorDataProvider *provider;
    provider= vector_layer->dataProvider();

    vector_layer->startEditing();
    provider->addFeatures(feature_list);
    vector_layer->commitChanges();

    QString path_svg1         = dir->currentPath()+ "/data/sign.svg";
    QgsSvgMarkerSymbolLayerV2 *svgMarker1 = new QgsSvgMarkerSymbolLayerV2();
    svgMarker1->setPath(path_svg1);
    QgsSymbolLayerV2List symList1;
    symList1.append( svgMarker1 );
    QgsMarkerSymbolV2* markSym1 = new QgsMarkerSymbolV2( symList1 );
    QgsSingleSymbolRendererV2* symRenderer1 = new QgsSingleSymbolRendererV2( markSym1 );
    svgMarker1->setSize( 10 );
    vector_layer->setRendererV2( symRenderer1 );


    QgsMapLayerRegistry::instance()->addMapLayer(vector_layer, TRUE);
    myLayerSet.append(QgsMapCanvasLayer(vector_layer, TRUE));
    //------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------qgis maptools

    mpMapToolBar = addToolBar("Tool bar");

    mpMapToolBar->setParent(this);
    mpMapToolBar->show();
    //-----------------------------------action
    QAction *mpActionPan = mpMapToolBar->addAction("Pan");
    QAction *mpActionZoomIn = mpMapToolBar->addAction("Zoom in");
    QAction *mpActionZoomout = mpMapToolBar->addAction("Zoom out");
    QAction *mpActionEmitPoint = mpMapToolBar->addAction("Sellect");
    QAction *mpActionIdentify = mpMapToolBar->addAction("Identify");

    mpMapToolBar->addSeparator();

    mpPanTool = new QgsMapToolPan(mypMapCanvas);
    mpPanTool->setAction(mpActionPan);

    mpZoomInTool = new QgsMapToolZoom(mypMapCanvas, FALSE);
    mpZoomInTool->setAction(mpActionZoomIn);

    mpZoomOutTool = new QgsMapToolZoom(mypMapCanvas, TRUE );
    mpZoomOutTool->setAction(mpActionZoomout);

    mpEmitPoint = new QgsMapToolEmitPoint(mypMapCanvas);
    mpEmitPoint->setAction(mpActionEmitPoint);

    mpIdentify = new QgsMapToolIdentify(mypMapCanvas);
    mpIdentify->setAction(mpActionIdentify);


    //connect actions
    connect(mpActionPan,SIGNAL(triggered(bool)),this,SLOT(panMode()));
    connect(mpActionZoomIn,SIGNAL(triggered(bool)),this,SLOT(zoomInMode()));
    connect(mpActionZoomout,SIGNAL(triggered(bool)),this,SLOT(zoomOutMode()));
    connect(mpActionEmitPoint,SIGNAL(triggered(bool)),this,SLOT(pointMode()));
    connect(mpActionIdentify,SIGNAL(triggered(bool)),this,SLOT(IdentifyMode()));

    //-------------------------------------------------------------------
    /*

     CItem *item;
     item = new CItem(mypMapCanvas);
     QGraphicsScene * scene;
     scene = mypMapCanvas->scene();
     QGraphicsView view(scene);
     scene->addItem(item);
     view.showFullScreen();
     */



    mypMapCanvas->enableAntiAliasing(true);
    mypMapCanvas->setCanvasColor(QColor(255, 255, 255));
    mypMapCanvas->freeze(false);

    // Set the Map Canvas Layer Set
    mypMapCanvas->setLayerSet(myLayerSet);
    mypMapCanvas->setVisible(true);
    mypMapCanvas->refresh();


}
void map::get_coordiante(QgsPoint p)
{
    QString coordinates;
    coordinates = p.toString();
    lat_long->setText(coordinates);
    //p.t
}
//void zoomInMode();
//void zoomOutMode();
//void panMode();
void map::panMode()
{
   mypMapCanvas->setMapTool(mpPanTool);
}
void map::zoomInMode()
{
  mypMapCanvas->setMapTool(mpZoomInTool);
}
void map::zoomOutMode()
{
  mypMapCanvas->setMapTool(mpZoomOutTool);
}
void map::pointMode()
{
    mypMapCanvas->setMapTool(mpEmitPoint);
}
void map::IdentifyMode()
{
    mypMapCanvas->setMapTool(mpIdentify);
}
void map::addlayer(QString name)
{
    QString layer_path         = dir->currentPath()+ "/data/"+name+".shp";
    //QString layer_name = name;

    QgsVectorLayer *layer =  new QgsVectorLayer(layer_path, name, "ogr");

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
    myLayerSet.append(QgsMapCanvasLayer(layer, TRUE));
    mypMapCanvas->setExtent(layer->extent());
    //mypMapCanvas->setLayerSet(myLayerSet);
    //mypMapCanvas->setVisible(true);
    //mypMapCanvas->refresh();
}
