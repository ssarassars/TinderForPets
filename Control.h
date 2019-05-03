#ifndef CONTROL_H
#define CONTROL_H
#include <QApplication>
#include "QDebug"
#include "AnimalTableModel.h"
#include "DBHandler.h"
#include "Animal.h"
#include <QObject>
#include "Store.h"
#include "CuacsAppView.h"
#include "StoreControl.h"
#include "LoginControl.h"
class CuacsAppView;
class StoreControl;
class LoginControl;

class Control
{
public:
    Control();
    ~Control();
    /*
    Function   : viewAnimalList
    Purpose    : displays the animal management menu after the Manage Animals option is selected from the main menu
    Parameters : None
    */
    void viewAnimalList();
    /*
    Function   : viewClientList
    Purpose    : displays the client management menu after the Manage Clients option is selected from the main menu
    Parameters : None
    */
    void viewClientList();

    /*     * Function  : addAnimal
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
     * Function  : getModelClient
     * Purpose   : to return client table model
     * Returns    : type: ClientTableModel, pointer to client table model
    */
    ClientTableModel* getModelClient();
/*
     * Function  : getModelAnimal
     * Purpose   : to return animal table model
     * Returns    : type: AnimalTableModel, pointer to animal table model 
    */
    AnimalTableModel* getModelAnimal();
    /*
         * Function  : getModelMatch
         * Purpose   : to return match table model
         * Returns    : type: MatchTableModel, pointer to match table model
        */
     MatchTableModel* getModelMatch();

    /*
     * Function  : addClient
     * Purpose   : to add a client to the database and the internal in memory vector of clients
     * Parameters: input:
                     name, type: QString, name of client entered by user
                     address, type: QString, address of client entered by user

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
    void editClient(int id, QString name, QString address, QString animalPrefType, QString phoneNo, QString email,
                    QString agePref,
                    QString genderPref,QString sizePref,QString kidFriendlinessPref,
                    QString costPref,QString currTrainPref,QString intelligencePref,QString timeCommitPref,
                    QString sheddingPref,QString aptCompatibilityPref,QString trainSuitPref);

    /*
    Function   : updateClientBigFive
    Purpose    : passes the client's scores on the Big Five personality test to StoreControl
    Parameters :
                input:
                id, type: int, ID number of client to identify them
                testResults, type: QVector<float>, client's scores on the test

    */
    void updateClientBigFive(int id, QVector<float> *testResults);

    /* Function   : attemptLoginAsClient
     * Purpose    : to verify that the entered client user id is valid for logging in
     * Parameters : input: userID, type: int, the user id entered for logging in as client
     * Returns    : type: bool, true if the userID is that of an existing client, false otherwise
    */
    bool attemptLoginAsClient(int userID);

    /* Function   : attemptLoginAsStaff
     * Purpose    : to verify that the entered staff user id is valid for logging in
     * Parameters : input: userID, type: int, the user id entered for logging in as staff
     * Returns    : type: bool, true if the userID is that of an existing staff member, false otherwise
    */
    bool attemptLoginAsStaff(int userID);
    /* Function   : setStoreControl
     * Purpose    : to verify that the entered staff user id is valid for logging in
     * Parameters : input: userID, type: int, the user id entered for logging in as staff
     * Returns    : type: void
    */
    void setStoreControl (StoreControl *sc);
    /* Function   : getSelectedClientObject
     * Purpose    : to retreve client object give its ID
     * Parameters : input: userID, type: int, the client ID
     * Returns    : type: Client*, animal object corresponding to the userID input
    */
    Client* getSelectedClientObject(int userID);
    /* Function   : getSelectedAnimalObject
     * Purpose    : to retreve animal object give its ID
     * Parameters : input: userID, type: int, the user id entered for logging in as staff
     * Returns    : type: Animal*, animal object corresponding to the animalID input
    */
    Animal* getSelectedAnimalObject(int animalID);
    /* Function   : clientScoreVectorMap
     * Purpose    : return the client score from the vector
     * Parameters : input: clientID, type: int, the client id in match pair
     *                      animalID, type: int, the animal id in match pair
     *                      position, tyope: int, the position from enum order
     * Returns    : type: float, vector client score
    */
    float clientScoreVectorMap(int clientID, int animalID, int position);
    /* Function   : animalScoreVectorMap
     * Purpose    : return the animal score from the vector
     * Parameters : input: clientID, type: int, the client id in match pair
     *                      animalID, type: int, the animal id in match pair
     *                      position, tyope: int, the position from enum order
     * Returns    : type: float, vector animal score
    */
    float animalScoreVectorMap(int clientID, int animalID, int position);
    /* Function   : finalMatchScoreMap
     * Purpose    : return the final value match score matrix entry
     * Parameters : input: clientID, type: int, the client id in match pair
     *                      animalID, type: int, the animal id in match pair
     * Returns    : type: float, final match score
    */
    float finalMatchScoreMap(int clientID, int animalID);

private slots:
        //void update();
private:
    StoreControl *storeControl;
    LoginControl *loginControl;
    Store *petStore;
};

#endif // CONTROL_H
