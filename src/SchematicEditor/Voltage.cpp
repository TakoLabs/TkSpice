#include <SchematicEditor/Voltage.hpp>
#include <SchematicEditor/Pin.hpp>
#include <QtGui/QPainter>

Voltage::Voltage(QGraphicsItem* parent) :
    SymbolItem(parent)
{
    this->pin1 = new Pin(this);
    this->pin2 = new Pin(this);

    this->pin1->setPos(0, 30);
    this->pin2->setPos(0, -30);
}

QRectF Voltage::boundingRect() const {
    return QRectF(-10, -10, 40, 40);
}

void Voltage::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) {
    painter->drawEllipse(QPointF(0, 0), 20, 20);

    // Pins
    painter->drawLine(0, -20, 0, -30);
    painter->drawLine(0, 20, 0, 30);

    // Arrow
    painter->drawLine(0, -12, 0, 12);
    painter->drawLine(4, -5, 0, -12);
    painter->drawLine(-4, -5, 0, -12);
}
