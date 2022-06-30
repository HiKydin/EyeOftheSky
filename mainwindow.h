#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCamera>
#include <QMap>
#include <QListWidgetItem>
#include <QCameraImageCapture>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void slot_listwidget_item_clicked(QListWidgetItem *item);
    void on_pushButton_showAll_clicked();
    void on_pushButton_capture_clicked();
    void slot_camera_captured(int fd,const QImage &testImage);
    void on_btn_QCode_clicked();

private:
    Ui::MainWindow *ui;

    QMap<QString, QCamera*> map_camera;
    int cap_number = 0;

    QCameraImageCapture *QCodeimageCapture = NULL;
};
#endif // MAINWINDOW_H
