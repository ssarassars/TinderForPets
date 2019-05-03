#include "Store.h"

Store::Store(QObject *parent) : QObject(parent)
{
    //Example match client:animal IDs return from algorithm
//    QMap<int, int> matchMap;
//    matchMap.insert(1, 6);
//    matchMap.insert(2, 7);
//    matchMap.insert(6, 8);
//    matchMap.insert(7, 9);
//    matchMap.insert(8, 10);
//    matchMap.insert(9, 11);
//    matchMap.insert(10, 12);

    dbQuery = new DBQuery();
    QVector<Animal*> animalVector = dbQuery->getAnimalsFromDB();
    QVector<Client*> clientVector = dbQuery->getClientsFromDB();
    QVector<Staff*> staffVector = dbQuery->getStaffFromDB();
    clientTableModel = new ClientTableModel(clientVector, NULL);
    animalTableModel = new AnimalTableModel(animalVector, NULL);
    staffCollection = new StaffCollection(staffVector);
    clientCollection = new ClientCollection(clientVector);
    animalCollection = new AnimalCollection(animalVector);
    matchingAlgo = new MatchingAlgorithm(animalVector, clientVector);
    QMap<int, int> matchMap = matchingAlgo->getClientAnimalMap();
    matchTableModel = new MatchTableModel(matchMap, NULL);

    QObject::connect(this, SIGNAL(updateSign(Animal*)), animalTableModel, SLOT(update(Animal*)));
    QObject::connect(this, SIGNAL(updateSignClient(Client*)), clientTableModel, SLOT(update(Client*)));
}

Store::~Store(){
    delete dbQuery;
    delete animalTableModel;
    delete clientTableModel;
    delete staffCollection;
    delete clientCollection;
    delete animalCollection;
}

void Store::tablePass(Animal* animal)
{
    animalCollection->addToAnimalVector(animal);
    emit updateSign(animal);
}

void Store::tablePass(Client* client)
{
    clientCollection->addToClientVector(client);
    emit updateSignClient(client);
}

int Store::pullLatestAnimalID()
{
    return dbQuery->getLatestAnimalID();
}

int Store::pullLatestClientID()
{
    return dbQuery->getLatestClientID();
}

void Store::addAnimal(QString name, QString type, QString gender, QString age, QString size,
                      QString shedding, QString cost, QString timidity,  QString sociability, QString aggression, QString obedience,
                      QString loyalty, QString affection, QString activity, QString excitability, QString expressiveness,
                      QString trainingSuitability, QString currentTraining, QString intelligence, QString apartmentCompatibility,
                      QString timeCommitment,QString kidFriendliness)
{
    dbQuery->insertAnimalIntoTable(name,  type,  gender,  age,  size,
                                      shedding,  cost,  timidity,   sociability,  aggression,  obedience,
                                      loyalty,  affection,  activity,  excitability,  expressiveness,
                                      trainingSuitability,  currentTraining,  intelligence,  apartmentCompatibility,
                                      timeCommitment, kidFriendliness);

    int id = pullLatestAnimalID();

    Animal* animal = new Animal(id, name, type, gender,  age,  size,
                                shedding,  cost,  timidity,   sociability,  aggression,  obedience,
                                loyalty,  affection,  activity,  excitability,  expressiveness,
                                trainingSuitability,  currentTraining,  intelligence,  apartmentCompatibility,
                                timeCommitment, kidFriendliness);
    matchingAlgo->updateAnimalScore(animal);
    tablePass(animal);

    //tablePass adds the new Animal to the AnimalTableModel
}

void Store::editAnimal(int id, QString name, QString gender, QString type, QString age, QString size,
                QString shedding, QString cost, QString timidity,  QString sociability, QString aggression, QString obedience,
                QString loyalty, QString affection, QString activity, QString excitability, QString expressiveness,
                QString trainingSuitability, QString currentTraining, QString intelligence, QString apartmentCompatibility,
                QString timeCommitment,QString kidFriendliness)
{
    dbQuery->editAnimalInTable(id, name, gender, type, age, size,
                               shedding, cost, timidity, sociability, aggression, obedience,
                               loyalty, affection, activity, excitability, expressiveness,
                               trainingSuitability, currentTraining, intelligence, apartmentCompatibility,
                               timeCommitment, kidFriendliness);
    animalCollection->editAnimal(id, name, gender, type, age, size,
                                 shedding, cost, timidity, sociability, aggression, obedience,
                                 loyalty, affection, activity, excitability, expressiveness,
                                 trainingSuitability, currentTraining, intelligence, apartmentCompatibility,
                                 timeCommitment, kidFriendliness);
    matchingAlgo->updateAnimalScore(animalCollection->getAnimalObjectWithId(id));

}

void Store::addClient(QString name, QString address, QString phoneNo, QString email)
{
    dbQuery->insertClientIntoTable(name, address, phoneNo, email);
    //handlerPass is like passing a baton - takes the values here, and gives them to its own internal dbhandler, which in turn adds them to the SQL database

    int id = pullLatestClientID();

    Client* client = new Client(id, name, email, EMPTYENTRY, address, phoneNo);
    matchingAlgo->updateClientScore(client);
    tablePass(client);

    //tablePass adds the new Client to the ClientTableModel
}

void Store::editClient(int id, QString name, QString address, QString animalPrefType, QString phoneNo,
                       QString email, QString agePref,
                       QString genderPref,QString sizePref,QString kidFriendlinessPref,
                       QString costPref,QString currTrainPref,QString intelligencePref,QString timeCommitPref,
                       QString sheddingPref,QString aptCompatibilityPref,QString trainSuitPref){
    dbQuery->editClientInTable(id, name, address, animalPrefType,
                               phoneNo, email, agePref,
                               genderPref, sizePref, kidFriendlinessPref,
                               costPref, currTrainPref, intelligencePref, timeCommitPref,
                               sheddingPref, aptCompatibilityPref, trainSuitPref);

    clientCollection->editClient(id, name, address, animalPrefType,
                                 phoneNo, email, agePref,
                                 genderPref, sizePref, kidFriendlinessPref,
                                 costPref, currTrainPref, intelligencePref, timeCommitPref,
                                 sheddingPref, aptCompatibilityPref, trainSuitPref);
    Client* client = clientCollection->getClientObjectWithId(id) ;
    matchingAlgo->updateClientScore(client);
}
void Store::updateClientBigFive(int id, QVector<float> *testResults)

{
    clientCollection->computeBigFiveOnClient(id, testResults);
    Client* currClient = clientCollection->getClientObjectWithId(id);
    dbQuery->editClientBigFive(id, currClient->getOpennessToExp(), currClient->getConscientiousness(),
                               currClient->getExtraversion(),currClient->getAgreeableness(), currClient->getNeuroticism());
    matchingAlgo->updateClientScore(currClient);

}

AnimalTableModel* Store::getAnimalTableModel()
{
    return animalTableModel;
}

ClientTableModel* Store::getClientTableModel()
{
    return clientTableModel;
}

MatchTableModel* Store::getMatchTableModel()
{
    return matchTableModel;
}
bool Store::checkIfClientExists(int userID)
{
    return clientCollection->checkIfClientExists(userID);

}
bool Store::checkIfStaffExists(int userID)
{
    return staffCollection->checkIfStaffExists(userID);

}

Client* Store::getClientObjectgivenId(int userID)
{
    return clientCollection->getClientObjectWithId(userID);

}

Animal* Store::getAnimalObjectgivenId(int animalID)
{
    return animalCollection->getAnimalObjectWithId(animalID);

}

float Store::clientScoreVectorMap(int clientID, int animalID, int position){

    return matchingAlgo->clientScoreVectorMap(clientID, animalID, position);

}
float Store::animalScoreVectorMap(int clientID, int animalID, int position){

    return matchingAlgo->animalScoreVectorMap(clientID, animalID, position);

}

float Store::finalMatchScoreMap(int clientID, int animalID){

    return matchingAlgo->finalMatchScoreMap(clientID, animalID);

}

