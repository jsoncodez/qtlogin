#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QFileInfo>
#include <QDebug>
#include <vector>
#include <QModelIndex>
#include <QAbstractItemModel>
#include <QSqlTableModel>
#include <QSqlQueryModel>

// #include "login.h"

/*
 * TO DO:
 * HAVE A WAY TO SAVE AND BUILD OFF CONFIRMED GRADES TO MAKE SCENARIOS
-DELETE AND START FRESH?
-MODIFY, DELETE

- ONLY QUERY ONCE AND CLOSE THROUGHOUT CODE, only add to what is already present in member variables
    -trial and error of sql

-exit button

*/
namespace Ui {

class SecDialog;

    void addValues( QString Course_Name, int Course_Credits, QString Course_Grade);
    

}



class SecDialog : public QDialog
{
    Q_OBJECT


public:
    explicit SecDialog(QWidget *parent = nullptr);
    // explicit SecDialog(QWidget *parent = 0);
    ~SecDialog();
    void connClose();
    bool connOpen();
    
    void calcGPA();
    
    
private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_exit_clicked();

    void on_pushButton_load_clicked();


    void on_pushButton_delete_clicked();
    
    void on_tableView_classList_activated(const QModelIndex &index);
    // bool removeRows(int, int, const QModelIndex &parent);
    
    
private:
    Ui::SecDialog *ui;
    // QSqlDatabase *m_mydb;
    QSqlDatabase m_mydb;
    QString m_dbpath;
    int m_qpiSum = 0;
    int m_creditsSum = 0;
    float m_GPA = 0;
    QModelIndex m_currentSelection;

};

#endif // SECDIALOG_H
