#include <MainWindow.hpp>
#include "ui_MainWindow.h"
#include <SchematicEditor/SchematicWidget.hpp>
#include <QtWidgets/QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->editor = new SchematicWidget(this);

    this->setCentralWidget(this->editor);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_aAddResistor_triggered() {
    this->editor->addResistor();
}

void MainWindow::on_aAddVoltage_triggered() {
    this->editor->addVoltage();
}
