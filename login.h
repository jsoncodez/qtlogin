#ifndef LOGIN_H
#define LOGIN_H


#include <QMainWindow>
#include "secdialog.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class login;
}
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_btn_login_clicked();


private:
    Ui::login *ui;
    SecDialog *secDialog;
};
#endif // LOGIN_H
