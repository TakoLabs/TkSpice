#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

namespace Ui {
class MainWindow;
}


class SchematicWidget;
class QLabel;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_aAddResistor_triggered();

    void on_aAddVoltage_triggered();

private:
    Ui::MainWindow *ui;
    SchematicWidget* editor;

};

#endif // MAINWINDOW_HPP
