#ifndef SCHEMATICSCENE_HPP
#define SCHEMATICSCENE_HPP

#include <QtWidgets/QGraphicsScene>

class Line;

class SchematicScene : public QGraphicsScene
{
    Q_OBJECT
public:
    SchematicScene(QObject* parent = nullptr);

    int getGridSize() const;
    void setGridSize(int);

protected:
    void drawBackground(QPainter*, const QRectF&) override;
    void mousePressEvent(QGraphicsSceneMouseEvent*) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent*) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent*) override;

private:
    Line* current_line;
    int grid_size;
    bool drawLine;
};

#endif // SCHEMATICSCENE_HPP
