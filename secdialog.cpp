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
    
    QSqlTableModel *modal = new QSqlTableModel;
    modal->setTable("coursesTable");
    
    
    modal->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modal->select();
    
    QTableView *view = ui->tableView_classList;
    // QTableView *view = new QTableView;
    view->setModel(modal);
    // view->hideColumn(0); // don't show the ID
    view->show();
    

    QString query = "CREATE TABLE IF NOT EXISTS coursesTable ("
                  "Course_Name VARCHAR(20), "
                  "Course_Credits integer, "
                  "Course_Grade VARCHAR(1));";


    QSqlQuery qry;
    
    
    ui->tableView_classList->setSelectionBehavior(QAbstractItemView::SelectRows);
    
    if (!qry.exec(query)) {
        qDebug() << "error creating table";
    }
    
    m_mydb.close();

}

SecDialog::~SecDialog()
{

    delete ui;
}

void SecDialog::addValues2( QString Course_Name, int Course_Credits, QString Course_Grade) {
    // QSqlTableModel *modal = new QSqlTableModel();
    // m_mydb.open();
    
    m_mydb.open();
    QSqlTableModel *modal = new QSqlTableModel;
    modal->setTable("coursesTable");
    
    
    modal->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modal->select();
    
    
    
    const int row = modal->rowCount();
    modal->insertRows(row, 1);
    modal->setData(modal->index(row,0), Course_Name);
    modal->setData(modal->index(row,1), Course_Credits);
    modal->setData(modal->index(row,2), Course_Grade);
    
    modal->submitAll();
    
    
    QTableView *view = ui->tableView_classList;
    // QTableView *view = new QTableView;
    view->setModel(modal);
    // view->hideColumn(0); // don't show the ID
    view->show();
    

    

   
    
    // ui->tableView_classList->setModel(modal);
    
    

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

    int qpiSum = 0;
    int creditsSum = 0;
    int currentCredit = 0;

    m_qpiSum = 0;
    m_creditsSum = 0;
    // QString sGPA = "";
    QSqlQueryModel gradeQry;
    gradeQry.setQuery("select * from coursesTable");
    m_mydb.open();
    // QSqlTableModel gradeModel;

    // gradeModel.setTable("courseTable");

 
    // QSqlQueryModel gradeQry;
    // gradeQry.setQuery("SELECT * FROM courseTable");

    for (int i = 0; i < gradeQry.rowCount(); i++) {
        currentCredit = gradeQry.record(i).value("Course_Credits").toInt();
        m_creditsSum += gradeQry.record(i).value("Course_Credits").toInt();
        qDebug() << "CREDITS.....= " << currentCredit;
        QString tempStrGrade = gradeQry.record(i).value("Course_Grade").toString();
        int tempIntGrade = 0;
        if (tempStrGrade == "A") {
            tempIntGrade = 4;

        } else if (tempStrGrade == "B") {
            tempIntGrade = 3;
        } else if (tempStrGrade == "C") {
            tempIntGrade = 2;
        } else if (tempStrGrade == "D") {
            tempIntGrade = 1;
        } else if (tempStrGrade == "F") {
            tempIntGrade = 0;
        } else {
            //create a highlighting function to highlight row where there is an incorrect input
            qDebug() << "INCORRECT INPUT, PLEASE REVIEW AND CORRECT";
        }
        qDebug() << "TEMP STR GRADE = " << tempStrGrade;
        qDebug() << "TEMP INT GRADE = " << tempIntGrade;
        m_qpiSum += (tempIntGrade * currentCredit);



    }

    m_GPA= float(m_qpiSum)/float(m_creditsSum);

    QString sGPA = QString::number(m_GPA, 'f' , 2);
    ui->label_GPA->setText(sGPA);
    qDebug() << "QPI SUM .....= " << m_qpiSum;
    qDebug() << "CREDITS SUM = " << m_creditsSum;
    qDebug() << "GPA.......................... = " << m_GPA;
    m_mydb.close();

}

void SecDialog::on_pushButton_add_clicked()
{
    QString className, classGrade;
    int classCredits;

    className=ui->lineEdit_className->text();
    classCredits=ui->lineEdit_classCredits->text().toInt();
    classGrade=ui->lineEdit_classGrade->text();
    
    addValues2(className, classCredits, classGrade);
    
    
    /*// addValues(className, classCredits, classGrade);


    //     //POST to table
    // QSqlQueryModel * modal = new QSqlQueryModel();
    // modal->setQuery("select * from coursesTable");
    // m_mydb.open();

    // ui->tableView_classList->setModel(modal);*/

    calcGPA();

}


void SecDialog::on_tableView_classList_activated(const QModelIndex &index)
{
    QString val=ui->tableView_classList->model()->data(index).toString();
    

    
    QSqlQuery qry;
    m_mydb.open();
    qry.prepare("SELECT * FROM coursesTable WHERE Course_Name='"+val+"' OR Course_Credits='"+val+"' OR Course_Grade='"+val+"'");
    
    
    if(qry.exec()) {
        while(qry.next()) {
            ui->lineEdit_className->setText(qry.value(0).toString());
            ui->lineEdit_classCredits->setText(qry.value(1).toString());
            ui->lineEdit_classGrade->setText(qry.value(2).toString());
            
        }
        m_mydb.close();
    } else {
        QMessageBox::critical(this, tr("error::"), qry.lastError().text());
    }
    
    qDebug() << "INDEX .....= " << index;
    // qDebug() << "&INDEX .....= " << &index;
    qDebug() << "INDEX.row() .....= " << index.row();
    
    m_currentSelection = index;
    
    qDebug() << "m_currentSelection .....= " << m_currentSelection;

}

void SecDialog::on_pushButton_exit_clicked()
{
    this->close();
    // login::connClose();
}


void SecDialog::on_pushButton_delete_clicked()
{
  /*//   int selectedRow = ui->tableView_classList->selectionModel()->currentIndex().row();
    

  //   qDebug() << "SELECTED ROW DELETE CLICKED = " << selectedRow;

  //   ui->tableView_classList->setSelectionBehavior(QAbstractItemView::SelectRows);
  //   ui->tableView_classList->setSelectionMode(QAbstractItemView::SingleSelection);
    
    
  //   m_mydb.open();
    
  //   QSqlTableModel modal;
    
  //   modal.setTable("coursesTable");
    
    
    
  //   modal.select();
    
  //   modal.removeRow(selectedRow);
    
  //   modal.submitAll();
  
  //   calcGPA(); */
    
    
    
    
    int selectedRow = ui->tableView_classList->selectionModel()->currentIndex().row();
    
    ui->tableView_classList->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_classList->setSelectionMode(QAbstractItemView::SingleSelection);
    
    m_mydb.open();
    
    QSqlTableModel *modal = new QSqlTableModel;
    
    
    modal->setTable("coursesTable");
    
    
    modal->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modal->select();
    
    modal->removeRow(selectedRow);
    
    modal->submitAll();
    
    QTableView *view = ui->tableView_classList;
    // QTableView *view = new QTableView;
    view->setModel(modal);
    // view->hideColumn(0); // don't show the ID
    
    view->show();
    
    calcGPA();


}


void SecDialog::on_pushButton_load_clicked()
{
    QSqlQueryModel * modal = new QSqlQueryModel();
    modal->setQuery("select * from coursesTable");
    m_mydb.open();
    // QTableView *view = new QTableView;
    ui->tableView_classList->setModel(modal);

    m_mydb.close();
    calcGPA();
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
 

        qDebug()<<"end";
        return true;


    } else {
        // QMessageBox::information(this, "Connection", "Database FAILED");
        return false;
    }


}









