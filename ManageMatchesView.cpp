#include "ManageMatchesView.h"
#include "ui_ManageMatchesView.h"

ManageMatchesView::ManageMatchesView(QWidget *parent, Control* cntrl, MatchTableModel *matchTableModel) :
    QMainWindow(parent),
    ui(new Ui::ManageMatchesView)
{

    ui->setupUi(this);
    this->cntrl= cntrl;
    this->matchTableModel = matchTableModel;
    setWindowState(Qt::WindowFullScreen);
    setWindowTitle("cuACS - Manage Animals");
    ui->matchesTableView->verticalHeader()->setVisible(false);
    ui->matchesTableView->resizeColumnsToContents();
    ui->matchesTableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:white}");
    ui->matchesTableView->setStyleSheet("QHeaderView::section{background-color:blue}");
    ui->matchesTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->matchesTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->matchesTableView->setShowGrid(false);
    ui->matchesTableView->setModel(matchTableModel);
    ui->matchesTableView->setColumnWidth(0,50);
    ui->matchesTableView->setColumnWidth(1,50);
    connect(ui->matchesTableView,SIGNAL(clicked(QModelIndex)), this, SLOT(on_matchesTableView_clicked(QModelIndex)));

    QMap<QString, QVector<QString>> opennessToExpAnimalPref = {

        {"Very High", {"Very Low Timidity", "Very High Activity", "Very High Excitability"}},
        {"High", {"Low Timidity", "High Activity", "High Excitability"}},
        {"Moderate", {"Moderate Timidity", "Moderate Obedience", "Moderate Activity", "Moderate Excitability"}},
        {"Low", {"High Obedience", "Low Activity"}},
        {"Very Low", {"Very High Obedience", "Very Low Activity"}},

    };

    QMap<QString, QVector<QString>> conscientiousnessAnimalPref = {

        {"Very High", {"Very High Obedience", "Very Low Activity"}},
        {"High", {"Low Activity", "High Obedience"}},
        {"Moderate", {"Moderate Obedience", "Moderate Activity", "Moderate Excitability"}},
        {"Low", {"High Loyalty", "Low Obedience", "High Excitability"}},
        {"Very Low", {"Very Low Obedience", "Very High Loyalty", "Very High Excitability"}},

    };

    QMap<QString, QVector<QString>> extraversionAnimalPref = {

        {"Very High", {"Very High Sociability", "Very High Excitability", "Very High Expressiveness"}},
        {"High", {"High Sociability", "High Excitability", "High Expressiveness"}},
        {"Moderate", {"Moderate Sociability", "Moderate Expressiveness", "Moderate Excitability"}},
        {"Low", {"High Sociability", "Low Excitability"}},
        {"Very Low", {"Very Low Sociability", "Very Low Excitability"}},

    };

    QMap<QString, QVector<QString>> agreeablenessAnimalPref = {

        {"Very High", {"Very High Aggression", "Very High Loyalty", "Very High Affection"}},
        {"High", {"High Aggression", "High Loyalty", "High Affection"}},
        {"Moderate", {"Moderate Timidity", "Moderate Sociability", "Moderate Aggression", "Moderate Loyalty", "Moderate Affection"}},
        {"Low", {"Low Timidity", "Low Sociability", "Low Affection"}},
        {"Very Low", {"Very Low Timidity", "Very Low Sociability", "Very Low Affection"}},

    };

    QMap<QString, QVector<QString>> neuroticismAnimalPref = {

        {"Very High", {"Very High Loyalty", "Very Low Aggression", "Very High Affection", "Very High Expressiveness"}},
        {"High", {"Low Aggression", "High Loyalty", "High Affection", "High Expressiveness"}},
        {"Moderate", {"Moderate Loyalty", "Moderate Aggression", "Moderate Affection", "Moderate Expressiveness"}},

    };

    this->neuroticismAnimalPref=neuroticismAnimalPref;
    this->agreeablenessAnimalPref=agreeablenessAnimalPref;
    this->extraversionAnimalPref=extraversionAnimalPref;
    this->agreeablenessAnimalPref=agreeablenessAnimalPref;
    this->conscientiousnessAnimalPref=conscientiousnessAnimalPref;
}

ManageMatchesView::~ManageMatchesView()
{
    delete ui;
}

void ManageMatchesView::on_matchesTableView_clicked(const QModelIndex &index)
{
    int selectedClientID = ui->matchesTableView->model()->index(index.row(),0).data().toInt();
    int selectedAnimalID = ui->matchesTableView->model()->index(index.row(),1).data().toInt();
    float finalMatchScore = cntrl->finalMatchScoreMap(selectedClientID, selectedAnimalID);
    Client* clientSelected = cntrl->getSelectedClientObject(selectedClientID);
    Animal* animalSelected = cntrl->getSelectedAnimalObject(selectedAnimalID);

    QString nameClient = clientSelected->getName();
    QString nameAnimal = animalSelected->getName();
    QString openToExperience = clientSelected->getOpennessToExp();
    QString conscientiousness = clientSelected->getConscientiousness();
    QString extraversion = clientSelected->getExtraversion();
    QString agreeableness = clientSelected->getAgreeableness();
    QString neuroticism = clientSelected->getNeuroticism();

    //DEMO
    QString clientIdealScore = QString::number(10.5);
    QString animalScore = QString::number(5.5);

    //QString matchScore = QString::number(finalMatchScore);

    //float check = cntrl->clientScoreVectorMap(selectedClientID, selectedAnimalID, TrainingSuitability);
    QString trainingSuitClient = QString::number(cntrl->clientScoreVectorMap(selectedClientID, selectedAnimalID, TrainingSuitability));
    QString trainingSuitnimal = QString::number(cntrl->animalScoreVectorMap(selectedClientID, selectedAnimalID, TrainingSuitability));

    QString currentTrainingClient = QString::number(cntrl->clientScoreVectorMap(selectedClientID, selectedAnimalID, CurrentTraining));
    QString currentTrainingAnimal = QString::number(cntrl->animalScoreVectorMap(selectedClientID, selectedAnimalID, CurrentTraining));

    QString costClient = QString::number(cntrl->clientScoreVectorMap(selectedClientID, selectedAnimalID, Cost));
    QString costAnimal = QString::number(cntrl->animalScoreVectorMap(selectedClientID, selectedAnimalID, Cost));

    QString intelligenceClient = QString::number(cntrl->clientScoreVectorMap(selectedClientID, selectedAnimalID, Intelligence));
    QString intelligenceAnimal = QString::number(cntrl->animalScoreVectorMap(selectedClientID, selectedAnimalID, Intelligence));

    QString timecommClient = QString::number(cntrl->clientScoreVectorMap(selectedClientID, selectedAnimalID, TimeCommitment));
    QString timeCommAnimal = QString::number(cntrl->animalScoreVectorMap(selectedClientID, selectedAnimalID, TimeCommitment));

    QString aptClient = QString::number(cntrl->clientScoreVectorMap(selectedClientID, selectedAnimalID, AptCompatibility));
    QString aptAnimal = QString::number(cntrl->animalScoreVectorMap(selectedClientID, selectedAnimalID, AptCompatibility));

    QString kidfriendlyClient = QString::number(cntrl->clientScoreVectorMap(selectedClientID, selectedAnimalID, Kidfriendliness));
    QString kidfriendlyAnimal = QString::number(cntrl->animalScoreVectorMap(selectedClientID, selectedAnimalID, Kidfriendliness));

    QString ageClient = QString::number(cntrl->clientScoreVectorMap(selectedClientID, selectedAnimalID, Age));
    QString ageAnimal = QString::number(cntrl->animalScoreVectorMap(selectedClientID, selectedAnimalID, Age));

    QString genderClient = QString::number(cntrl->clientScoreVectorMap(selectedClientID, selectedAnimalID, Gender));
    QString genderAnimal = QString::number(cntrl->animalScoreVectorMap(selectedClientID, selectedAnimalID, Gender));

    QString sizeClient = QString::number(cntrl->clientScoreVectorMap(selectedClientID, selectedAnimalID, Size));
    QString sizeAnimal = QString::number(cntrl->animalScoreVectorMap(selectedClientID, selectedAnimalID, Size));

    QString sheddingClient = QString::number(cntrl->clientScoreVectorMap(selectedClientID, selectedAnimalID, Shedding));
    QString sheddingAnimal = QString::number(cntrl->animalScoreVectorMap(selectedClientID, selectedAnimalID, Shedding));


    // QString trainingSuit = clientSelected->getTrainSuitabilityPref().compare("TBA")==0 ? ui->trainSuitPara->setText("Client Ideal Animal Score: " + clientIdealScore + ("         Animal Score: " + animalScore)) : ui->trainSuitLabel->setText("");
   QString trainingSuit = clientSelected->getTrainSuitabilityPref();
           if(trainingSuit.compare("TBA")!=0){
               ui->trainSuitLabel->setText("<b>Training Suitability</b>");
               ui->trainSuitPara->setText("Client Ideal Animal Score: " + trainingSuitClient + ("         Animal Score: " + trainingSuitnimal));
           }else{
               //ui->trainSuitLabel->setText("");
               ui->trainSuitPara->setText("Not Applicable");
           }
    QString currentTraining = clientSelected->getCurrTrainingPref();
            if(currentTraining.compare("TBA")!=0) {
                  ui->currTrainLabel->setText("<b>Current Training</b>");
                   ui->currTrainPara->setText("Client Ideal Animal Score: " + currentTrainingClient + ("         Animal Score: " + currentTrainingAnimal));
            }else{
                   //ui->currTrainLabel->setText("");
                   ui->currTrainPara->setText("Not Applicable.");
            }
    QString cost = clientSelected->getCostPref();
            if(cost.compare("TBA")!=0){
                ui->costLabel->setText("<b>Cost<b>");
                   ui->costPara->setText("Client Ideal Animal Score: " + costClient + ("         Animal Score: " + costAnimal));
            }else{
                   //ui->costLabel->setText("");
                   ui->costPara->setText("Not Applicable.");
            }
    QString intelligence = clientSelected->getTimeCommitPref();
            if(intelligence.compare("TBA")!=0){
                ui->intelligenceLabel->setText("<b>Intelligence</b>");
                   ui->intelligencePara->setText("Client Ideal Animal Score: " + intelligenceClient + ("         Animal Score: " + intelligenceAnimal));
             }else{
                   //ui->intelligenceLabel->setText("");
                   ui->intelligencePara->setText("Not Applicable.");
             }
    QString timeCommitment = clientSelected->getTimeCommitPref();
            if(timeCommitment.compare("TBA")!=0){
                ui->timeCommLabel->setText("<b>Time Commitment</b>");
                   ui->timeCommPara->setText("Client Ideal Animal Score: " + timecommClient + ("         Animal Score: " + timeCommAnimal));
             }else{
                   //ui->timeCommLabel->setText("");
                   ui->timeCommPara->setText("Not Applicable");
             }
    QString apartmentCompt = clientSelected->getAptCompatibilityPref();
                  if(apartmentCompt.compare("TBA")!=0){
                      ui->aptCompatLabel->setText("<b>Apartment Compatibility</b>");
                    ui->aptCompPara->setText("Client Ideal Animal Score: " + aptClient + ("         Animal Score: " + aptAnimal));
                 }else{
                    //ui->aptCompatLabel->setText("");
                    ui->aptCompPara->setText("Not Applicable.");
                 }
    QString kidFriendliness = clientSelected->getKidFriendlyPref();
                if(kidFriendliness.compare("TBA")!=0){
                    ui->kidFriendlyLabel->setText("<b>Kid Friendliness</b>");
                    ui->kidFriendlyPara->setText("Client Ideal Animal Score: " + kidfriendlyClient + ("         Animal Score: " + kidfriendlyAnimal));
                }else{
                    //ui->kidFriendlyLabel->setText("");
                    ui->kidFriendlyPara->setText("Not Applicable.");
                }
    QString age = clientSelected->getAgePref();
                if(age.compare("TBA")!=0){
                    ui->ageLabel->setText("<b>Age</b>");
                    ui->agePara->setText("Client Ideal Animal Score: " + ageClient + ("         Animal Score: " + ageAnimal));
                }else{
                    //ui->ageLabel->setText("");
                    ui->agePara->setText("Not Applicable.");
                }
    QString gender = clientSelected->getGenderPref();
                if(gender.compare("TBA")!=0){
                    ui->genderLabel->setText("<b>Gender</b>");
                    ui->genderPara->setText("Client Ideal Animal Score: " + genderClient + ("         Animal Score: " + genderAnimal));
                }else{
                   // ui->genderLabel->setText("");
                    ui->genderPara->setText("Not Applicable.");
                }
    QString size = clientSelected->getSizePref();
                if(size.compare("TBA")!=0){
                    ui->sizeLabel->setText("<b>Size</b>");
                    ui->sizePara->setText("Client Ideal Animal Score: " + sizeClient + ("         Animal Score: " + sizeAnimal));
                }else{
                    // ui->sizeLabel->setText("");
                    ui->sizePara->setText("Not Applicable.");
                }
    QString shedding = clientSelected->getSheddingPref();
                if(shedding.compare("TBA")!=0){
                    ui->sheddingLabel->setText("<b>Shedding</b>");
                    ui->sheddingPara->setText("Client Ideal Animal Score: " + sheddingClient + ("         Animal Score: " + sheddingAnimal));
                }else{
                    // ui->sizeLabel->setText("");
                    ui->sheddingPara->setText("Not Applicable.");
                }


    ui->displayClientName->setText(nameClient);
    ui->paraClient->setText("<b>From the Big Five Personality Test, we know </b>" + nameClient + "<b> has: </b>");
    ui->paraAnimalPersonality->setText("<b>Therefore, </b>" + nameClient + "'s <b>ideal compatible pet is matched using: </b>");

    ui->displayAnimalName->setText(nameAnimal);
    ui->displayMatchScore->setNum(finalMatchScore);
    ui->rangeOpentoExp->setText(openToExperience);
    ui->rangeConscientiousness->setText(conscientiousness);
    ui->rangeExtraversion->setText(extraversion);
    ui->rangeAgreeableness->setText(agreeableness);
    ui->rangeNeuroticism->setText(neuroticism);

    QString timidityClient = QString::number(cntrl->clientScoreVectorMap(selectedClientID, selectedAnimalID, Timidity));
    QString timidityAnimal = QString::number(cntrl->animalScoreVectorMap(selectedClientID, selectedAnimalID, Timidity));

    QString sociabilityClient = QString::number(cntrl->clientScoreVectorMap(selectedClientID, selectedAnimalID, Sociability));
    QString sociabilityAnimal = QString::number(cntrl->animalScoreVectorMap(selectedClientID, selectedAnimalID, Sociability));

    QString aggressionClient = QString::number(cntrl->clientScoreVectorMap(selectedClientID, selectedAnimalID, Aggression));
    QString aggressionAnimal = QString::number(cntrl->animalScoreVectorMap(selectedClientID, selectedAnimalID, Aggression));

    QString obedienceClient = QString::number(cntrl->clientScoreVectorMap(selectedClientID, selectedAnimalID, Obedience));
    QString obedienceAnimal = QString::number(cntrl->animalScoreVectorMap(selectedClientID, selectedAnimalID, Obedience));

    QString loyaltyClient = QString::number(cntrl->clientScoreVectorMap(selectedClientID, selectedAnimalID, Loyalty));
    QString loyaltyAnimal = QString::number(cntrl->animalScoreVectorMap(selectedClientID, selectedAnimalID, Loyalty));

    QString affectionClient = QString::number(cntrl->clientScoreVectorMap(selectedClientID, selectedAnimalID, Affection));
    QString affectionAnimal = QString::number(cntrl->animalScoreVectorMap(selectedClientID, selectedAnimalID, Affection));

    QString activityClient = QString::number(cntrl->clientScoreVectorMap(selectedClientID, selectedAnimalID, Activity));
    QString activityAnimal = QString::number(cntrl->animalScoreVectorMap(selectedClientID, selectedAnimalID, Activity));

    QString excitabilityClient = QString::number(cntrl->clientScoreVectorMap(selectedClientID, selectedAnimalID, Excitability));
    QString excitabilityAnimal = QString::number(cntrl->animalScoreVectorMap(selectedClientID, selectedAnimalID, Excitability));

    QString expresivenessClient = QString::number(cntrl->clientScoreVectorMap(selectedClientID, selectedAnimalID, Expressive));
    QString expressivenessAnimal = QString::number(cntrl->animalScoreVectorMap(selectedClientID, selectedAnimalID, Expressive));

    ui->timidityPara->setText("As determined by attributes " + openToExperience + " Openness to Experience and " + agreeableness + " Agreeableness.");
    ui->sociabilityPara->setText("As determined by " + extraversion + " Extraversion and " + agreeableness + " Agreeableness.");
    ui->aggressionPara->setText("As determined by " + agreeableness + " Agreeableness and " + neuroticism + " Neuroticism.");
    ui->obediencePara->setText("As determined by attributes " + openToExperience + " Openness to Experience and " + conscientiousness + " Conscientiousness.");
    ui->loyaltyPara->setText("As determined by attributes " + conscientiousness + " Conscientiousness, " + agreeableness + " Agreeableness and " + neuroticism + " Neuroticism.");
    ui->affectionPara->setText("As determined by attributes " + agreeableness + " Agreeableness and " + neuroticism + " Neuroticism.");
    ui->activityPara->setText("As determined by attributes " + openToExperience + " Openness to Experience and " + conscientiousness + " Conscientiousness.");
    ui->excitabilityPara->setText("As determined by attributes " + openToExperience + " Openness to Experience, " + conscientiousness + " Conscientiousness and " + extraversion + " Extraversion.");
    ui->expressivenessPara->setText("As determined by attributes " + extraversion + " Extraversion and " + neuroticism + " Neuroticism.");

    ui->timidityScore->setText("Client Ideal Animal Score: " + timidityClient + ("         Animal Score: " + timidityAnimal));
    ui->sociabilityScore->setText("Client Ideal Animal Score: " + sociabilityClient + ("         Animal Score: " + sociabilityAnimal));
    ui->aggressionScore->setText("Client Ideal Animal Score: " + aggressionClient + ("         Animal Score: " + aggressionAnimal));
    ui->obedienceScore->setText("Client Ideal Animal Score: " + obedienceClient + ("         Animal Score: " + obedienceAnimal));
    ui->loyaltyScore->setText("Client Ideal Animal Score: " + loyaltyClient + ("         Animal Score: " + loyaltyAnimal));
    ui->affectionScore->setText("Client Ideal Animal Score: " + affectionClient + ("         Animal Score: " + affectionAnimal));
    ui->activityScore->setText("Client Ideal Animal Score: " + activityClient + ("         Animal Score: " + activityAnimal));
    ui->excitabilityScore->setText("Client Ideal Animal Score: " + excitabilityClient + ("         Animal Score: " + excitabilityAnimal));
    ui->expressivenessScore->setText("Client Ideal Animal Score: " + expresivenessClient + ("         Animal Score: " + expressivenessAnimal));

}
