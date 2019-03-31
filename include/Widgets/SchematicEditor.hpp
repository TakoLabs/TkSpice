#ifndef SCHEMATICEDITOR_HPP
#define SCHEMATICEDITOR_HPP

#include <QtWidgets/QGraphicsView>
#include <Symbol.hpp>

class SchematicEditor : public QGraphicsView
{
    Q_OBJECT

////////////////////////////////////
///            ENUMS             ///
////////////////////////////////////
private:
    enum State {
        Nothing             = 0b0,
        PlacingComponent    = 0b1 ,
        MovingComponent     = 0b10,
        MovingView          = 0b100
    };
    Q_DECLARE_FLAGS(States, State)

    enum Tool {
        Select,
        Place
    };


/////////////////////////////////////
///            METHODS            ///
/////////////////////////////////////
public:
    SchematicEditor(QWidget* parent = nullptr);

    void addComponent(uint compID);
    void moveComponent(Symbol* component, const QPoint& pos);

public slots:
    void zoomIn();
    void zoomOut();
    void moveView(const QPoint& pos);

signals:
    void zoomChanged(double factor);
    void mouseMoved(const QPoint& pos);

protected:
    virtual void wheelEvent(QWheelEvent*) override;    
    virtual void mouseReleaseEvent(QMouseEvent*) override;
    virtual void mousePressEvent(QMouseEvent*) override;
    virtual void mouseMoveEvent(QMouseEvent*) override;
    virtual void keyPressEvent(QKeyEvent*) override;

private:
    QPoint toSceneCoord(const QPoint& pos) const;
    void appendSelectedComponent(Symbol*);
    void removeSelectedComponent(Symbol*);
    void clearSelectedComponents();


/////////////////////////////////////
///            MEMBERS            ///
/////////////////////////////////////
private:
    QGraphicsScene* scene;

    // View states
    States state;
    Tool tool;
    bool selecting;

    // View members
    double zoomFactor;
    QPoint lastMousePos;
    int lastVScrollBarPos;
    int lastHScrollBarPos;
    QVector<Symbol*> selectedComponents;
    QVector<Symbol*> movingComponents;

    // Components management
    QVector<Symbol*> componentList;
};


#endif // SCHEMATICEDITOR_HPP
