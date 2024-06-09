#ifndef LOGIN_H
#define LOGIN_H


#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QFileInfo>
#include <QDebug>
#include <QMessageBox>

#include "secdialog.h"



QT_BEGIN_NAMESPACE
namespace Ui {
class login;

}

// class secdialog;

QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT




public:
    login(QWidget *parent = nullptr);
    ~login();



    // bool connOpen();// QSqlDatabase mydb;

    // void login::connClose() {
    //     mydb.close();
    //     mydb.removeDatabase(QSqlDatabase::defaultConnection);

    // }

    // bool login::connOpen() {

    //     QDir databasePath;
    //     QString dbpath = databasePath.currentPath()+"/mydb.db";
    //     QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    //     mydb.setDatabaseName(dbpath);
    //     mydb.open();

    //     if (mydb.open()) {
    //         // QMessageBox::information(this, "Connection", "Database Connected Successfully");

    //         QString query = "CREATE TABLE IF NOT EXISTS coursesTable ("
    //                         "Course_Name VARCHAR(20), "
    //                         "Course_Credits integer, "
    //                         "Course_Grade VARCHAR(1));";

    //         QSqlQuery qry;
    //         // query.exec("create table courses "
    //         //            "Course_Name varchar(20), "
    //         //            "Course_Credits integer, "
    //         //            "Course_Grade varchar(1)");
    //         // QSqlQuery query("mydb");
    //         // query.prepare("CREATE TABLE IF NOT EXISTS data (id int not null primary key, tu text, data BLOB, puits integer);");

    //         if (!qry.exec(query)) {
    //             qDebug()<<"Error creating table";
    //         }

    //         qDebug()<<"end";
    //         return true;


    //     } else {
    //         // QMessageBox::information(this, "Connection", "Database FAILED");
    //         return false;
    //     }
    // }
    void connClose();

private slots:
    void on_btn_login_clicked();


private:
    Ui::login *ui;
    SecDialog *userClassApp;
    SecDialog *secDialog;
};
#endif // LOGIN_H
