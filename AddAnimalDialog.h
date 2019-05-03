#ifndef ADDANIMALDIALOG_H
#define ADDANIMALDIALOG_H

#include "Control.h"
#include <QMessageBox>
#include <QDialog>
#include "Animal.h"
#include "DBHandler.h"

class Control;

namespace Ui {
class AddAnimalDialog;
}

class AddAnimalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddAnimalDialog(QWidget *parent = 0, Control *cntrl = 0);
    ~AddAnimalDialog();

private slots:
    /*
    Function   : done()
    Purpose    : adds new entry in the Animal table to the database and to the view when OK button is clicked, with the parameters 
    Parameters : type: int, okResponse
    */
    void done(int);
    /*
    Function   : validateInput()
    Purpose    : checks user input in the text fields corresponding to valid attribute and throw error if invalid entry is attempted
    Parameters : type: int, okResponse
    Retunr: type: bool, true if all inputs are valid,
                        false if there are invalid entries
    */
    bool validatedInput();

private:
    Ui::AddAnimalDialog *ui;
    Control *cntrl;
};

#endif // ADDANIMALDIALOG_H
