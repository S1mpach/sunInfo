#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QNetworkReply>
#include <QNetworkAccessManager>
#include <QMainWindow>
#include<QJsonDocument>
#include<QJsonArray>
#include<QJsonObject>
#include<QList>
#include<fstream>
#include <QFile>
#include<QMessageBox>
#include<vector>
#include <QMainWindow>
#include<geolocationmanager.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Check_clicked();

private:
    std::shared_ptr<GeoLocationManager> ptr_GeoLocationManager = GeoLocationManager::getAccess();
    SunInfo res;
    QString buffer{};
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
