#ifndef STORE_H
#define STORE_H
#include "Animal.h"
#include <QDebug>
#include "DBHandler.h"
#include "AnimalTableModel.h"
#include "ClientTableModel.h"
#include "MatchTableModel.h"
#include "StaffCollection.h"
#include "DBQuery.h"
#include "ClientCollection.h"
#include "AnimalCollection.h"
#include "Constants.h"
#include <QMap>
#include "MatchingAlgorithm.h"

class Store: public QObject
{
    Q_OBJECT
public:
    Store(QObject *parent = 0);
    ~Store();
    /*
     * Function  : addAnimal
     * Purpose   : to add an animal to the database and the internal in memory vector of animals
     * Parameters: input:
                name, type: QString, name of animal entered by user
                age, type: QString, age range of animal entered by user
                gender, type: QString, gender of animal selected by user
                type, type: QString, species of animal selected by user
                size, type: QString, size of animal
                shedding, type: QString, how much the animal sheds
                cost, type: QString, how much would the animal cost to maintain
                timidity, type: QString, how timid is the animal
                sociability, type: QString, extent to which animal is willing to socialize
                aggression, type: QString, extent to which animal can be agressive
                obedience, type: QString, extent to which animal will listen to authority
                loyalty, type: QString, extent to which animal is typically loyal
                affection, type: QString, extent to which animal is willing to be affective
                activity, type: QString, extent to which animal is typically active
                excitability, type: QString, extent to which animal is excitable
                expressiveness, type: QString, animal's skill with expressing their needs
                trainingSuitability, type: QString, How effective training will be in altering the animal’s natural behaviour.
                currentTraining, type: QString, extent to which the animal has already been trained
                intelligence, type: QString, how smart the animal is - this affects its ability to perform tasks.
                apartmentCompatibility, type: QString, How well-suited the animal is to living in an apartment.
                timeCommitment,type: QString, how much time per day the animal will require in order to be satisfied.
                kidFriendliness, type: QString, rating of how well animal copes with children, selected by user

    */
    void addAnimal(QString name, QString type, QString gender, QString age, QString size,
                   QString shedding, QString cost, QString timidity,  QString sociability, QString aggression, QString obedience,
                   QString loyalty, QString affection, QString activity, QString excitability, QString expressiveness,
                   QString trainingSuitability, QString currentTraining, QString intelligence, QString apartmentCompatibility,
                   QString timeCommitment,QString kidFriendliness);

    /*
    Function   : editAnimal
    Purpose    : to edit an animal in the database and the AnimalCollection
    Parameters :
                input:
                id, type: int, ID number of animal to identify it
                name, type: QString, name of animal entered by user
                age, type: QString, age range of animal entered by user
                gender, type: QString, gender of animal selected by user
                type, type: QString, species of animal selected by user
                size, type: QString, size of animal
                shedding, type: QString, how much the animal sheds
                cost, type: QString, how much would the animal cost to maintain
                timidity, type: QString, how timid is the animal
                sociability, type: QString, extent to which animal is willing to socialize
                aggression, type: QString, extent to which animal can be agressive
                obedience, type: QString, extent to which animal will listen to authority
                loyalty, type: QString, extent to which animal is typically loyal
                affection, type: QString, extent to which animal is willing to be affective
                activity, type: QString, extent to which animal is typically active
                excitability, type: QString, extent to which animal is excitable
                expressiveness, type: QString, animal's skill with expressing their needs
                trainingSuitability, type: QString, How effective training will be in altering the animal’s natural behaviour.
                currentTraining, type: QString, extent to which the animal has already been trained
                intelligence, type: QString, how smart the animal is - this affects its ability to perform tasks.
                apartmentCompatibility, type: QString, How well-suited the animal is to living in an apartment.
                timeCommitment,type: QString, how much time per day the animal will require in order to be satisfied.
                kidFriendliness, type: QString, rating of how well animal copes with children, selected by user

    */
    void editAnimal(int id, QString name, QString gender, QString type, QString age, QString size,
                    QString shedding, QString cost, QString timidity,  QString sociability, QString aggression, QString obedience,
                    QString loyalty, QString affection, QString activity, QString excitability, QString expressiveness,
                    QString trainingSuitability, QString currentTraining, QString intelligence, QString apartmentCompatibility,
                    QString timeCommitment,QString kidFriendliness);
/*
     * Function  : addClient
     * Purpose   : to add a client to the database and the internal in memory vector of clients
     * Parameters: input:
                     name, type: QString, name of client entered by staff, passed to handler for database adding
                     address, type: QString, address of client entered by staff, passed to handler for database adding
                     phoneNo, type: QString, phone number entered by client
                     email, type: QString, email entered by client
    */
    void addClient(QString name, QString address, QString phoneNo, QString email);

    /*
         * Function  : editClient
         * Purpose   : to edit a client in the database and the ClientCollection
         * Parameters: input:
                         id, type: int, ID number of client to identify them
                         animalPrefType, type: QString, client's desired type of animal
                         address, type: QString, updated address of client
                         phoneNo, type: QString, updated phone number of client
                         email, type: QString, updated email address of client
        */
    void editClient(int id, QString name,QString address, QString animalPrefType, QString phoneNo, QString email,
                    QString agePref,
                    QString genderPref,QString sizePref,QString kidFriendlinessPref,
                    QString costPref,QString currTrainPref,QString intelligencePref,QString timeCommitPref,
                    QString sheddingPref,QString aptCompatibilityPref,QString trainSuitPref);

    void updateClientBigFive(int id, QVector<float> *testResults);
/*
     * Function  : getAnimalTableModel
     * Purpose   : to return animal table model
     * Returns    : type: AnimalTableModel, pointer to animal table model 
    */
    AnimalTableModel* getAnimalTableModel();
/*
     * Function  : getClientTableModel
     * Purpose   : to return client table model
     * Returns    : type: ClientTableModel, pointer to client table model
    */
    ClientTableModel* getClientTableModel();
    /*
         * Function  : getMatchTableModel
         * Purpose   : to return match table model
         * Returns    : type: MatchTableModel, pointer to match table model
        */
        MatchTableModel* getMatchTableModel();
    /* Function   : checkIfClientExists
     * Purpose    : to verify that the entered client user id is valid for logging in
     * Parameters : input: userID, type: int, the user id entered for logging in as cient
     * Returns    : type: bool, true if the userID is that of an existing client, false otherwise
    */
    bool checkIfClientExists(int userID);
    /* Function   : checkIfStaffExists
     * Purpose    : to verify that the entered staff user id is valid for logging in
     * Parameters : input: userID, type: int, the user id entered for logging in as staff
     * Returns    : type: bool, true if the userID is that of an existing staff member, false otherwise
    */
    bool checkIfStaffExists(int userID);
    /* Function   : getClientObjectgivenId
     * Purpose    : retrieve client object from client id from the client collection vector
     * Parameters : input: clietID, type: int, the client id
     * Returns    : type: Client*, client object
    */
    Client* getClientObjectgivenId(int userID);
    /* Function   : getAnimalObjectgivenId
     * Purpose    : retrieve animal object from animal id from the animal collection vector
     * Parameters : input: animalID, type: int, the animal id
     * Returns    : type: Animal*, animal object
    */
    Animal* getAnimalObjectgivenId(int animalID);
    /* Function   : tablePass
     * Purpose    : pass animal object to notify of update for the table view
     * Parameters : input: Animal object, type: Aniaml*, animal object
     * Returns    : type: Animal*, animal object
    */
    void tablePass(Animal* animal);

    /* Function   : clientScoreVectorMap
     * Purpose    : return client vector score of particular attribute from enum position of attributes order
     * Parameters : input: none
     * Returns    : type: float, client score
    */
    float clientScoreVectorMap(int clientID, int animalID, int position);
    /* Function   : animalScoreVectorMap
     * Purpose    : return animal vector score of particular attribute from enum position of attributes order
     * Parameters : input: none
     * Returns    : type: float, animal score
    */
    float animalScoreVectorMap(int clientID, int animalID, int position);
    /* Function   : finalMatchScoreMap
     * Purpose    : return final match score from match with client and animal IDs to be displayed to view
     * Parameters : input: none
     * Returns    : type: float, final match score from KM matrix entry
    */
    float finalMatchScoreMap(int clientID, int animalID);

signals:
    void updateSign(Animal*);
    void updateSignClient(Client*);

private:
    /*
    Function   : handlerPass
    Purpose    : sends animal information along to the DBHandler
    Parameters : input:
                 name, type: QString, name of animal entered by user, passed to handler for database adding
                 age, type: int, age of animal entered by user, passed to handler for database adding
                 gender, type: QString, gender of animal selected by user, passed to handler for database adding
                 type, type: QString, species of animal selected by user, passed to handler for database adding
                 kidfriendly, type: QString, rating of how well animal copes with children, selected by user, passed to handler
                                    for database adding
                 cost, type: QString, rating of how expensive animal is to maintain, selected by user, passed to handler
                             for database adding
                 disability, type: QString, disability (if any) suffered by animal, selected by user, passed to handler
                                   for database adding
                 shedding, type: QString, rating of how much animal sheds, selected by user, passed to handler for database
                                 adding
                 apartmentliving, type: QString, rating of how well the animal will cope with living in an apartment, selected by user,
                                        passed to handler for database adding
    */

    void handlerPass(QString name, QString type, QString gender, QString age, QString size,
                     QString shedding, QString cost, QString timidity,  QString sociability, QString aggression, QString obedience,
                     QString loyalty, QString affection, QString activity, QString excitability, QString expressiveness,
                     QString trainingSuitability, QString currentTraining, QString intelligence, QString apartmentCompatibility,
                     QString timeCommitment,QString kidFriendliness);
    /*
    Function   : handlerPass
    Purpose    : overloaded - sends client information along to the DBHandler
    Parameters : input:
                 name, type: QString, name of client entered by user, passed to handler for database adding
                 address, type: QString, address of client entered by user, passed to handler for database adding
                 phoneNo, type: int, phone number of client entered by user, passed to handler for database adding
    */
    void handlerPass(QString name, QString address, QString phoneNo, QString email);
    /*
    Function   : tablePass
    Purpose    : sends Animal object along to the animal model in order for
                 it to be added to the in-memory vector of animals
    Parameters :
                 input:
                 animal, type: Animal, passed to handler to add it to our QVector of all Animal objects in the database
    */
   // void tablePass(Animal* animal);
    /*
    Function   : tablePass
    Purpose    : overloaded - sends Client object along to the animal model in order for
                 it to be added to the in-memory vector of animals
    Parameters :
                 input:
                 client, type: Client, passed to handler to add it to our QVector of all Client objects in the database
    */
    void tablePass(Client* client);
    /*
    Function   : pullLatestAnimalID
    Purpose    : gets ID of latest animal in the database (so the View knows what the new Animal's ID is)
    Parameters :
                 output:
                 id, type: int, ID of newest animal in DB
    */
    int pullLatestAnimalID();
    /*
    Function   : pullLatestClientID
    Purpose    : gets ID of latest client in the database (so the View knows what the new Client's ID is)
    Parameters :
                 output:
                 id, type: int, ID of newest client in DB
    */
    int pullLatestClientID();
    AnimalTableModel *animalTableModel;
    ClientTableModel *clientTableModel;
    StaffCollection  *staffCollection;
    AnimalCollection *animalCollection;
    ClientCollection *clientCollection;
    MatchTableModel *matchTableModel;
    MatchingAlgorithm *matchingAlgo;
    //dbHandler could be passed to multiple models in the future
//    DBHandler *dbHandler;
    DBQuery *dbQuery;

};

#endif // STORE_H
