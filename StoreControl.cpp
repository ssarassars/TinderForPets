//#include <QDebug>
#include "StoreControl.h"

StoreControl::StoreControl(Store *petStore)
{
    this->petStore=petStore;
}

StoreControl::~StoreControl(){

}

void StoreControl::addAnimal(QString name, QString type, QString gender, QString age, QString size,
                        QString shedding, QString cost, QString timidity,  QString sociability, QString aggression, QString obedience,
                        QString loyalty, QString affection, QString activity, QString excitability, QString expressiveness,
                        QString trainingSuitability, QString currentTraining, QString intelligence, QString apartmentCompatibility,
                        QString timeCommitment,QString kidFriendliness)
{
    petStore->addAnimal( name,  type,  gender,  age,  size,
                         shedding,  cost,  timidity,   sociability,  aggression,  obedience,
                         loyalty,  affection,  activity,  excitability,  expressiveness,
                         trainingSuitability,  currentTraining,  intelligence,  apartmentCompatibility,
                         timeCommitment, kidFriendliness);

}

void StoreControl::editAnimal(int id, QString name, QString gender, QString type, QString age, QString size,
                QString shedding, QString cost, QString timidity,  QString sociability, QString aggression, QString obedience,
                QString loyalty, QString affection, QString activity, QString excitability, QString expressiveness,
                QString trainingSuitability, QString currentTraining, QString intelligence, QString apartmentCompatibility,
                QString timeCommitment,QString kidFriendliness)
{
    petStore->editAnimal(id, name, gender, type, age, size,
                               shedding, cost, timidity, sociability, aggression, obedience,
                               loyalty, affection, activity, excitability, expressiveness,
                               trainingSuitability, currentTraining, intelligence, apartmentCompatibility,
                               timeCommitment, kidFriendliness);
}

void StoreControl::addClient(QString name, QString address, QString phoneNo, QString email)
{
    petStore->addClient(name, address, phoneNo, email);
}

void StoreControl::editClient(int id,QString name, QString address, QString animalPrefType, QString phoneNo, QString email,
                              QString agePref,
                              QString genderPref,QString sizePref,QString kidFriendlinessPref,
                              QString costPref,QString currTrainPref,QString intelligencePref,QString timeCommitPref,
                              QString sheddingPref,QString aptCompatibilityPref,QString trainSuitPref){
    petStore->editClient(id, name, address, animalPrefType,
                               phoneNo, email,  agePref,
                          genderPref, sizePref, kidFriendlinessPref,
                          costPref, currTrainPref, intelligencePref, timeCommitPref,
                          sheddingPref, aptCompatibilityPref, trainSuitPref);
}
void StoreControl::updateClientBigFive(int id, QVector<float> *testResults)
{
    qDebug()<<"in store control ";
    petStore->updateClientBigFive(id, testResults);
}

ClientTableModel* StoreControl::getModelClient()
{
    return petStore->getClientTableModel();
}
AnimalTableModel* StoreControl::getModelAnimal()
{
    return petStore->getAnimalTableModel();
}

MatchTableModel* StoreControl::getModelMatch()
{
    return petStore->getMatchTableModel();
}

Client* StoreControl::getClientObjectwithID(int userID){
    return petStore->getClientObjectgivenId(userID);
}

Animal* StoreControl::getAnimalObjectwithID(int animalID){
    return petStore->getAnimalObjectgivenId(animalID);
}

float StoreControl::clientScoreVectorMap(int clientID, int animalID, int position){

    return petStore->clientScoreVectorMap(clientID, animalID, position);

}
float StoreControl::animalScoreVectorMap(int clientID, int animalID, int position){

    return petStore->animalScoreVectorMap(clientID, animalID, position);

}

float StoreControl::finalMatchScoreMap(int clientID, int animalID){

    return petStore->finalMatchScoreMap(clientID, animalID);

}
