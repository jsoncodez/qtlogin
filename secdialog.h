#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QFileInfo>
#include <QDebug>
// #include "login.h"


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



private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_exit_clicked();

    void on_pushButton_load_clicked();

private:
    Ui::SecDialog *ui;
    // QSqlDatabase *m_mydb;
    QSqlDatabase m_mydb;
    QString m_dbpath;

};

#endif // SECDIALOG_H
