#ifndef EDITANIMALDIALOG_H
#define EDITANIMALDIALOG_H

#include "Control.h"
#include <QMessageBox>
#include <QDialog>
#include "Animal.h"
#include "DBHandler.h"

class Control;

namespace Ui {
class EditAnimalDialog;
}

class EditAnimalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditAnimalDialog(QWidget *parent = 0, Control *cntrl = 0, Animal *editedAnimal = 0);
    ~EditAnimalDialog();

signals:
    void editSignal();

private slots:
    /*
    Function   : on_buttonBox_accepted()
    Purpose    : confirms update to animal details
    Parameters : none
    */
    void on_buttonBox_accepted();

private:
    Ui::EditAnimalDialog *ui;
    Control *cntrl;
    Animal *editedAnimal;
};

#endif // EDITANIMALDIALOG_H
