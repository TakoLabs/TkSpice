#ifndef PIN_HPP
#define PIN_HPP

#include <SchematicEditor/SymbolItem.hpp>

class Pin : public SymbolItem
{
public:
    Pin(QGraphicsItem* parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;
};

#endif // PIN_HPP
