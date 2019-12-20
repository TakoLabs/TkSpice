#include <SchematicEditor/SymbolItem.hpp>
#include <SchematicEditor/SchematicScene.hpp>
#include <QApplication>
#include <QtCore/QDebug>

SymbolItem::SymbolItem(QGraphicsItem* parent) :
    QGraphicsItem(parent)
{
    setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemSendsGeometryChanges | QGraphicsItem::ItemSendsScenePositionChanges);
}

QVariant SymbolItem::itemChange(GraphicsItemChange change, const QVariant& value) {
    if(change == ItemPositionChange && scene()) {
        QPointF new_pos {value.toPointF()};

        if(QApplication::mouseButtons() == Qt::LeftButton){
            SchematicScene* customScene {qobject_cast<SchematicScene*> (scene())};
            int gridSize {customScene->getGridSize()};
            qreal xV {qRound(new_pos.x()/gridSize)*gridSize};
            qreal yV {qRound(new_pos.y()/gridSize)*gridSize};

            scene()->update();
            return QPointF(xV, yV);
        }
        else
            return new_pos;
    }

    return QGraphicsItem::itemChange(change, value);
}
