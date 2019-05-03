#include "DBHandler.h"

DBHandler* DBHandler::instance = 0;

DBHandler::DBHandler()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../COMP_3004/Data/cuACSDatabase.db");
    if(!db.open())
        qDebug()<<"Database not open!";
        //possibly give user notification of error through GUI
}
DBHandler* DBHandler::getInstance(){
    if (!instance){
        instance = new DBHandler;
    }
    return instance;
}

QSqlDatabase& DBHandler::getDB(){
    return db;
}

//QSqlQuery DBHandler::getStaffTable()
//{
//    QSqlQuery query;
//    query.exec("select * from Staff");
//    return query;
//}
//QSqlQuery DBHandler::getAnimalsTable()
//{
//    QSqlQuery query;
//    query.exec("select * from Animals");
//    return query;
//}

//QSqlQuery DBHandler::getClientsTable()
//{
//    QSqlQuery query;
//    query.exec("select * from Clients");
//    return query;
//}
//int DBHandler::getLatestAnimalID()
//{
//    QSqlQuery query;
//    query.prepare("SELECT id FROM Animals ORDER BY id DESC LIMIT 1;");
//    query.exec();
//    query.first();
//    return query.value(0).toInt();
//}
//int DBHandler::getLatestClientID()
//{
//    QSqlQuery query;
//    query.prepare("SELECT id FROM Clients ORDER BY id DESC LIMIT 1;");
//    query.exec();
//    query.first();
//    return query.value(0).toInt();
//}

DBHandler::~DBHandler()
{
    db.close();

}
QSqlError DBHandler::lastError()
{
    return db.lastError();
}
//void DBHandler::insertAnimalIntoTable(QString name, QString type, QString gender, QString age, QString size,
//                                      QString shedding, QString cost, QString timidity,  QString sociability, QString aggression, QString obedience,
//                                      QString loyalty, QString affection, QString activity, QString excitability, QString expressiveness,
//                                      QString trainingSuitability, QString currentTraining, QString intelligence, QString apartmentCompatibility,
//                                      QString timeCommitment,QString kidFriendliness){

//    QSqlQuery query;
//    query.prepare("INSERT INTO Animals( name, type, gender,  age,  size, "
//                  "shedding,  cost,  timidity,   sociability,  aggression,  obedience,"
//                  "loyalty,  affection,  activity,  excitability,  expressiveness,"
//                  "trainingSuitability,  currentTraining,  intelligence,  apartmentCompatibility,"
//                  "timeCommitment, kidFriendliness )"
//                  "VALUES ( :name, :type, :gender,  :age,  :size, "
//                  ":shedding,  :cost,  :timidity,   :sociability,  :aggression,  :obedience,"
//                  ":loyalty,  :affection,  :activity,  :excitability,  :expressiveness,"
//                  ":trainingSuitability,  :currentTraining,  :intelligence,  :apartmentCompatibility,"
//                  ":timeCommitment, :kidFriendliness)");

//    //HYPHENATED ATTRIBUTES: must be QUOTED in the insert statement and CANNOT EXIST as part of the values statement
//    query.bindValue(":name", name);
//    query.bindValue(":type", type);
//    query.bindValue(":gender", gender);
//    query.bindValue(":age", age);
//    query.bindValue(":size", size);
//    query.bindValue(":shedding", shedding);
//    query.bindValue(":cost", cost);
//    query.bindValue(":timidity", timidity);
//    query.bindValue(":sociability", sociability);
//    query.bindValue(":aggression", aggression);
//    query.bindValue(":obedience", obedience);
//    query.bindValue(":loyalty", loyalty);
//    query.bindValue(":affection", affection);
//    query.bindValue(":activity", activity);
//    query.bindValue(":excitability", excitability);
//    query.bindValue(":expressiveness", expressiveness);
//    query.bindValue(":trainingSuitability", trainingSuitability);
//    query.bindValue(":currentTraining", currentTraining);
//    query.bindValue(":intelligence", intelligence);
//    query.bindValue(":apartmentCompatibility", apartmentCompatibility);
//    query.bindValue(":timeCommitment", timeCommitment);
//    query.bindValue(":kidFriendliness", kidFriendliness);

//    query.exec();
//    //qDebug()<<query.lastError()<<endl;
//}
//void DBHandler::insertClientIntoTable(QString name, QString address, QString phoneNo, QString email)
//{
//    QSqlQuery query;
//    query.prepare("INSERT INTO Clients(name, animalPrefType, address, phoneNo, email)"
//                  "VALUES (:name, :animalPrefType, :address, :phoneNo, :email)");
//    query.bindValue(":name", name);
//    query.bindValue(":animalPrefType", "TBA");
//    query.bindValue(":address", address);
//    query.bindValue(":phoneNo", phoneNo);
//    query.bindValue(":email", email);

//    query.exec();
//    //qDebug()<<query.lastError()<<endl;
//}
