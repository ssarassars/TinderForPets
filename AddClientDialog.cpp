#include "AddClientDialog.h"
#include "ui_AddClientDialog.h"
#include <QDebug>

AddClientDialog::AddClientDialog(QWidget *parent, Control *cntrl) :
    QDialog(parent),
    ui(new Ui::AddClientDialog)
{
    ui->setupUi(this);
    this->cntrl = cntrl;
}

AddClientDialog::~AddClientDialog()
{
    delete ui;
}

bool AddClientDialog::validatedInput()
{
    bool ok;
    ui->phoneField->toPlainText().toLong(&ok, 10);

    if (ui->nameField->toPlainText().trimmed().isEmpty())
    {
        QMessageBox::warning(this,"Invalid Information","Name must be filled out.");
        return false;
    }
    else if (ui->addressField->toPlainText().trimmed().isEmpty())
    {
        QMessageBox::warning(this,"Invalid Information","Address must be filled out.");
        return false;
    }
    else if (ui->phoneField->toPlainText().trimmed().isEmpty())
    {
        QMessageBox::warning(this,"Invalid Information","Phone number must be filled out.");
        return false;
    }else if (!(ui->phoneField->toPlainText().trimmed().isEmpty()) && ui->phoneField->toPlainText().trimmed().length() != 10)
    {
        QMessageBox::warning(this,"Invalid Information","Phone number must be 10 digits.");
        return false;
    }
    else if (!ok)
    {
        QMessageBox::warning(this,"Invalid Information","Phone number must be comprised of digits only.");
        return false;
    }else{
        return true;
    }
return true;
}

void AddClientDialog::done(int response)
{
    if(QDialog::Accepted == response){
        if(validatedInput()){

            QString name = ui->nameField->toPlainText();
            QString address = ui->addressField->toPlainText();
            QString phoneNo = ui->phoneField->toPlainText();
            QString email = ui->emailField->toPlainText();

            cntrl->addClient(name, address, phoneNo, email);

            QDialog::done(response);
        }else{
            return;
        }
    }else{
        QDialog::done(response);
        return;
    }
}
