#include <SchematicEditor/Line.hpp>
#include <SchematicEditor/Pin.hpp>
#include <SchematicEditor/SchematicScene.hpp>
#include <QtGui/QPainter>
#include <QtCore/QDebug>

Line::Line(QGraphicsItem* parent) :
    SymbolItem(parent)
{
    setFlags(QGraphicsItem::ItemSendsGeometryChanges);

    this->begin = QPointF(0, 0);
    this->end = QPointF(0, 0);
}

void Line::setBegin(QPointF pos) {
    SchematicScene* customScene = qobject_cast<SchematicScene*> (scene());
    int gridSize = customScene->getGridSize();
    qreal xV = qRound(pos.x()/gridSize)*gridSize;
    qreal yV = qRound(pos.y()/gridSize)*gridSize;

    this->begin = QPointF(xV, yV);

    auto items = scene()->items(pos);
    for(auto item : items) {
        auto pin = dynamic_cast<Pin*>(item);
        if(pin != nullptr) {
            this->pin1 = pin;
            QObject::connect(this->pin1, &Pin::onItemMove, this, &Line::onPin1Move);
            break;
        }
    }

    scene()->update();
}

void Line::setEnd(QPointF pos) {
    SchematicScene* customScene = qobject_cast<SchematicScene*> (scene());
    int gridSize = customScene->getGridSize();
    qreal xV = qRound(pos.x()/gridSize)*gridSize;
    qreal yV = qRound(pos.y()/gridSize)*gridSize;

    this->end = QPointF(xV, yV);

    auto items = scene()->items(pos);
    for(auto item : items) {
        auto pin {dynamic_cast<Pin*>(item)};
        if(pin != nullptr) {
            this->pin2 = pin;
            QObject::connect(this->pin2, &Pin::onItemMove, this, &Line::onPin2Move);
            break;
        }
    }

    scene()->update();
}


QRectF Line::boundingRect() const {
    return QRectF(0, 0, 0, 0);
}

void Line::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) {
    painter->drawLine(this->begin, this->end);
}

void Line::onPin1Move(QPointF new_pos) {
    qDebug() << "New Pos: " << new_pos;
    setBegin(new_pos);
}

void Line::onPin2Move(QPointF new_pos) {
    setEnd(new_pos);
}

