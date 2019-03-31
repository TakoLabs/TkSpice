#include <MainWindow.hpp>
#include "ui_MainWindow.h"
#include <Widgets/SchematicEditor.hpp>
#include <QtWidgets/QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->editor = new SchematicEditor(this);
    this->statusZoom = new QLabel(this);
    this->statusMousePos = new QLabel(this);

    setEditorZoomStatus(1);
    setEditorMousePosStatus(QPoint(0, 0));


    this->ui->statusbar->addPermanentWidget(this->statusZoom);
    this->ui->statusbar->addPermanentWidget(this->statusMousePos);


    connect(this->editor, SIGNAL(zoomChanged(double)), this, SLOT(setEditorZoomStatus(double)));
    connect(this->editor, SIGNAL(mouseMoved(QPoint)), this, SLOT(setEditorMousePosStatus(QPoint)));


    this->setCentralWidget(this->editor);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::setEditorZoomStatus(double factor) {
    QString text { tr("Zoom: x") };
    text += QString::number(factor);
    this->statusZoom->setText(text);
}

void MainWindow::setEditorMousePosStatus(const QPoint& pos) {
    QString text { tr("Mouse: ") };
    text += QString::number(pos.x()) + ", " + QString::number(pos.y());
    this->statusMousePos->setText(text);
}


void MainWindow::on_aAddResistor_triggered()
{
    this->editor->addComponent(0);
}
