#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCameraInfo>
#include <QCamera>
#include <QDebug>
#include <QVideoWidget>
#include <QCameraImageCapture>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*******************界面配置*************************/
    this->setWindowIcon(QIcon(":/res/MainIcon.png"));
    this->setWindowTitle("EyeOftheSky");


    /*******************功能配置*************************/
    connect(ui->actionclose,&QAction::triggered,[=](){
        this->close();
    });




    QCamera *camera = NULL;
    const QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    for (const QCameraInfo &cameraInfo : cameras)
    {
        //qDebug()<<cameraInfo.deviceName();
        qDebug()<<cameraInfo.description();

        ui->listWidget->addItem(cameraInfo.description());
        camera = new QCamera(cameraInfo);
        map_camera.insert(cameraInfo.description(),camera);
    }

    connect(ui->listWidget, &QListWidget::itemClicked,
            this, &MainWindow::slot_listwidget_item_clicked);
}

//摄像头选中
void MainWindow::slot_listwidget_item_clicked(QListWidgetItem *item)
{
    QMap<QString, QCamera*>::const_iterator i = map_camera.find(item->text());
    if (i != map_camera.end())
    {
        qDebug() <<i.key()<<i.value() << endl;
    }
    i.value()->setViewfinder(ui->widget);
    i.value()->start();
}

//capture按钮
void MainWindow::on_pushButton_capture_clicked()
{
    QString path=
            QString("D:\\code\\QT_Example\\camera\\camera\\%1.jpg")
            .arg(cap_number++);
    QCamera *camera = map_camera.first();
    QCameraImageCapture imageCapture(camera);

    camera->setCaptureMode(QCamera::CaptureStillImage);
    camera->start();
    //on half pressed shutter button
    camera->searchAndLock();
    //on shutter button pressed
    imageCapture.capture(path);
    //on shutter button released
    camera->unlock();
}
//showAll按钮
void MainWindow::on_pushButton_showAll_clicked()
{
    map_camera.first()->setViewfinder(ui->widget);
    map_camera.first()->start();
    map_camera.last()->setViewfinder(ui->widget_2);
    map_camera.last()->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
