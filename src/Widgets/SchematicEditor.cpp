#include <Widgets/SchematicEditor.hpp>
#include <Resistor.hpp>
#include <QtGui/QWheelEvent>
#include <QtGui/QMouseEvent>
#include <QtGui/QKeyEvent>
#include <QtWidgets/QScrollBar>
#include <QtCore/QDebug>

SchematicEditor::SchematicEditor(QWidget* parent) :
    QGraphicsView(parent)
{
    this->scene = new QGraphicsScene(this);
    this->scene->setSceneRect(-4096, -4096, 8192, 8192);

    this->zoomFactor = 1;
    this->selecting = false;


    this->state = SchematicEditor::Nothing;
    this->tool = SchematicEditor::Select;



    this->scene->addLine(-4096, 0, 4096, 0);
    this->scene->addLine(0, -4096, 0, 4096);



    setMouseTracking(true);

    setScene(this->scene);
}


void SchematicEditor::zoomIn() {
    double factor { 1.25 };
    setTransformationAnchor(AnchorUnderMouse);

    if ((matrix().m11() * factor) > 2)
        factor = 2 / matrix().m11();

    QMatrix	old_matrix = matrix();

    scale(factor, factor);

    QRect	viewport_rect = viewport()->rect();
    QRectF	new_visible_rect = QRectF(mapToScene(viewport_rect.topLeft()), mapToScene(viewport_rect.bottomRight()));


    this->zoomFactor *= factor;

    emit zoomChanged(this->zoomFactor);
}

void SchematicEditor::zoomOut() {
    double factor { 0.8 };
    setTransformationAnchor(AnchorUnderMouse);

    scale(factor, factor);
    this->zoomFactor *= factor;
    emit zoomChanged(this->zoomFactor);
}


void SchematicEditor::moveView(const QPoint& pos) {
    horizontalScrollBar()->setValue(pos.x());
    verticalScrollBar()->setValue(pos.y());
}


void SchematicEditor::addComponent(uint compID) {
    this->tool = SchematicEditor::Place;

    Resistor* res { new Resistor() };
    res->setVisible(true);
    res->setSelected(true);

    this->scene->addItem(res);
    this->movingComponents.erase(this->movingComponents.begin(), this->movingComponents.end());
    this->movingComponents.append(res);
}

void SchematicEditor::moveComponent(Symbol* component, const QPoint& pos) {
    component->setPos(pos);
}


void SchematicEditor::wheelEvent(QWheelEvent* event) {
    QGraphicsView::wheelEvent(event);

    if(event->delta() < 0)
        zoomIn();
    else
        zoomOut();
}

void SchematicEditor::mousePressEvent(QMouseEvent* event) {
    QGraphicsView::mousePressEvent(event);

    auto sceneCoord { toSceneCoord(event->pos()) };

    if(event->button() == Qt::MidButton) {
        this->state.setFlag(MovingView);

        this->lastMousePos = event->pos();
        this->lastHScrollBarPos = horizontalScrollBar()->value();
        this->lastVScrollBarPos = verticalScrollBar()->value();
    }

    if(event->button() == Qt::LeftButton) {
        switch(this->tool) {
            case SchematicEditor::Select: {
                auto component { dynamic_cast<Symbol*>(this->itemAt(event->pos())) };

                if(component == nullptr) {
                    clearSelectedComponents();
                    qDebug() << "No items";
                    break;
                }

                qDebug() << "items";

                if(!this->selectedComponents.contains(component))
                    clearSelectedComponents();


                appendSelectedComponent(component);
                this->movingComponents.append(component);

                break;
            }

            case SchematicEditor::Place: {
                for(Symbol* component : this->movingComponents) {
                    component->setSelected(false);
                }

                this->movingComponents.erase(this->movingComponents.begin(), this->movingComponents.end());
                this->tool = SchematicEditor::Select;

                break;
            }
        }
    }
}

void SchematicEditor::mouseReleaseEvent(QMouseEvent* event) {
    QGraphicsView::mouseReleaseEvent(event);

    auto sceneCoord { toSceneCoord(event->pos()) };

    if(event->button() == Qt::MidButton)
        this->state.setFlag(MovingView, false);

    if(event->button() == Qt::LeftButton) {
        switch(this->tool) {
            case SchematicEditor::Select: {
                break;
            }
        }
    }
}

void SchematicEditor::mouseMoveEvent(QMouseEvent* event) {
    QGraphicsView::mouseMoveEvent(event);

    auto sceneCoord { toSceneCoord(event->pos()) };

    emit mouseMoved(sceneCoord);

    if(this->state.testFlag(MovingView)) {
        auto delta { event->pos() - this->lastMousePos };
        QPoint translation { this->lastHScrollBarPos - delta.x(), this->lastVScrollBarPos - delta.y() };
        moveView(translation);
    }

    switch(this->tool) {
        case SchematicEditor::Place: {
            for(Symbol* component : this->movingComponents)
                moveComponent(component, mapToScene(event->pos()).toPoint());

            break;
        }
    }
}

void SchematicEditor::keyPressEvent(QKeyEvent* event) {
    if(event->key() == Qt::Key_Left) {
        move(QPoint(-10, 0));
        qDebug() << "Left";

    } else if(event->key() == Qt::Key_Right) {
        move(QPoint(10, 0));

    } else if(event->key() == Qt::Key_Up) {
        move(QPoint(0, 10));

    } else if(event->key() == Qt::Key_Down) {
        move(QPoint(0, -10));

    }
}


QPoint SchematicEditor::toSceneCoord(const QPoint& pos) const {
    QPoint sceneCoord { mapToScene(pos).toPoint() };
    sceneCoord.setY(sceneCoord.y() * -1);

    return sceneCoord;
}

void SchematicEditor::appendSelectedComponent(Symbol* component) {
    component->setSelected(true);
    this->selectedComponents.append(component);
}

void SchematicEditor::removeSelectedComponent(Symbol* component) {
    component->setSelected(false);

    this->selectedComponents.removeOne(component);
}

void SchematicEditor::clearSelectedComponents() {
    for(Symbol* component : this->selectedComponents)
        component->setSelected(false);

    this->selectedComponents.erase(this->selectedComponents.begin(), this->selectedComponents.end());
}
