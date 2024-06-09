#include "login.h"
#include "ui_login.h"
#include <QMessageBox>


login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);

    // QDir databasePath;
    // QString dbpath = databasePath.currentPath()+"/mydb.db";

    // QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    // mydb.setDatabaseName(dbpath);
    // mydb.open();



    // QSqlQuery query("CREATE TABLE courses "
    //                  "Course_Name varchar(20), "
    //                  "Course_Credits integer, "
    //                  "Course_Grade varchar(1)");


    // query.exec("CREATE TABLE courses "
    //            "Course_Name varchar(20), "
    //            "Course_Credits integer, "
    //            "Course_Grade varchar(1)");

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

        ui->statusbar->showMessage("Username and password is correct", 2000);

        // QDir databasePath;
        // QString dbpath = databasePath.currentPath()+"/mydb.db";
        // QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
        // mydb.setDatabaseName(dbpath);

        QMessageBox::information(this, "Login","Username and password is correct");
        hide();


        // secDialog = new SecDialog(this);
        userClassApp = new SecDialog(this);


        // QSqlQuery query;



        // connOpen();
        if (userClassApp->connOpen()) {
            QMessageBox::information(this, "Connection", "Database Connected Successfully");

            userClassApp->show();


            // secDialog = new SecDialog(this);
            // secDialog->show();

        } else {
            QMessageBox::information(this, "Login", "Failed to open Database... Try again...");
        }



        // if (mydb.open()) {
        //     QMessageBox::information(this, "Connection", "Database Connected Successfully");
        //     QSqlQuery query("mydb");
        //     // query.prepare("CREATE TABLE IF NOT EXISTS data (id int not null primary key, tu text, data BLOB, puits integer);");
        //     query.prepare("create table if not exists courses "
        //                "(id integer primary key, "
        //                "Course_Name varchar(20), "
        //                "Course_Credits integer, "
        //                "Course_Grade varchar(1)");
        // } else {
        //     QMessageBox::information(this, "Connection", "Database FAILED");
        // }

    } else {
        // QMessageBox::warning(this, "Login", "Username and password combo not correct");
        ui->statusbar->showMessage("Username and password validation failed...", 2000);
    }

}





