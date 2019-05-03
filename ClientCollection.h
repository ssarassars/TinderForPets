#ifndef CLIENTCOLLECTION_H
#define CLIENTCOLLECTION_H
#include "Client.h"
#include <QVector>
#include <QDebug>

class ClientCollection
{
public:
    ClientCollection(QVector<Client*> clientVector);
     ~ClientCollection();
    /*
    Function   : checkIfClientExists
    Purpose    : scans client table in database to determine if specified client exists
    Parameters : input :
                 userID, type: int, used to specify which client is being searched for
                 output:
                 type, bool: true if client exists, false if not
    */
    bool checkIfClientExists(int userID);
    /*
    Function   : getClientObjectWithId
    Purpose    : retrieves and returns specified client object
    Parameters : input :
                 rowIdSelected, type: int, used to find client
                 output:
                 c, type, Client: the requested client
    */
    Client* getClientObjectWithId(int &rowIdSelected);
    /*
    Function   : editClient
    Purpose    : to edit a client in the ClientCollection (basic attributes and matching preferences)
    Parameters :
                input:
                id, type: int, ID number of client to identify them
                name, type: QString, name of client
                address, type: QString, address of client
                animalPrefType, type: QString, animal species preferred by client
                phoneNo, type: QString, client's phone number
                email, type: QString, client's email address
                agePref, type: QString, animal age range preferred by client
                genderPref, type: QString, animal gender preferred by client
                sizePref, type: QString, size of animal client prefers
                sheddingPref, type: QString, how much the client would prefer the animal sheds
                costPref, type: QString, how much would the client prefer the animal cost to maintain
                trainSuitPref, type: QString, how effective the client would prefer training to be in altering the animal’s natural behaviour.
                currTrainPref, type: QString, extent to which the client would prefer the animal has already been trained
                intelligencePref, type: QString, how smart the client would prefer the animal to be
                aptCompatibilityPref, type: QString, how well-suited the client would prefer the animal is to living in an apartment.
                timeCommitPref, type: QString, how much time per day the client wants the animal to require in order to be satisfied.
                kidFriendlinessPref, type: QString, how well the client would like the animal to cope with children

    */
    void editClient(int id, QString name, QString address, QString animalPrefType, QString phoneNo, QString email,
                    QString agePref,
                    QString genderPref,QString sizePref,QString kidFriendlinessPref,
                    QString costPref,QString currTrainPref,QString intelligencePref,QString timeCommitPref,
                    QString sheddingPref,QString aptCompatibilityPref,QString trainSuitPref);
    /*
    Function   : computeBigFiveOnClient
    Purpose    : to compute the client's scores on the Big Five personality test
    Parameters :
                input:
                id, type: int, ID number of client to identify them
                testResults, type: QVector<float>, client's scores on the test

    */
    void computeBigFiveOnClient(int id, QVector<float> *testResults);
    /*
    Function   : addToClientVector
    Purpose    : to add a client to the ClientCollection's vector
    Parameters :
                input:
                clientToAdd, type: Client, animal being added

    */
    void addToClientVector(Client* clientToAdd);
private:
    QVector<Client*> clientVector;
};

#endif // CLIENTCOLLECTION_H
