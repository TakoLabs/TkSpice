#ifndef RESISTOR_HPP
#define RESISTOR_HPP

#include <Symbol.hpp>

class Resistor : public Symbol
{
public:
    Resistor() = default;
    ~Resistor() = default;

protected:
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) override;

private:
};

#endif // RESISTOR_HPP
