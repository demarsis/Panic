#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    MapPtr cafe = MapGeneratorCafe().generate();
    FloorPtr groundFloor= cafe->getFloors()[0];
    ui->openGLWidget->setFloorImage(groundFloor->getFloorImage()->getImage());
    ui->openGLWidget->update();
}
