#include "EditAnimalDialog.h"
#include "ui_EditAnimalDialog.h"

//DEMO CLASS DEMO CLASS

EditAnimalDialog::EditAnimalDialog(QWidget *parent, Control *cntrl, Animal *editedAnimal):
    QDialog(parent),
    ui(new Ui::EditAnimalDialog)
{
    ui->setupUi(this);
    this->cntrl = cntrl;
    this->editedAnimal = editedAnimal;
    ui->nameValue->setText(editedAnimal->getName());
    ui->idValue->setNum(editedAnimal->getID());
    for (int index = 0; index < ui->sizeOpt->count(); index++){
        if(ui->sizeOpt->itemText(index) == editedAnimal->getSize()){
                ui->sizeOpt->setCurrentIndex(index);
        }
    }
    for (int index = 0; index < ui->genderOpt->count(); index++){
        if(ui->genderOpt->itemText(index) == editedAnimal->getGender()){
                ui->genderOpt->setCurrentIndex(index);
        }
    }
    for (int index = 0; index < ui->typeOpt->count(); index++){
        if(ui->typeOpt->itemText(index) == editedAnimal->getType()){
                ui->typeOpt->setCurrentIndex(index);
        }
    }
    for (int index = 0; index < ui->ageOpt->count(); index++){
        if(ui->ageOpt->itemText(index) == editedAnimal->getAge()){
                ui->ageOpt->setCurrentIndex(index);
        }
    }
    for (int index = 0; index < ui->costOpt->count(); index++){
        if(ui->costOpt->itemText(index) == editedAnimal->getCost()){
                ui->costOpt->setCurrentIndex(index);
        }
    }
    for (int index = 0; index < ui->kidFriendlyopt->count(); index++){
        if(ui->kidFriendlyopt->itemText(index) == editedAnimal->getKidfriendliness()){
                ui->kidFriendlyopt->setCurrentIndex(index);
        }
    }
    for (int index = 0; index < ui->obedienceOpt->count(); index++){
        if(ui->obedienceOpt->itemText(index) == editedAnimal->getObedience()){
                ui->obedienceOpt->setCurrentIndex(index);
        }
    }
    for (int index = 0; index < ui->loyaltyOpt->count(); index++){
        if(ui->loyaltyOpt->itemText(index) == editedAnimal->getLoyalty()){
                ui->loyaltyOpt->setCurrentIndex(index);
        }
    }
    for (int index = 0; index < ui->affectionOpt->count(); index++){
        if(ui->affectionOpt->itemText(index) == editedAnimal->getAffection()){
                ui->affectionOpt->setCurrentIndex(index);
        }
    }
    for (int index = 0; index < ui->expressiveOpt->count(); index++){
        if(ui->expressiveOpt->itemText(index) == editedAnimal->getExpressiveness()){
                ui->expressiveOpt->setCurrentIndex(index);
        }
    }
    for (int index = 0; index < ui->trainingOpt->count(); index++){
        if(ui->trainingOpt->itemText(index) == editedAnimal->getCurrentTraining()){
                ui->trainingOpt->setCurrentIndex(index);
        }
    }
    for (int index = 0; index < ui->timeComOpt->count(); index++){
        if(ui->timeComOpt->itemText(index) == editedAnimal->getTimeCommitment()){
                ui->timeComOpt->setCurrentIndex(index);
        }
    }
    for (int index = 0; index < ui->sheddingOpt->count(); index++){
        if(ui->sheddingOpt->itemText(index) == editedAnimal->getShedding()){
                ui->sheddingOpt->setCurrentIndex(index);
        }
    }
    for (int index = 0; index < ui->intelligenceOpt->count(); index++){
        if(ui->intelligenceOpt->itemText(index) == editedAnimal->getIntelligence()){
                ui->intelligenceOpt->setCurrentIndex(index);
        }
    }
    for (int index = 0; index < ui->apartmentComOpt->count(); index++){
        if(ui->apartmentComOpt->itemText(index) == editedAnimal->getApartmentCompatibility()){
                ui->apartmentComOpt->setCurrentIndex(index);
        }
    }
    for (int index = 0; index < ui->excitabilityOpt->count(); index++){
        if(ui->excitabilityOpt->itemText(index) == editedAnimal->getExcitability()){
                ui->excitabilityOpt->setCurrentIndex(index);
        }
    }
    for (int index = 0; index < ui->timidityOpt->count(); index++){
        if(ui->timidityOpt->itemText(index) == editedAnimal->getTimidity()){
                ui->timidityOpt->setCurrentIndex(index);
        }
    }
    for (int index = 0; index < ui->activityopt->count(); index++){
        if(ui->activityopt->itemText(index) == editedAnimal->getActivity()){
                ui->activityopt->setCurrentIndex(index);
        }
    }
    for (int index = 0; index < ui->sociabilityOpt->count(); index++){
        if(ui->sociabilityOpt->itemText(index) == editedAnimal->getSociability()){
                ui->sociabilityOpt->setCurrentIndex(index);
        }
    }
    for (int index = 0; index < ui->aggressionOpt->count(); index++){
        if(ui->aggressionOpt->itemText(index) == editedAnimal->getAggression()){
                ui->aggressionOpt->setCurrentIndex(index);
        }
    }
    for (int index = 0; index < ui->trainisingSuitOpt->count(); index++){
        if(ui->trainisingSuitOpt->itemText(index) == editedAnimal->getTrainingSuitability()){
                ui->trainisingSuitOpt->setCurrentIndex(index);
        }
    }

}

EditAnimalDialog::~EditAnimalDialog()
{
    delete ui;
}

void EditAnimalDialog::on_buttonBox_accepted()
{
    int id = editedAnimal->getID();
    QString name = ui->nameValue->toPlainText();
    QString gender = ui->genderOpt->currentText();
    QString type = ui->typeOpt->currentText();
    QString age = ui->ageOpt->currentText();
    QString size = ui->sizeOpt->currentText();
    QString cost = ui->costOpt->currentText();
    QString kidFriendliness = ui->kidFriendlyopt->currentText();
    QString obedience = ui->obedienceOpt->currentText();
    QString loyalty = ui->loyaltyOpt->currentText();
    QString affection = ui->affectionOpt->currentText();
    QString expressiveness = ui->expressiveOpt->currentText();
    QString currentTraining = ui->trainingOpt->currentText();
    QString intelligence = ui->intelligenceOpt->currentText();
    QString timeCommitment = ui->timeComOpt->currentText();
    QString shedding = ui->sheddingOpt->currentText();
    QString apartmentCompatibility = ui->apartmentComOpt->currentText();
    QString excitability = ui->excitabilityOpt->currentText();
    QString timidity = ui->timidityOpt->currentText();
    QString activity = ui->activityopt->currentText();
    QString sociability = ui->sociabilityOpt->currentText();
    QString trainingSuitability = ui->trainisingSuitOpt->currentText();
    QString aggression = ui->aggressionOpt->currentText();

    emit editSignal();

    cntrl->editAnimal(id, name, gender, type, age, size,
                      shedding, cost, timidity, sociability, aggression, obedience,
                      loyalty, affection, activity, excitability, expressiveness,
                      trainingSuitability, currentTraining, intelligence, apartmentCompatibility,
                      timeCommitment, kidFriendliness);
}
