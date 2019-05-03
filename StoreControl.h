#ifndef STORECONTROL_H
#define STORECONTROL_H

#include "Store.h"
#include <QObject>


class StoreControl
{
public:
    StoreControl(Store* petStore=0);
    ~StoreControl();
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

    //REAL METHOD REAL METHOD
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

    void updateClientBigFive(int id, QVector<float> *testResults);

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
            /* Function   : getClientObjectgivenId
             * Purpose    : retrieve client object from client id from the client collection vector
             * Parameters : input: clietID, type: int, the client id
             * Returns    : type: Client*, client object
            */
        Client* getClientObjectwithID(int userID);
        /* Function   : getAnimalObjectgivenId
         * Purpose    : retrieve animal object from animal id from the animal collection vector
         * Parameters : input: animalID, type: int, the animal id
         * Returns    : type: Animal*, animal object
        */
        Animal* getAnimalObjectwithID(int animalID);
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

private:
        Store* petStore;

};

#endif // STORECONTROL_H
