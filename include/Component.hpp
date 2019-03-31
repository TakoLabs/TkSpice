#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <Node.hpp>
#include <QtCore/QStringList>
#include <QtCore/QString>
#include <QtCore/QList>

class Component
{
public:
    Component();

    QString getLetter() const;
    QString getName() const;
    QList<Node*> getPins() const;
    bool hasModel() const;
    QString getModelName() const;
    QStringList getParamValues() const;
};

#endif // COMPONENT_HPP
