#include "login.h"
#include "./ui_login.h"
#include <QMessageBox>


login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);

    QDir databasePath;
    QString dbpath = databasePath.currentPath()+"/mydb.db";

    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(dbpath);
    mydb.open();
    QSqlQuery query;
    query.exec("create table courses "
               "(id integer primary key, "
               "Course_Name varchar(20), "
               "Course_Credits integer, "
               "Course_Grade varchar(1)");
}

login::~login()
{
    delete ui;
}

void login::on_btn_login_clicked()
{
    QString username = ui->line_user->text();
    QString password = ui->line_pw->text();

    if (username == "test" && password == "test") {
        // QMessageBox::information(this, "Login","Username and password is correct");
        // hide();

        // secDialog = new SecDialog(this);
        // secDialog->show();
        ui->statusbar->showMessage("Username and password is correct", 2000);

        QDir databasePath;
        QString dbpath = databasePath.currentPath()+"/mydb.db";
        QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName(dbpath);

        if (mydb.open()) {
            QMessageBox::information(this, "Connection", "Database Connected Successfully");
        } else {
            QMessageBox::information(this, "Connection", "Database FAILED");
        }

    } else {
        // QMessageBox::warning(this, "Login", "Username and password combo not correct");
        ui->statusbar->showMessage("Username and password validation failed...", 2000);
    }

}

