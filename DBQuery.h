#ifndef DBQUERY_H
#define DBQUERY_H
#include <QSqlQuery>
#include <QWidget>
#include "DBHandler.h"
#include <QVector>
#include <QDebug>
#include "Animal.h"
#include "Client.h"
#include "Staff.h"
#include "Constants.h"

class DBHandler;

class DBQuery
{

public:
    DBQuery();
    ~DBQuery();
    QSqlQuery getTable(QString);
    QVector<Client*> getClientsFromDB();
    QVector<Animal*> getAnimalsFromDB();
    QVector<Staff*> getStaffFromDB();
    int getLatestAnimalID();
    int getLatestClientID();
    /*
    Function   : insertAnimalIntoTable
    Purpose    : inserts new animal attributes into animal table in database
    Parameters : input/output:
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
    void insertAnimalIntoTable(QString name, QString type, QString gender, QString age, QString size,
                               QString shedding, QString cost, QString timidity,  QString sociability, QString aggression, QString obedience,
                               QString loyalty, QString affection, QString activity, QString excitability, QString expressiveness,
                               QString trainingSuitability, QString currentTraining, QString intelligence, QString apartmentCompatibility,
                               QString timeCommitment,QString kidFriendliness);

    /*
    Function   : editAnimalInTable
    Purpose    : updates database entry for animal with given ID
    Parameters :
                input:
                id, type: int, ID number of animal so the DBQuery knows which row to modify
                input/output:
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
    void editAnimalInTable(int id,  QString name, QString gender, QString type, QString age, QString size,
                                    QString shedding, QString cost, QString timidity,  QString sociability, QString aggression, QString obedience,
                                    QString loyalty, QString affection, QString activity, QString excitability, QString expressiveness,
                                    QString trainingSuitability, QString currentTraining, QString intelligence, QString apartmentCompatibility,
                                    QString timeCommitment,QString kidFriendliness);

    /*
    Function   : insertClientIntoTable
    Purpose    : inserts new client attributes into client table in database
    Parameters : input/output:
                name, type: QString, name of client entered by user, passed to handler for database adding
                address, type: QString, address of client entered by user, passed to handler for database adding
                phoneNo, type: QString, phone number of client selected by user, passed to handler for database adding
                email, type: QString, email of client entered by user, passed to handler for database adding
    */
    void insertClientIntoTable(QString name, QString address, QString phoneNo, QString email);
    /*
    Function   : editClientInTable
    Purpose    : updates database entry for client with given ID
    Parameters :
                input:
                id, type: int, ID number of client so the DBQuery knows which row to modify
                input/output:
                name, type: QString, name of client entered by user, passed to handler for database adding
                address, type: QString, address of client entered by user, passed to handler for database adding
                phoneNo, type: QString, phone number of client selected by user, passed to handler for database adding
                email, type: QString, email of client entered by user, passed to handler for database adding
    */
    void editClientInTable(int id, QString name, QString address, QString animalPrefType, QString phoneNo, QString email,
                           QString agePref,
                           QString genderPref, QString sizePref,QString kidFriendlinessPref,
                           QString costPref,QString currTrainPref,QString intelligencePref,QString timeCommitPref,
                           QString sheddingPref,QString aptCompatibilityPref,QString trainSuitPref);

    /*
    Function   : editClientBigFive
    Purpose    : updates database entry for animal with given ID
    Parameters :
                input:
                id, type: int, ID number of client so the DBQuery knows which row to modify
                input/output:
                opennessToExp, type: QString, how receptive client is to new experiences
                conscientiousness, type: QString, how organized client is
                extraversion, type: QString, how sociable client is
                agreeableness, type: QString, client's compassion and understanding
                neuroticism, type: QString, client's propensity to be stressed
    */
    void editClientBigFive(int id, QString opennessToExp,QString conscientiousness, QString extraversion,
                                    QString agreeableness, QString neuroticism);


private:
    DBHandler *dbHandler;
};

#endif // DBQUERY_H
