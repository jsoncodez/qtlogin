#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QFileInfo>
#include <QDebug>

namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecDialog(QWidget *parent = nullptr);
    ~SecDialog();

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_exit_clicked();

private:
    Ui::SecDialog *ui;
};

#endif // SECDIALOG_H
