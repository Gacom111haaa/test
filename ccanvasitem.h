#ifndef CCANVASITEM_H
#define CCANVASITEM_H
#include "qgsmapcanvasitem.h"
#include "qgsmapcanvas.h"


class CCanvasItem : public QgsMapCanvasItem
{
public:
    CCanvasItem();
    QgsMapCanvas *parent_canvas;

};

#endif // CCANVASITEM_H
