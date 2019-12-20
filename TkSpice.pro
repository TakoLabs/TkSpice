QT  += core gui widgets

TARGET = TkSpice
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++17

SOURCES +=  \
            src/main.cpp \
            src/MainWindow.cpp \
            src/LibraryManager/LibraryManager.cpp \
            src/LibraryManager/Library.cpp \
            src/SchematicEditor/SchematicWidget.cpp \
            src/SchematicEditor/SchematicScene.cpp \
            src/SchematicEditor/SymbolItem.cpp \
            src/SchematicEditor/Resistor.cpp \
            src/SchematicEditor/Voltage.cpp \
    src/SchematicEditor/Pin.cpp \
    src/SchematicEditor/Line.cpp

HEADERS += \
            include/MainWindow.hpp \
            include/LibraryManager/LibraryManager.hpp \
            include/LibraryManager/Library.hpp \
            include/SchematicEditor/SchematicWidget.hpp \
            include/SchematicEditor/SchematicScene.hpp \
            include/SchematicEditor/SymbolItem.hpp \
            include/SchematicEditor/Resistor.hpp \
            include/SchematicEditor/Voltage.hpp \
    include/SchematicEditor/Pin.hpp \
    include/SchematicEditor/Line.hpp

INCLUDEPATH += include

FORMS += \
    ui/MainWindow.ui
