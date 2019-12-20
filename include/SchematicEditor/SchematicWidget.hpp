#ifndef SCHEMATICEDITOR_HPP
#define SCHEMATICEDITOR_HPP

#include <QtWidgets/QGraphicsView>

class SchematicScene;

class SchematicWidget : public QGraphicsView
{
    Q_OBJECT

////////////////////////////////////
///            ENUMS             ///
////////////////////////////////////
private:

/////////////////////////////////////
///            METHODS            ///
/////////////////////////////////////
public:
    SchematicWidget(QWidget* parent = nullptr);

    void addResistor();
    void addVoltage();

protected:
    void wheelEvent(QWheelEvent*) override;

/////////////////////////////////////
///            MEMBERS            ///
/////////////////////////////////////
private:
    SchematicScene* scene;
};


#endif // SCHEMATICEDITOR_HPP
