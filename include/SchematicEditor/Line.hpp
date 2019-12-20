#ifndef LINE_HPP
#define LINE_HPP

#include <SchematicEditor/SymbolItem.hpp>

class Pin;

class Line : public SymbolItem
{
public:
    Line(QGraphicsItem *parent = nullptr);

    void setPin1(Pin*);
    void setPin2(Pin*);

    void setBegin(QPointF);
    void setEnd(QPointF);

    QRectF boundingRect() const override;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;

private:
    QPointF begin, end;
    Pin* pin1;
    Pin* pin2;
};

#endif // LINE_HPP
