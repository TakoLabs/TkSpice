#ifndef VOLTAGE_HPP
#define VOLTAGE_HPP

#include <SchematicEditor/SymbolItem.hpp>

class Pin;

class Voltage: public SymbolItem
{
public:
    Voltage(QGraphicsItem* parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;

private:
    Pin* pin1;
    Pin* pin2;
};

#endif // VOLTAGE_HPP
