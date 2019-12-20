#ifndef RESISTOR_HPP
#define RESISTOR_HPP

#include <SchematicEditor/SymbolItem.hpp>

class Pin;

class Resistor : public SymbolItem
{
public:
    Resistor(QGraphicsItem* parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;

private:
    Pin* pin1;
    Pin* pin2;
};

#endif // RESISTOR_HPP
