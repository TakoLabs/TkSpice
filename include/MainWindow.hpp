#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

namespace Ui {
class MainWindow;
}


class SchematicEditor;
class QLabel;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void setEditorZoomStatus(double factor);
    void setEditorMousePosStatus(const QPoint& pos);

    void on_aAddResistor_triggered();

private:
    Ui::MainWindow *ui;
    SchematicEditor* editor;
    QLabel* statusZoom;
    QLabel* statusMousePos;

};

#endif // MAINWINDOW_HPP
