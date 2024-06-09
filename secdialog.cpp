#include "secdialog.h"
#include "ui_secdialog.h"
#include <QMessageBox>

SecDialog::SecDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SecDialog)
{
    ui->setupUi(this);


    connOpen();
    // m_mydb->open();

    QSqlQuery qry;


    qry.exec("CREATE TABLE courses, "
                "Course_Name varchar(20), "
                "Course_Credits integer, "
                "Course_Grade varchar(1)");

    if(!qry.exec()) {
        qDebug() << "Sec Dialog Widget Class = " << qry.lastError();
    } else {
        qDebug() << "Table Created";
    }


    // QSqlQuery m_mydb("CREATE TABLE courses "
    //                  "Course_Name varchar(20), "
    //                  "Course_Credits integer, "
    //                  "Course_Grade varchar(1)");

    // QSqlQuery query;

    // query.prepare("CREATE TABLE IF NOT EXISTS courses "
    //                  "Course_Name varchar(20), "
    //                  "Course_Credits integer, "
    //                  "Course_Grade varchar(1)");



    // QSqlQuery query("CREATE TABLE courses "
    //                 "Course_Name varchar(20), "
    //                 "Course_Credits integer, "
    //                 "Course_Grade varchar(1)");



    // QSqlQuery query;
    // QSqlQueryModel * modal = new QSqlQueryModel();

    // QSqlQuery* qry = new QSqlQuery();



    // connOpen();

    // QDir databasePath;
    // QString dbpath = databasePath.currentPath()+"/mydb.db";
    // QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    // mydb.setDatabaseName(dbpath);

    // if (mydb.open()) {
    //     QMessageBox::information(this, "Connection", "Database Connected Successfully");

    //     QString query = "CREATE TABLE IF NOT EXISTS coursesTable ("
    //                   "Course_Name VARCHAR(20), "
    //                   "Course_Credits integer, "
    //                   "Course_Grade VARCHAR(1));";

    //     QSqlQuery qry;
    //     // query.prepare("CREATE TABLE IF NOT EXISTS data (id int not null primary key, tu text, data BLOB, puits integer);");

    //     if (!qry.exec(query)) {
    //         qDebug()<<"Error creating table";
    //     }

    //     // addValues("Math", 4, "A");


    //     qDebug()<<"end";


    // } else {
    //     QMessageBox::information(this, "Connection", "Database FAILED");
    // }
}

SecDialog::~SecDialog()
{

    delete ui;
}

void addValues( QString Course_Name, int Course_Credits, QString Course_Grade) {

    QSqlQuery qry;
    qry.prepare("INSERT INTO coursesTable ("
                "Course_Name, "
                "Course_Credits, "
                "Course_Grade)"
                "VALUES (?,?,?);");

    qry.addBindValue(Course_Name);
    qry.addBindValue(Course_Credits);
    qry.addBindValue(Course_Grade);

    if(!qry.exec()) {
        qDebug() <<"error adding values to db";
    }
}
void SecDialog::on_pushButton_add_clicked()
{
    QString className, classGrade;
    int classCredits;

    className=ui->lineEdit_className->text();
    classCredits=ui->lineEdit_classCredits->text().toInt();
    classGrade=ui->lineEdit_classGrade->text();


    addValues(className, classCredits, classGrade);

}


void SecDialog::on_pushButton_exit_clicked()
{
    // login::connClose();
}


void SecDialog::on_pushButton_clicked()
{

}
QSqlDatabase mydb;

void SecDialog::connClose() {
    mydb.close();
    mydb.removeDatabase(QSqlDatabase::defaultConnection);

}

bool SecDialog::connOpen() {

    QDir databasePath;
    QString dbpath = databasePath.currentPath()+"/mydb.db";
    m_dbpath = dbpath;




    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(dbpath);

    // m_mydb->setDatabaseName(dbpath);
    // m_mydb.open();

    if (mydb.open()) {
        // QSqlQuery qry;


        // qry.prepare("CREATE TABLE IF NOT EXISTS courses, "
        //               "Course_Name varchar(20), "
        //               "Course_Credits integer, "
        //               "Course_Grade varchar(1)");

        // if(!qry.exec()) {
        //     qDebug() << qry.lastError();
        // } else {
        //     qDebug() << "Table Created";
        // }





        // QMessageBox::information(this, "Connection", "Database Connected Successfully");

        // QString query = "CREATE TABLE IF NOT EXISTS coursesTable ("
        //                 "Course_Name VARCHAR(20), "
        //                 "Course_Credits integer, "
        //                 "Course_Grade VARCHAR(1));";

        // QSqlQuery qry;
        // query.exec("create table courses "
        //            "Course_Name varchar(20), "
        //            "Course_Credits integer, "
        //            "Course_Grade varchar(1)");
        // QSqlQuery query("mydb");
        // query.prepare("CREATE TABLE IF NOT EXISTS data (id int not null primary key, tu text, data BLOB, puits integer);");

        // if (!qry.exec(query)) {
        //     qDebug()<<"Error creating table";
        // }



        qDebug()<<"end";
        return true;


    } else {
        // QMessageBox::information(this, "Connection", "Database FAILED");
        return false;
    }

    // QDir databasePath;
    // QString dbpath = databasePath.currentPath()+"/mydb.db";
    // QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");



    // mydb.setDatabaseName(dbpath);
    // mydb.open();

    // if (mydb.open()) {
    //     // QMessageBox::information(this, "Connection", "Database Connected Successfully");

    //     QString query = "CREATE TABLE IF NOT EXISTS coursesTable ("
    //                     "Course_Name VARCHAR(20), "
    //                     "Course_Credits integer, "
    //                     "Course_Grade VARCHAR(1));";

    //     QSqlQuery qry;
    //     // query.exec("create table courses "
    //     //            "Course_Name varchar(20), "
    //     //            "Course_Credits integer, "
    //     //            "Course_Grade varchar(1)");
    //     // QSqlQuery query("mydb");
    //     // query.prepare("CREATE TABLE IF NOT EXISTS data (id int not null primary key, tu text, data BLOB, puits integer);");

    //     if (!qry.exec(query)) {
    //         qDebug()<<"Error creating table";
    //     }

    //     qDebug()<<"end";
    //     return true;


    // } else {
    //     // QMessageBox::information(this, "Connection", "Database FAILED");
    //     return false;
    // }
}


