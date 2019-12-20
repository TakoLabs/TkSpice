#include <SchematicEditor/Pin.hpp>
#include <QtGui/QPainter>
#include <QtCore/QDebug>

Pin::Pin(QGraphicsItem* parent) :
    SymbolItem(parent)
{
    setFlags(QGraphicsItem::ItemSendsGeometryChanges | QGraphicsItem::ItemSendsScenePositionChanges);
}

QRectF Pin::boundingRect() const {
    return QRectF(-1.5, -1.5, 3, 3);
}

void Pin::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) {
    painter->setBrush(Qt::black);
    painter->drawEllipse(QPointF(0,0), 3, 3);
}

QVariant Pin::itemChange(GraphicsItemChange change, const QVariant& value) {

    if(change == ItemScenePositionHasChanged && scene())
        qDebug() << "test 2";

    return SymbolItem::itemChange(change, value);
}
