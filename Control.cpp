#include "Control.h"

Control::Control()
{
    petStore = new Store(NULL);
    this->storeControl = new StoreControl(petStore);
    this->loginControl = new LoginControl(petStore);


}
void Control::addAnimal(QString name, QString type, QString gender, QString age, QString size,
                        QString shedding, QString cost, QString timidity,  QString sociability, QString aggression, QString obedience,
                        QString loyalty, QString affection, QString activity, QString excitability, QString expressiveness,
                        QString trainingSuitability, QString currentTraining, QString intelligence, QString apartmentCompatibility,
                        QString timeCommitment,QString kidFriendliness)
{
    storeControl->addAnimal( name,  type,  gender,  age,  size,
                         shedding,  cost,  timidity,   sociability,  aggression,  obedience,
                         loyalty,  affection,  activity,  excitability,  expressiveness,
                         trainingSuitability,  currentTraining,  intelligence,  apartmentCompatibility,
                         timeCommitment, kidFriendliness);
}

//ONLY id is not allowed to be edited.
void Control::editAnimal(int id, QString name, QString gender, QString type, QString age, QString size,
                QString shedding, QString cost, QString timidity,  QString sociability, QString aggression, QString obedience,
                QString loyalty, QString affection, QString activity, QString excitability, QString expressiveness,
                QString trainingSuitability, QString currentTraining, QString intelligence, QString apartmentCompatibility,
                QString timeCommitment,QString kidFriendliness)
{
    storeControl->editAnimal(id, name, gender, type, age, size,
                               shedding, cost, timidity, sociability, aggression, obedience,
                               loyalty, affection, activity, excitability, expressiveness,
                               trainingSuitability, currentTraining, intelligence, apartmentCompatibility,
                               timeCommitment, kidFriendliness);
}

ClientTableModel* Control::getModelClient()
{
    return storeControl->getModelClient();
}

MatchTableModel* Control::getModelMatch()
{
    return storeControl->getModelMatch();
}

Client* Control::getSelectedClientObject(int userID){
    return storeControl->getClientObjectwithID(userID);
}

Animal* Control::getSelectedAnimalObject(int animalID){
    return storeControl->getAnimalObjectwithID(animalID);
}

AnimalTableModel* Control::getModelAnimal()
{
    return storeControl->getModelAnimal();
}
void Control::addClient(QString name, QString address, QString phoneNo, QString email)
{
    storeControl->addClient(name, address, phoneNo, email);
}

void Control::editClient(int id, QString name, QString address, QString animalPrefType, QString phoneNo, QString email,
                        QString agePref,
                        QString genderPref,QString sizePref,QString kidFriendlinessPref,
                        QString costPref,QString currTrainPref,QString intelligencePref,QString timeCommitPref,
                        QString sheddingPref,QString aptCompatibilityPref,QString trainSuitPref){

    storeControl->editClient(id, name,address, animalPrefType,
                               phoneNo, email, agePref,
                             genderPref,  sizePref, kidFriendlinessPref,
                             costPref, currTrainPref, intelligencePref, timeCommitPref,
                             sheddingPref, aptCompatibilityPref, trainSuitPref);
}
void Control::updateClientBigFive(int id, QVector<float> *testResults)
{
    storeControl->updateClientBigFive(id, testResults);
}

bool Control::attemptLoginAsClient(int userID)
{
    return loginControl->attemptLoginAsClient(userID);

}
bool Control::attemptLoginAsStaff(int userID)
{
    return loginControl->attemptLoginAsStaff(userID);

}

float Control::clientScoreVectorMap(int clientID, int animalID, int position){

    return storeControl->clientScoreVectorMap(clientID, animalID, position);

}
float Control::animalScoreVectorMap(int clientID, int animalID, int position){

    return storeControl->animalScoreVectorMap(clientID, animalID, position);

}

float Control::finalMatchScoreMap(int clientID, int animalID){

    return storeControl->finalMatchScoreMap(clientID, animalID);

}

void Control::setStoreControl(StoreControl* sc){
    storeControl = sc;
}

Control::~Control(){
    delete storeControl;
    delete loginControl;
    delete petStore;
}

