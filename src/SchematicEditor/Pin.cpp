#include <SchematicEditor/Pin.hpp>
#include <QtGui/QPainter>

Pin::Pin(QGraphicsItem* parent) :
    SymbolItem(parent)
{
    setFlags(QGraphicsItem::ItemSendsGeometryChanges);
}

QRectF Pin::boundingRect() const {
    return QRectF(-1.5, -1.5, 3, 3);
}

void Pin::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) {
    painter->setBrush(Qt::black);
    painter->drawEllipse(QPointF(0,0), 3, 3);
}
