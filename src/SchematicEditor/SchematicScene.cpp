#include <SchematicEditor/SchematicScene.hpp>
#include <SchematicEditor/Line.hpp>
#include <SchematicEditor/SchematicWidget.hpp>
#include <QtWidgets/QGraphicsSceneMouseEvent>
#include <QtGui/QPainter>
#include <QtCore/QDebug>

SchematicScene::SchematicScene(QObject* parent) :
    QGraphicsScene(parent),
    grid_size(10),
    drawLine(false)
{

}

int SchematicScene::getGridSize() const {
    return this->grid_size;
}

void SchematicScene::setGridSize(int size) {
    this->grid_size = size;
}

void SchematicScene::drawBackground(QPainter* painter, const QRectF& rect) {
    QGraphicsScene::drawBackground(painter, rect);

    QPen pen;
    pen.setCosmetic(true);
    pen.setColor(Qt::darkGray);
    painter->setPen(pen);

    int left {static_cast<int>(static_cast<int>(rect.left()) - (static_cast<int>(rect.left()) % this->grid_size))};
    int top {static_cast<int>(rect.top()) - (static_cast<int>(rect.top()) % this->grid_size)};

    QVector<QPointF> points, bold_points;
    for(int x{left}; x < rect.right(); x += this->grid_size)
        for(int y{top}; y < rect.bottom(); y += this->grid_size) {
            if(x%100 == 0 || y%100 == 0)
                bold_points.append(QPointF(x,y));
            else
                points.append(QPointF(x,y));
        }

    /*for(int x{left}; x < rect.right(); x += this->grid_size)
        bold_points.append(QPointF(x,0));
    for(int y{top}; y < rect.bottom(); y += this->grid_size)
        bold_points.append(QPointF(0,y));*/

    painter->drawPoints(points.data(), points.size());
    pen.setWidth(pen.width() + 1);
    painter->setPen(pen);
    painter->drawPoints(bold_points.data(), bold_points.size());
}

void SchematicScene::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    QGraphicsScene::mousePressEvent(event);

    if(event->button() == Qt::RightButton) {
        // Draw Line
        if(this->drawLine) {
            this->drawLine = false;
            this->current_line = nullptr;
        } else {
            this->drawLine = true;
            this->current_line = new Line;
            this->addItem(this->current_line);

            auto pos {event->scenePos()};
            qreal xV = round(pos.x()/this->grid_size)*this->grid_size;
            qreal yV = round(pos.y()/this->grid_size)*this->grid_size;

            this->current_line->setPos(xV, yV);
        }
    }
}

void SchematicScene::mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {
    QGraphicsScene::mouseReleaseEvent(event);

}

void SchematicScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {
    QGraphicsScene::mouseReleaseEvent(event);
    qDebug() << "Ti";

    // Draw Line
    if(this->drawLine) {
        auto end {event->scenePos() - this->current_line->pos()};
        this->current_line->setEnd(end);
    }
}
