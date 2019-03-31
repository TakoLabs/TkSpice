#ifndef SYMBOL_HPP
#define SYMBOL_HPP


#include <QtWidgets/QGraphicsItem>

class Symbol : public QGraphicsItem
{
public:
    Symbol();

    QRectF boundingRect() const override;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;

    void setSelected(bool);
    bool isSelected() const;

private:
    bool selected;

};

#endif // SYMBOL_HPP
