#ifndef CITEM_H
#define CITEM_H
#include "QRectF"
#include "QPainter"
#include "qgsvertexmarker.h"

class CItem : public QgsVertexMarker
{
public:
    CItem(QgsMapCanvas *mapcanvas);
    QRectF boundingRect () const;
    void paint(QPainter *painter);
    QgsMapCanvas *parent_canvas;
};

#endif // CITEM_H
