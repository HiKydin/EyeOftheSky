#include "login.h"
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QPainter>
#include "mainwindow.h"

login::login(QWidget *parent)
    : QWidget(parent)
{
    /*******************界面配置*************************/

    //登录界面配置
    this->setWindowIcon(QIcon(":/res/MainIcon.png"));
    this->setFixedSize(500,500);
    this->setWindowTitle("EyeOfTheSky    登录界面");

    //
    //添加按钮
    QPushButton *btn_Signin = new QPushButton("注册");
    btn_Signin->setParent(this);
    btn_Signin->setFixedSize(100,50);
    btn_Signin->move((this->width()/2)-btn_Signin->width(),this->height()/2+100);

    QPushButton *btn_Login = new QPushButton("登录");
    btn_Login->setParent(this);
    btn_Login->setFixedSize(100,50);
    btn_Login->move((this->width()/2),this->height()/2+100);


    //创建文本框
    QLineEdit *usernameText = new QLineEdit(this);
    QLineEdit *userpwdText = new QLineEdit(this);
    usernameText->resize(200,usernameText->height());
    userpwdText->resize(200,userpwdText->height());
    usernameText->move(150,200);
    userpwdText->move(150,250);

    //创建文本
    QLabel *usernamelbl = new QLabel(this);
    usernamelbl->setText("账号:");
    QLabel *userpwdlbl = new QLabel(this);
    userpwdlbl->setText("密码:");

    usernamelbl->move(100,200);
    userpwdlbl->move(100,250);

    //水平垂直居中
    usernamelbl->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    userpwdlbl->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    //鼠标穿透事件
    usernamelbl->setAttribute(Qt::WA_TransparentForMouseEvents);
    userpwdlbl->setAttribute(Qt::WA_TransparentForMouseEvents);

    //设置主标题
    QLabel *maintitle = new QLabel(this);
    maintitle->setText("天眼");
    QFont font;
    font.setFamily("微软雅黑");
    font.setPixelSize(50);
    maintitle->setFont(font);
    //自适应大小
    maintitle->adjustSize();
    maintitle->move(200,70);

    /*******************功能配置*************************/

    MainWindow *vediowindow = new MainWindow();
    vediowindow->resize(1800,1000);


    connect(btn_Login,&QPushButton::clicked,[=](){
        //qDebug()<<"点击了登录";
        if(strcmp(usernameText->text().toUtf8().data(),username)==0 && strcmp(userpwdText->text().toUtf8().data(),userpwd)==0)
        {
            //qDebug()<<"登录成功";
            this->hide();
            vediowindow->show();
        }
        else if(usernameText->text()=="" || userpwdText->text()== "")
        {
            QMessageBox::critical(this,"error","请输入用户名和密码");
        }
        else
        {
            QMessageBox::critical(this,"error","请检查您的账号密码");
            usernameText->clear();
            userpwdText->clear();
        }
    });

}
void login::paintEvent(QPaintEvent *)
{
    //绘制主图
    QPainter painter(this);

    //初始化pix资源
    QPixmap pix;
    QString pixPath = ":/res/MainIcon.png";
    pix.load(pixPath);
    pix = pix.scaled(pix.width()*0.7,pix.height()*0.7);

    //设置抗锯齿
    painter.setRenderHint(QPainter::Antialiasing);

    painter.drawPixmap(0,15,pix);

}
login::~login()
{

}
