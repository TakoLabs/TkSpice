QT  += core gui widgets

TARGET = TkSpice
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++17

SOURCES +=  \
            src/main.cpp \
            src/Node.cpp \
            src/Resistor.cpp \
            src/MainWindow.cpp \
            src/Model.cpp \
            src/Symbol.cpp \
            src/LibraryManager/LibraryManager.cpp \
            src/LibraryManager/Library.cpp \
    src/Widgets/SchematicEditor.cpp

HEADERS += \
            include/Node.hpp \
            include/Resistor.hpp \
            include/Component.hpp \
            include/MainWindow.hpp \
            include/Model.hpp \
            include/Symbol.hpp \
            include/LibraryManager/LibraryManager.hpp \
            include/LibraryManager/Library.hpp \
            include/Widgets/SchematicEditor.hpp

INCLUDEPATH += include

FORMS += \
    ui/MainWindow.ui
