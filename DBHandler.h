#ifndef DBANIMALHANDLER_H
#define DBANIMALHANDLER_H
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>
#include "Animal.h"
class DBHandler
{
public:

    ~DBHandler();
    /*
    Function   : getAnimalsTable
    Purpose    : gets query that returns the animal table from the database
    Parameters : output:
                 query, type: QSqlQuery, query with animal table
    */
//    QSqlQuery getAnimalsTable();
    /*
    Function   : getClientsTable
    Purpose    : gets query that returns the clients table from the database
    Parameters : output:
                 query, type: QSqlQuery, query with clients table
    */

//    QSqlQuery getClientsTable();

    /*
    Function   : getStaffTable
    Purpose    : gets query that returns the staff table from the database
    Parameters : output:
                 query, type: QSqlQuery, query with staff table
    */
//    QSqlQuery getStaffTable();
    /*
    Function   : getAnimalsTableColumnCount
    Purpose    : gets query that returns the animal table from the database and calculates the column count
    Parameters : output:
                 columnCount, type: int, number of columns in animal table
    */
    int getAnimalsTableColumnCount();
    /*
    Function   : getLatestAnimalID
    Purpose    : return the last animalID from the table
    Parameters : output:
                 animalID, type: int, last animal ID in table
    */
//    int getLatestAnimalID();
    /*
    Function   : getLatestClientID
    Purpose    : return the last clientID from the table
    Parameters : output:
                 clientID, type: int, last client ID in table
    */
//    int getLatestClientID();
    /*
//    Function   : insertAnimalIntoTable
//    Purpose    : inserts new animal attributes into animal table in database
//    Parameters : input/output:
//                name, type: QString, name of animal entered by user
//                age, type: QString, age range of animal entered by user
//                gender, type: QString, gender of animal selected by user
//                type, type: QString, species of animal selected by user
//                size, type: QString, size of animal
//                shedding, type: QString, how much the animal sheds
//                cost, type: QString, how much would the animal cost to maintain
//                timidity, type: QString, how timid is the animal
//                sociability, type: QString, extent to which animal is willing to socialize
//                aggression, type: QString, extent to which animal can be agressive
//                obedience, type: QString, extent to which animal will listen to authority
//                loyalty, type: QString, extent to which animal is typically loyal
//                affection, type: QString, extent to which animal is willing to be affective
//                activity, type: QString, extent to which animal is typically active
//                excitability, type: QString, extent to which animal is excitable
//                expressiveness, type: QString, animal's skill with expressing their needs
//                trainingSuitability, type: QString, How effective training will be in altering the animal’s natural behaviour.
//                currentTraining, type: QString, extent to which the animal has already been trained
//                intelligence, type: QString, how smart the animal is - this affects its ability to perform tasks.
//                apartmentCompatibility, type: QString, How well-suited the animal is to living in an apartment.
//                timeCommitment,type: QString, how much time per day the animal will require in order to be satisfied.
//                kidFriendliness, type: QString, rating of how well animal copes with children, selected by user

//    */
//    void insertAnimalIntoTable(QString name, QString type, QString gender, QString age, QString size,
//                               QString shedding, QString cost, QString timidity,  QString sociability, QString aggression, QString obedience,
//                               QString loyalty, QString affection, QString activity, QString excitability, QString expressiveness,
//                               QString trainingSuitability, QString currentTraining, QString intelligence, QString apartmentCompatibility,
//                               QString timeCommitment,QString kidFriendliness);
//    /*
//    Function   : insertClientIntoTable
//    Purpose    : inserts new client attributes into client table in database
//    Parameters : input/output:
//                name, type: QString, name of client entered by user, passed to handler for database adding
//                address, type: QString, address of client entered by user, passed to handler for database adding
//                phoneNo, type: QString, phone number of client selected by user, passed to handler for database adding
//    */
//    void insertClientIntoTable(QString name, QString address, QString phoneNo, QString email);
    /*
    Function   : lastError
    Purpose    : returns database error
    Parameters : output:
                 dbError type: QSqlError, database error
    */
    QSqlError lastError();
    /*
    Function   : getInstance
    Purpose    : returns database error
    Parameter  : input:
                    none
    Output     : output:
                    none
    */
    static DBHandler *getInstance();
    /*
    Function   : getDB
    Purpose    : returns database
    Parameters : none
    Return     : output:
                 type: QSqlDatabase& , reference to database
    */
    QSqlDatabase& getDB();

private:
    DBHandler();
    static DBHandler* instance;
    QSqlDatabase db;
};

#endif // DBANIMALHANDLER_H
