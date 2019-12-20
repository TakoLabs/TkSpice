#ifndef SYMBOLITEM_HPP
#define SYMBOLITEM_HPP

#include <QtWidgets/QGraphicsItem>

class SymbolItem : public QGraphicsItem
{
public:
    SymbolItem(QGraphicsItem* parent = nullptr);

protected:
    QVariant itemChange(GraphicsItemChange, const QVariant&) override;
};

#endif // SYMBOLITEM_HPP
