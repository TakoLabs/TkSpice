#include <Symbol.hpp>
#include <QtGui/QPainter>
#include <QtCore/QDebug>

Symbol::Symbol()
{
    this->selected = false;
}


void Symbol::setSelected(bool sel) {
    this->selected = sel;

    update(); // To redraw the component
}

bool Symbol::isSelected() const {
    return this->selected;
}


QRectF Symbol::boundingRect() const {
    return QRectF(-10, -10, 20, 20);
}


void Symbol::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) {
    if(this->selected)
        painter->setPen(Qt::red);
    else
        painter->setPen(Qt::black);
}
