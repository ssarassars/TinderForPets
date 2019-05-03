#include "EditClientDialog.h"
#include "ui_EditClientDialog.h"

EditClientDialog::EditClientDialog(QWidget *parent,Control *cntrl, Client *client) :
    QDialog(parent),
    ui(new Ui::EditClientDialog)
{
    ui->setupUi(this);
    this->cntrl = cntrl;
    this->clientToEdit = client;
    ui->phoneField->setText(client->getPhoneNo());
    ui->addressField->setText(client->getAddress());
    ui->nameField->setText(client->getName());
    ui->emailField->setText(client->getEmail());
    ui->neuroDisplay->setText(client->getNeuroticism());
    ui->conscienDisplay->setText(client->getConscientiousness());
    ui->agreeDisplay->setText(client->getAgreeableness());
    ui->extraversionDisplay->setText(client->getExtraversion());
    ui->opennessDisplay->setText(client->getOpennessToExp());

    ui->stackedWidgetOverall->setCurrentIndex(0);

    //if big five filled then use widget 1 (to not allow for retaking the test)
    //else use widget 0
    if(client->bigFiveComplete()){
       ui->stackedWBigFive->setCurrentIndex(1);
    }else{
       ui->stackedWBigFive->setCurrentIndex(0);
    }


    //map between combo and corresponding client attributes

    QHash<QComboBox*, QString> comboAttrMap;

    comboAttrMap[ui->typeOpt] = client->getAnimalPrefType();
    comboAttrMap[ui->ageOpt] = client->getAgePref();
    comboAttrMap[ui->genderOpt]= client->getGenderPref();
    comboAttrMap[ui->sizeOpt] = client->getSizePref();
    comboAttrMap[ui->kidOpt]= client->getKidFriendlyPref();
    comboAttrMap[ui->costOpt]= client->getCostPref();
    comboAttrMap[ui->currentTrainingOpt] = client->getCurrTrainingPref();
    comboAttrMap[ui->intelligenceOpt] = client->getIntelligencePref();
    comboAttrMap[ui->commitmentOpt]= client->getTimeCommitPref();
    comboAttrMap[ui->shedOpt]= client->getSheddingPref();
    comboAttrMap[ui->apartmentOpt] = client->getAptCompatibilityPref();
    comboAttrMap[ui->trainingSuitOpt]= client->getTrainSuitabilityPref();

    QHashIterator<QComboBox*, QString> i(comboAttrMap);
    while (i.hasNext()) {
        i.next();
        int index = i.key()->findText(i.value());
        if(index >= 0)
            i.key()->setCurrentIndex(index);
    }


}

EditClientDialog::~EditClientDialog()
{
    delete ui;
}

void EditClientDialog::on_okButton_accepted()
{
    bool ok;
    ui->phoneField->toPlainText().toLong(&ok, 10);

    if (ui->nameField->toPlainText().trimmed().isEmpty())
    {
        QMessageBox::warning(this,"Invalid Information","Name must be filled out.");
    }
    else if (ui->addressField->toPlainText().trimmed().isEmpty())
    {
        QMessageBox::warning(this,"Invalid Information","Address must be filled out.");
    }
    else if (ui->phoneField->toPlainText().trimmed().isEmpty())
    {
        QMessageBox::warning(this,"Invalid Information","Phone number must be filled out.");
    }
    else if (ui->phoneField->toPlainText().trimmed().length() != 10)
    {
        QMessageBox::warning(this,"Invalid Information","Phone number must be filled out.");
    }
    else if (!ok)
    {
        QMessageBox::warning(this,"Invalid Information","Phone number must be comprised of digits.");
    }
    else {
        QString name = ui->nameField->toPlainText();
        QString address = ui->addressField->toPlainText();
        QString phoneNo = ui->phoneField->toPlainText();
        QString email = ui->emailField->toPlainText();
        QString agePref = ui->ageOpt->currentText();
        QString genderPref = ui->genderOpt->currentText();
        QString animalType = ui->typeOpt->currentText();
        QString sizePref = ui->sizeOpt->currentText();
        QString kidFriendlinessPref = ui->kidOpt->currentText();
        QString costPref = ui->costOpt->currentText();
        QString currTrainPref = ui->currentTrainingOpt->currentText();
        QString intelligencePref = ui->intelligenceOpt->currentText();
        QString timeCommitPref = ui->commitmentOpt->currentText();
        QString sheddingPref = ui->shedOpt->currentText();
        QString aptCompatibilityPref = ui->apartmentOpt->currentText();
        QString trainSuitPref = ui->trainingSuitOpt->currentText();

        cntrl->editClient(this->clientToEdit->getID(), name, address, animalType, phoneNo, email,
                          agePref,
                          genderPref, sizePref, kidFriendlinessPref,
                          costPref, currTrainPref, intelligencePref, timeCommitPref,
                          sheddingPref, aptCompatibilityPref, trainSuitPref);


    }
}

void EditClientDialog::on_bigFiveButton_clicked()
{
    //switch to big five stacked widget
    ui->stackedWidgetOverall->setCurrentIndex(1);
}

void EditClientDialog::getTestScoresFromUI(QVector<float> *testRes){
    QComboBox* entries[] = { ui->comboBox_1,ui->comboBox_2, ui->comboBox_3,
                           ui->comboBox_4, ui->comboBox_5, ui->comboBox_6,
                           ui->comboBox_7, ui->comboBox_8, ui->comboBox_9,
                           ui->comboBox_10, ui->comboBox_11, ui->comboBox_12,
                           ui->comboBox_13, ui->comboBox_14, ui->comboBox_15,
                           ui->comboBox_16, ui->comboBox_17, ui->comboBox_18,
                           ui->comboBox_19, ui->comboBox_20, ui->comboBox_21,
                           ui->comboBox_22, ui->comboBox_23, ui->comboBox_24,
                           ui->comboBox_25, ui->comboBox_26, ui->comboBox_27,
                           ui->comboBox_28, ui->comboBox_29, ui->comboBox_30,
                           ui->comboBox_31, ui->comboBox_32, ui->comboBox_33,
                           ui->comboBox_34, ui->comboBox_35, ui->comboBox_36,
                           ui->comboBox_37, ui->comboBox_38, ui->comboBox_39,
                           ui->comboBox_40, ui->comboBox_41, ui->comboBox_42,
                           ui->comboBox_43, ui->comboBox_44};
    for(int i=0; i<44 ; i++){
        testRes->append(float(entries[i]->currentText().toInt()));
    }
}

void EditClientDialog::on_submitButton_clicked()
{
    ui->stackedWidgetOverall->setCurrentIndex(0);
    QVector<float> testResults = QVector<float>();
    getTestScoresFromUI(&testResults);
    cntrl->updateClientBigFive(clientToEdit->getID(), &testResults);
    ui->neuroDisplay->setText(this->clientToEdit->getNeuroticism());
    ui->conscienDisplay->setText(this->clientToEdit->getConscientiousness());
    ui->agreeDisplay->setText(this->clientToEdit->getAgreeableness());
    ui->extraversionDisplay->setText(this->clientToEdit->getExtraversion());
    ui->opennessDisplay->setText(this->clientToEdit->getOpennessToExp());
    ui->stackedWBigFive->setCurrentIndex(1);
}

void EditClientDialog::on_cancelButtonBigFive_clicked()
{
    ui->stackedWidgetOverall->setCurrentIndex(0);
    ui->stackedWBigFive->setCurrentIndex(0);
}
