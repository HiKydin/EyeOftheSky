#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

class login : public QWidget
{
    Q_OBJECT

public:
    login(QWidget *parent = 0);
    ~login();
    void paintEvent(QPaintEvent *);//重写绘图事件

private:
    const char username[10] = "admin";//用户名
    const char userpwd[10] = "admin";//密码
};

#endif // LOGIN_H
