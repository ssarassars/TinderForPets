#include "ClientCollection.h"

ClientCollection::ClientCollection(QVector<Client*> clientVector)
{
this->clientVector = clientVector;
}

ClientCollection::~ClientCollection()
{
     qDeleteAll(clientVector);
}

bool ClientCollection::checkIfClientExists(int userID)
{
    int currIndex = 0;
    int currID;
    while(currIndex < clientVector.size()){
        currID = clientVector[currIndex]->getID();
        if(currID == userID){
            return true;
        }
        ++currIndex;
    }
    return false;
}

Client* ClientCollection::getClientObjectWithId(int &rowIdSelected){
    for(Client* c: this->clientVector){
        if(c->getID()==rowIdSelected){
            return c;
        }
    }
    return NULL;
}


//USE THIS FOR EDITING
void ClientCollection::editClient(int id, QString name,QString address, QString animalPrefType, QString phoneNo, QString email,
                                  QString agePref,
                                  QString genderPref,QString sizePref,QString kidFriendlinessPref,
                                  QString costPref,QString currTrainPref,QString intelligencePref,QString timeCommitPref,
                                  QString sheddingPref,QString aptCompatibilityPref,QString trainSuitPref)
{

    QVectorIterator<Client*> i(clientVector);
    Client* currClient;
    while (i.hasNext()){
        currClient = i.next();
        if (currClient->getID() == id){
            currClient->setName(name);
            currClient->setAddress(address);
            currClient->setAnimalPrefType(animalPrefType);
            currClient->setPhoneNo(phoneNo);
            currClient->setEmail(email);

            currClient->setAgePref(agePref);
            currClient->setGenderPref(genderPref);
            currClient->setSizePref(sizePref);
            currClient->setKidFriendlyPref(kidFriendlinessPref);
            currClient->setCostPref(costPref);
            currClient->setCurrTrainingPref(currTrainPref);
            currClient->setIntelligencePref(intelligencePref);
            currClient->setTimeCommitPref(timeCommitPref);
            currClient->setSheddingPref(sheddingPref);
            currClient->setAptCompatibilityPref(aptCompatibilityPref);
            currClient->setTrainSuitabilityPref(trainSuitPref);
        }
    }


}
void ClientCollection::computeBigFiveOnClient(int id, QVector<float> *clientRes)
{

    QVectorIterator<Client*> i(clientVector);
    Client* currClient;
    while (i.hasNext()){
        currClient = i.next();
        if (currClient->getID() == id){
            currClient->computeBigFive(clientRes);
            break;
        }
    }
}

void ClientCollection::addToClientVector(Client* clientToAdd){
    this->clientVector.append(clientToAdd);
}
