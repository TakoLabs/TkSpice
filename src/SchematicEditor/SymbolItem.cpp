#include <SchematicEditor/SymbolItem.hpp>
#include <SchematicEditor/SchematicScene.hpp>
#include <QApplication>

SymbolItem::SymbolItem(QGraphicsItem* parent) :
    QGraphicsItem(parent)
{
    setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemSendsGeometryChanges);
}

QVariant SymbolItem::itemChange(GraphicsItemChange change, const QVariant& value) {
    if(change == ItemPositionChange && scene()) {
            QPointF newPos = value.toPointF();
            if(QApplication::mouseButtons() == Qt::LeftButton){
                SchematicScene* customScene = qobject_cast<SchematicScene*> (scene());
                int gridSize = customScene->getGridSize();
                qreal xV = round(newPos.x()/gridSize)*gridSize;
                qreal yV = round(newPos.y()/gridSize)*gridSize;

                scene()->update();
                return QPointF(xV, yV);
            }
            else
                return newPos;
        }
        else
            return QGraphicsItem::itemChange(change, value);
}
