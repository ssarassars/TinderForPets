#ifndef ADDCLIENTDIALOG_H
#define ADDCLIENTDIALOG_H

#include "Control.h"
#include <QMessageBox>
#include <QDialog>
#include "Client.h"
#include "DBHandler.h"

class Control;

namespace Ui {
class AddClientDialog;
}

class AddClientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddClientDialog(QWidget *parent = 0, Control *cntrl = 0);
    ~AddClientDialog();

private slots:
    /*
    Function   : done()
    Purpose    : adds new entry in the Client table to the database and to the view when OK button is clicked, with the parameters
    Parameters : type: int, okResponse
    */
    void done(int r);
    /*
    Function   : validateInput()
    Purpose    : checks user input in the text fields corresponding to valid attribute and throw error if invalid entry is attempted
    Parameters : type: int, okResponse
    Retunr: type: bool, true if all inputs are valid,
                        false if there are invalid entries
    */
    bool validatedInput();

private:
    Ui::AddClientDialog *ui;
    Control *cntrl;
};

#endif // ADDCLIENTDIALOG_H
