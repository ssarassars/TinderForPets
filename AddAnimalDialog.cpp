#include "AddAnimalDialog.h"
#include "ui_AddAnimalDialog.h"

AddAnimalDialog::AddAnimalDialog(QWidget *parent, Control *cntrl) :
    QDialog(parent),
    ui(new Ui::AddAnimalDialog)
{
    ui->setupUi(this);
    this->cntrl = cntrl;
}

AddAnimalDialog::~AddAnimalDialog()
{
    delete ui;
}

bool AddAnimalDialog::validatedInput()
{
    if (ui->nameField->toPlainText().trimmed().isEmpty())
    {
        QMessageBox::warning(this,"Invalid Information","Name must be filled out.");
        return false;
    }
    else if (ui->ageOpt->currentText().trimmed().isEmpty())
    {
        QMessageBox::warning(this,"Invalid Information","Age must be selected!");
        return false;
    }
    else {
        return true;
    }
    return true;
}

void AddAnimalDialog::done(int response)
{
    if(QDialog::Accepted == response){
        if(validatedInput()){

            QString name = ui->nameField->toPlainText();
            QString age = ui->ageOpt->currentText();
            QString size = ui->sizeOpt->currentText();
            QString gender = ui->genderOpt->currentText();
            QString type = ui->typeOpt->currentText();
            QString kidFriendly = ui->kidOpt->currentText();
            QString obedience = ui->obedienceOpt->currentText();
            QString loyalty = ui->loyaltyOpt->currentText();
            QString affection = ui->affectionOpt->currentText();
            QString expressiveness = ui->expressivenessOpt->currentText();
            QString currentTraining = ui->currentTrainingOpt->currentText();
            QString intelligence = ui->intelligenceOpt->currentText();
            QString cost = ui->costOpt->currentText();
            QString shedding = ui->shedOpt->currentText();
            QString apartmentCompatibility = ui->apartmentOpt->currentText();
            QString excitability = ui->excitabilityOpt->currentText();
            QString timidity = ui->timidityOpt->currentText();
            QString commitment = ui->commitmentOpt->currentText();
            QString activity = ui->activityOpt->currentText();
            QString sociability = ui->sociabilityOpt->currentText();
            QString trainingSuitability = ui->trainingSuitOpt->currentText();
            QString aggression = ui->aggressionOpt->currentText();

            cntrl->addAnimal(name, type, gender, age, size,
                             shedding,  cost, timidity,  sociability, aggression, obedience,
                             loyalty, affection, activity, excitability, expressiveness,
                             trainingSuitability, currentTraining, intelligence, apartmentCompatibility,
                          commitment, kidFriendly);

            QDialog::done(response);
        }else{
            return;
        }
    }else{
        QDialog::done(response);
        return;
    }
}
