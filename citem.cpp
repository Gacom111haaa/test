#include "citem.h"

CItem::CItem(QgsMapCanvas *mapcanvas):QgsVertexMarker(mapcanvas)
{
   // boundingRect();
    //parent_canvas = mapCanvas;

}

QRectF CItem::boundingRect() const
{
    QRectF r1(100, 200, 20, 20);
    return r1;
}
void CItem::paint(QPainter *painter)
{
    painter->drawLine(0,0,10,10);
}
