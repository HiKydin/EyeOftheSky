#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();
    void paintEvent(QPaintEvent *);

private:
    Ui::Login *ui;
    const char username[10] = "admin";
    const char userpwd[10] = "admin";
};
#endif // LOGIN_H
