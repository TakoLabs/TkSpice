#ifndef LIBRARYMANAGER_HPP
#define LIBRARYMANAGER_HPP

#include <QtCore/QVector>
#include <QtCore/QUrl>

class Library;

class LibraryManager
{
public:
    LibraryManager();
    void AddLibrary(const QString& name, const QUrl& path);

private:
    QVector<Library*>* lib_list;
};

#endif // LIBRARYMANAGER_HPP
