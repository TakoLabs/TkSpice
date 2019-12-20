#ifndef PIN_HPP
#define PIN_HPP

#include <SchematicEditor/SymbolItem.hpp>

class Pin : public QObject, public SymbolItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    Pin(QGraphicsItem* parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant& value) override;

signals:
    void onItemMove(QPointF new_pos);
};

#endif // PIN_HPP
