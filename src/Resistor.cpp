#include <Resistor.hpp>
#include <QtGui/QPainter>


void Resistor::paint(QPainter* painter, const QStyleOptionGraphicsItem* options, QWidget* widget) {
    Symbol::paint(painter, options, widget);

    painter->drawRect(-10, -10, 20, 20);
}
