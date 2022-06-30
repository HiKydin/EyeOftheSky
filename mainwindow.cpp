#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCameraInfo>
#include <QCamera>
#include <QDebug>
#include <QVideoWidget>
#include <QCameraImageCapture>
#include "JQQRCodeReader.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*******************界面配置*************************/

    //设置标题和Icon
    this->setWindowIcon(QIcon(":/res/MainIcon.png"));
    this->setWindowTitle("EyeOftheSky");


    /*******************功能配置*************************/

    //连接菜单栏的关闭按钮
    connect(ui->actionclose,&QAction::triggered,[=](){
        this->close();
    });

    //视频输出
    QCamera *camera = NULL;
    const QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    for (const QCameraInfo &cameraInfo : cameras)
    {
        ui->listWidget->addItem(cameraInfo.description());
        camera = new QCamera(cameraInfo);
        map_camera.insert(cameraInfo.description(),camera);
    }

    connect(ui->listWidget, &QListWidget::itemClicked,
            this, &MainWindow::slot_listwidget_item_clicked);

    //用来捕捉二维码的照相机
    QCodeimageCapture = new QCameraImageCapture(map_camera.first());
    //将图片拍摄与二维码读取槽函数连接
    connect(QCodeimageCapture,&QCameraImageCapture::imageCaptured,this,&MainWindow::slot_camera_captured);
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
//快照
void MainWindow::on_pushButton_capture_clicked()
{
    QString path=
            QString("C:\\Users\\admin\\Desktop\\%1.jpg")
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
//showAll
void MainWindow::on_pushButton_showAll_clicked()
{
    map_camera.first()->setViewfinder(ui->widget);
    map_camera.first()->start();
    map_camera.last()->setViewfinder(ui->widget_2);
    map_camera.last()->start();
}

//读取二维码的槽函数
void MainWindow::slot_camera_captured(int fd,const QImage &testImage)
{
    //创建二维码解析对象
    JQQRCodeReader qrCodeReader;
    //输出结果
    QString rst = qrCodeReader.decodeImage(testImage, JQQRCodeReader::DecodeQrCodeType );
    QMessageBox::information(this,"识别结果",rst);
}
//点击按钮，开始拍摄二维码
void MainWindow::on_btn_QCode_clicked()
{
    //创建相机对象，并拍摄
    QCamera *camera = map_camera.first();

    camera->setCaptureMode(QCamera::CaptureStillImage);
    camera->start();
    //on half pressed shutter button
    camera->searchAndLock();
    //on shutter button pressed
    QCodeimageCapture->capture();
    //on shutter button released
    camera->unlock();
}
MainWindow::~MainWindow()
{
    delete ui;
}
