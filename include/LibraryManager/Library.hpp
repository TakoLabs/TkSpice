#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <QtCore/QVector>

class Component;

class Library
{
public:
    Library();
    
    void AddComponent();

private:
    QVector<Component*>* comp_list;
};

#endif // LIBRARY_HPP
