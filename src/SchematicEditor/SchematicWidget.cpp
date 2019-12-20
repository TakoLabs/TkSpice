#include <SchematicEditor/SchematicWidget.hpp>
#include <SchematicEditor/SchematicScene.hpp>
#include <SchematicEditor/Resistor.hpp>
#include <SchematicEditor/Voltage.hpp>
#include <QtGui/QWheelEvent>
#include <QtWidgets/QScrollBar>
#include <QtCore/QtMath>
#include <QtCore/QDebug>

SchematicWidget::SchematicWidget(QWidget* parent) :
    QGraphicsView(parent)
{
    this->scene = new SchematicScene(this);
    this->scene->setSceneRect(-4096, -4096, 8192, 8192);

    setScene(this->scene);
    setMouseTracking(true);
}

void SchematicWidget::addResistor() {
    auto* res = new Resistor;
    this->scene->addItem(res);
    this->scene->update();
}

void SchematicWidget::addVoltage() {
    auto* vol = new Voltage;
    this->scene->addItem(vol);
    this->scene->update();
}

void SchematicWidget::wheelEvent(QWheelEvent* event) {
    const QPointF p0scene {mapToScene(event->pos())};

    qreal factor {qPow(1.2, event->delta() / 240.0)};
    scale(factor, factor);

    const QPointF p1mouse {mapFromScene(p0scene)};
    const QPointF move {p1mouse - event->pos()}; // The move
    horizontalScrollBar()->setValue(move.x() + horizontalScrollBar()->value());
    verticalScrollBar()->setValue(move.y() + verticalScrollBar()->value());
}
