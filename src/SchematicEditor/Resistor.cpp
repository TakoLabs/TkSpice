#include <SchematicEditor/Resistor.hpp>
#include <QtGui/QPainter>
#include <SchematicEditor/Pin.hpp>


Resistor::Resistor(QGraphicsItem* parent) :
    SymbolItem(parent)
{
    this->pin1 = new Pin(this);
    this->pin2 = new Pin(this);

    this->pin1->setPos(30, 0);
    this->pin2->setPos(-30, 0);
}

QRectF Resistor::boundingRect() const {
    return QRectF(-20, -10, 40, 20);
}

void Resistor::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) {
    painter->drawRect(-20, -10, 40, 20);
    painter->drawLine(-20, 0, -30, 0);
    painter->drawLine(20, 0, 30, 0);
}
