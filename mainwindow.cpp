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

void MainWindow::on_pushButton_Check_clicked()
{


    buffer = ui->lineEdit_input->text();
    if(buffer.size() < 2)
    {
        res = ptr_GeoLocationManager->getInfo();
    }else {
        res = ptr_GeoLocationManager->getInfo(buffer);

    }

    qDebug()<<"HERE RES";
qDebug()<<res.getPlaceName();
qDebug()<<res.getSunSet();
qDebug()<<res.getSunRise();

    ui->label_place->setText(res.getPlaceName());
    ui->label_sunset->setText(res.getSunSet());
    ui->label_sunrise->setText(res.getSunRise());
    buffer.clear();

}
