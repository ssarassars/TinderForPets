#ifndef EDITCLIENTDIALOG_H
#define EDITCLIENTDIALOG_H

#include <QDialog>
#include "Control.h"
#include "Client.h"
#include <QMessageBox>
#include <QDebug>
#include <QComboBox>
#include "Constants.h"
#include <QVector>
#include <QHash>
#include <QHashIterator>
class Control;

namespace Ui {
class EditClientDialog;
}

class EditClientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditClientDialog(QWidget *parent = 0,Control *cntrl = 0, Client *clientToEdit = 0);
    ~EditClientDialog();

private slots:
    /*
    Function   : on_buttonBox_accepted
    Purpose    : confirms update to client details
    Parameters : none
    */
    void on_okButton_accepted();

    /*
    Function   : on_bigFiveButton_clicked
    Purpose    : displays Big Five personality test
    Parameters : none
    */
    void on_bigFiveButton_clicked();

    /*
    Function   : on_bigFiveButton_clicked
    Purpose    : submits Big Five personality test results
    Parameters : none
    */
    void on_submitButton_clicked();

    /*
    Function   : on_bigFiveButton_clicked
    Purpose    : cancels Big Five personality test
    Parameters : none
    */
    void on_cancelButtonBigFive_clicked();

private:
    /*
    Function   : getTestScoresFromUI
    Purpose    : stores client's test results
    Parameters : input: testRes, type: QVector<float>, the storage data for the user's test results
    */
    void getTestScoresFromUI(QVector<float> *testRes);


    Ui::EditClientDialog *ui;
    Control *cntrl;
    Client *clientToEdit;
};

#endif // EDITCLIENTDIALOG_H


