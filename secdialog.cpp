#include "secdialog.h"
#include "ui_secdialog.h"
#include <QMessageBox>

SecDialog::SecDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SecDialog)
{
    ui->setupUi(this);


    // connOpen();
    // m_mydb->open();

    QDir databasePath;
    QString dbpath = databasePath.currentPath()+"/mydb.db";

    // QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    // mydb.setDatabaseName(dbpath);
    // mydb.open();


    m_mydb = QSqlDatabase::addDatabase("QSQLITE");
    m_mydb.setDatabaseName(dbpath);
    m_mydb.open();



    QString query = "CREATE TABLE IF NOT EXISTS coursesTable ("
                  "Course_Name VARCHAR(20), "
                  "Course_Credits integer, "
                  "Course_Grade VARCHAR(1));";


    QSqlQuery qry;

    if (!qry.exec(query)) {
        qDebug() << "error creating table";
    }


    // qry.exec("CREATE TABLE courses, "
    //             "Course_Name varchar(20), "
    //             "Course_Credits integer, "
    //             "Course_Grade varchar(1)");

    // if(!qry.exec()) {
    //     qDebug() << "Sec Dialog Widget Class = " << qry.lastError();
    // } else {
    //     qDebug() << "Table Created";
    // }


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

void SecDialog::calcGPA() {

    float GPA; //qDebug() << QString::number(1.125, 'f', 2);
            // qDebug() << QString::number(1.125, 'f', 2);
            // qDebug() << "Rounding 314.19 to 3 decimal places = " << QString::number(myStr.toDouble(), 'f', 3);
            // qDebug() << "Rounding 314.1945327743682 to 6 decimal places = " << QString::number(myStr.toDouble(), 'f',dec_pl);
    std::vector<int> eachQPI;
    int qpiSum;
    int creditsSum = 0;
    int currentCredit = 0;

    QSqlQueryModel gradeQry;
    gradeQry.setQuery("select * from coursesTable");
    m_mydb.open();
    // QSqlTableModel gradeModel;

    // gradeModel.setTable("courseTable");


    // QSqlQueryModel gradeQry;
    // gradeQry.setQuery("SELECT * FROM courseTable");

    for (int i = 0; i < gradeQry.rowCount(); i++) {
        currentCredit = gradeQry.record(i).value("Course_Credits").toInt();
        creditsSum += gradeQry.record(i).value("Course_Credits").toInt();
        qDebug() << "CREDITS.....= " << currentCredit;
    }
    qDebug() << "CREDITS SUM = " << creditsSum;


}

void SecDialog::on_pushButton_add_clicked()
{
    QString className, classGrade;
    int classCredits;

    className=ui->lineEdit_className->text();
    classCredits=ui->lineEdit_classCredits->text().toInt();
    classGrade=ui->lineEdit_classGrade->text();


    addValues(className, classCredits, classGrade);


        //POST to table
    QSqlQueryModel * modal = new QSqlQueryModel();
    modal->setQuery("select * from coursesTable");
    m_mydb.open();

    ui->tableView_classList->setModel(modal);

    calcGPA();

}


void SecDialog::on_pushButton_exit_clicked()
{
    // login::connClose();
}


void SecDialog::on_pushButton_load_clicked()
{
    QSqlQueryModel * modal = new QSqlQueryModel();
    modal->setQuery("select * from coursesTable");
    m_mydb.open();
    // QTableView *view = new QTableView;
    ui->tableView_classList->setModel(modal);

    // view->tableView_classList->setModel(modal);

    // view->show();



    // QSqlQueryModel * modal = new QSqlQueryModel();

    // m_mydb.open();

    // QSqlQuery* qry = new QSqlQuery(m_mydb);
    // qry->prepare("select * from coursesTable");
    // qry->exec();
    // modal->setQuery(*qry);
    // ui->tableView_classList->setModel(modal);
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




