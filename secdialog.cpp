#include "secdialog.h"
#include "ui_secdialog.h"
#include <QMessageBox>

void addValues( QString Course_Name, int Course_Credits, QString Course_Grade);

SecDialog::SecDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SecDialog)
{
    ui->setupUi(this);

    QDir databasePath;
    QString dbpath = databasePath.currentPath()+"/mydb.db";
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(dbpath);

    if (mydb.open()) {
        QMessageBox::information(this, "Connection", "Database Connected Successfully");

        QString query = "CREATE TABLE IF NOT EXISTS coursesTable ("
                      "Course_Name VARCHAR(20), "
                      "Course_Credits integer, "
                      "Course_Grade VARCHAR(1));";

        QSqlQuery qry;
        // query.prepare("CREATE TABLE IF NOT EXISTS data (id int not null primary key, tu text, data BLOB, puits integer);");

        if (!qry.exec(query)) {
            qDebug()<<"Error creating table";
        }

        // addValues("Math", 4, "A");


        qDebug()<<"end";


    } else {
        QMessageBox::information(this, "Connection", "Database FAILED");
    }
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

}

