#include "DBQuery.h"

DBQuery::DBQuery()
{
    dbHandler = DBHandler::getInstance();
}

QSqlQuery DBQuery::getTable(QString tableName){
    QSqlQuery query;
    query.exec("select * from " + tableName);
    return query;
}

DBQuery::~DBQuery()
{
}

QVector<Animal*> DBQuery::getAnimalsFromDB(){
    QVector<Animal*> animalVector;
    QSqlQuery query;
    query = getTable("Animals");
    while(query.next()){
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        QString type = query.value(2).toString();
        QString gender = query.value(3).toString();
        QString age = query.value(4).toString();
        QString size = query.value(5).toString();
        QString shedding = !query.value(6).toString().isEmpty() ? query.value(6).toString() : "";
        QString timidity = !query.value(7).toString().isEmpty() ? query.value(7).toString() : "";
        QString sociability = !query.value(8).toString().isEmpty() ? query.value(8).toString() : "";
        QString aggression = !query.value(9).toString().isEmpty() ? query.value(9).toString() : "";
        QString obedience = !query.value(10).toString().isEmpty() ? query.value(10).toString() : "";
        QString loyalty = !query.value(11).toString().isEmpty() ? query.value(11).toString() : "";
        QString affection = !query.value(12).toString().isEmpty() ? query.value(12).toString() : "";
        QString excitability = !query.value(13).toString().isEmpty() ? query.value(13).toString() : "";
        QString expressiveness = !query.value(14).toString().isEmpty() ? query.value(14).toString() : "";
        QString trainingSuitability = !query.value(15).toString().isEmpty() ? query.value(15).toString() : "";
        QString currentTraining = !query.value(16).toString().isEmpty() ? query.value(16).toString() : "";
        QString intelligence = !query.value(17).toString().isEmpty() ? query.value(17).toString() : "";
        QString cost = !query.value(18).toString().isEmpty() ? query.value(18).toString() : "";
        QString timeCommitment = !query.value(19).toString().isEmpty() ? query.value(19).toString() : "";
        QString apartmentCompatibility = !query.value(20).toString().isEmpty() ? query.value(20).toString() : "";
        QString kidFriendliness = !query.value(21).toString().isEmpty() ? query.value(21).toString() : "";
        QString activity = !query.value(22).toString().isEmpty() ? query.value(22).toString() : "";


        animalVector<< new Animal (id, name, type, gender,  age,  size,
                        shedding,  cost,  timidity,   sociability,  aggression,  obedience,
                        loyalty,  affection,  activity,  excitability,  expressiveness,
                        trainingSuitability,  currentTraining,  intelligence,  apartmentCompatibility,
                        timeCommitment, kidFriendliness);
    }
    return animalVector;
}
QVector<Client*> DBQuery::getClientsFromDB()
{
    QSqlQuery query;
    query = getTable("Clients");
    QVector<Client*> clientVector;

    while(query.next()){
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        QString animalPrefType = query.value(2).toString();
        QString address = query.value(3).toString();
        QString phoneNo = query.value(4).toString();
        QString email = query.value(5).toString();
        QString agePref = query.value(6).toString();
        QString genderPref = query.value(7).toString();
        QString sizePref = query.value(8).toString();
        QString kidFriendlinessPref = query.value(9).toString();
        QString costPref = query.value(10).toString();
        QString currTrainPref = query.value(11).toString();
        QString intelligencePref = query.value(12).toString();
        QString timeCommitPref = query.value(13).toString();
        QString sheddingPref = query.value(14).toString();
        QString aptCompatibilityPref = query.value(15).toString();
        QString trainSuitPref = query.value(16).toString();
        QString opennessToExp = query.value(17).toString();
        QString conscientiousness = query.value(18).toString();
        QString extraversion  = query.value(19).toString();
        QString agreeableness = query.value(20).toString();
        QString neuroticism = query.value(21).toString();

        clientVector << new Client(id, name, email, animalPrefType, address, phoneNo,
                                   opennessToExp,  conscientiousness,
                                   extraversion, agreeableness, neuroticism, agePref,
                                   genderPref, sizePref, kidFriendlinessPref,
                                   costPref, currTrainPref, intelligencePref, timeCommitPref,
                                   sheddingPref, aptCompatibilityPref, trainSuitPref);
    }
    return clientVector;
}

QVector<Staff*> DBQuery::getStaffFromDB()
{
    QSqlQuery query;
    query = getTable("Staff");
    QVector<Staff*> staffVector;

    //query = this->dbQuery->getTable(tableName);

    while(query.next()){
        int id = query.value(0).toInt();
        staffVector<< new Staff(id);
    }
    return staffVector;
}

int DBQuery::getLatestAnimalID()
{
    QSqlQuery query;
    query.prepare("SELECT id FROM Animals ORDER BY id DESC LIMIT 1;");
    query.exec();
    query.first();
    return query.value(0).toInt();
}
int DBQuery::getLatestClientID()
{
    QSqlQuery query;
    query.prepare("SELECT id FROM Clients ORDER BY id DESC LIMIT 1;");
    query.exec();
    query.first();
    return query.value(0).toInt();
}

void DBQuery::insertAnimalIntoTable(QString name, QString type, QString gender, QString age, QString size,
                                      QString shedding, QString cost, QString timidity,  QString sociability, QString aggression, QString obedience,
                                      QString loyalty, QString affection, QString activity, QString excitability, QString expressiveness,
                                      QString trainingSuitability, QString currentTraining, QString intelligence, QString apartmentCompatibility,
                                      QString timeCommitment,QString kidFriendliness){

    QSqlQuery query;
    query.prepare("INSERT INTO Animals( name, type, gender,  age,  size, "
                  "shedding,  cost,  timidity,   sociability,  aggression,  obedience,"
                  "loyalty,  affection,  activity,  excitability,  expressiveness,"
                  "trainingSuitability,  currentTraining,  intelligence,  apartmentCompatibility,"
                  "timeCommitment, kidFriendliness )"
                  "VALUES ( :name, :type, :gender,  :age,  :size, "
                  ":shedding,  :cost,  :timidity,   :sociability,  :aggression,  :obedience,"
                  ":loyalty,  :affection,  :activity,  :excitability,  :expressiveness,"
                  ":trainingSuitability,  :currentTraining,  :intelligence,  :apartmentCompatibility,"
                  ":timeCommitment, :kidFriendliness)");

    //HYPHENATED ATTRIBUTES: must be QUOTED in the insert statement and CANNOT EXIST as part of the values statement
    query.bindValue(":name", name);
    query.bindValue(":type", type);
    query.bindValue(":gender", gender);
    query.bindValue(":age", age);
    query.bindValue(":size", size);
    query.bindValue(":shedding", shedding);
    query.bindValue(":cost", cost);
    query.bindValue(":timidity", timidity);
    query.bindValue(":sociability", sociability);
    query.bindValue(":aggression", aggression);
    query.bindValue(":obedience", obedience);
    query.bindValue(":loyalty", loyalty);
    query.bindValue(":affection", affection);
    query.bindValue(":activity", activity);
    query.bindValue(":excitability", excitability);
    query.bindValue(":expressiveness", expressiveness);
    query.bindValue(":trainingSuitability", trainingSuitability);
    query.bindValue(":currentTraining", currentTraining);
    query.bindValue(":intelligence", intelligence);
    query.bindValue(":apartmentCompatibility", apartmentCompatibility);
    query.bindValue(":timeCommitment", timeCommitment);
    query.bindValue(":kidFriendliness", kidFriendliness);

    query.exec();
    //qDebug()<<query.lastError()<<endl;
}

//REAL METHOD (ALL ATTRIBUTES)
void DBQuery::editAnimalInTable(int id, QString name, QString gender, QString type, QString age, QString size,
                                QString shedding, QString cost, QString timidity,  QString sociability, QString aggression, QString obedience,
                                QString loyalty, QString affection, QString activity, QString excitability, QString expressiveness,
                                QString trainingSuitability, QString currentTraining, QString intelligence, QString apartmentCompatibility,
                                QString timeCommitment,QString kidFriendliness){
    QSqlQuery query;
    query.prepare("UPDATE Animals "
                  "SET name=:name,  gender=:gender, type=:type, age=:age,  size=:size,"
                  "shedding=:shedding,  cost=:cost,  timidity=:timidity,   sociability=:sociability,  aggression=:aggression,  obedience=:obedience,"
                  "loyalty=:loyalty,  affection=:affection,  activity=:activity,  excitability=:excitability,  expressiveness=:expressiveness,"
                  "trainingSuitability=:trainingSuitability,  currentTraining=:currentTraining,  intelligence=:intelligence,  apartmentCompatibility=:apartmentCompatibility,"
                  "timeCommitment=:timeCommitment, kidFriendliness=:kidFriendliness "
                  "WHERE id=:id");
    query.bindValue(":name", name);
    query.bindValue(":gender", gender);
    query.bindValue(":type", type);
    query.bindValue(":age", age);
    query.bindValue(":size", size);
    query.bindValue(":shedding", shedding);
    query.bindValue(":cost", cost);
    query.bindValue(":timidity", timidity);
    query.bindValue(":sociability", sociability);
    query.bindValue(":aggression", aggression);
    query.bindValue(":obedience", obedience);
    query.bindValue(":loyalty", loyalty);
    query.bindValue(":affection", affection);
    query.bindValue(":activity", activity);
    query.bindValue(":excitability", excitability);
    query.bindValue(":expressiveness", expressiveness);
    query.bindValue(":trainingSuitability", trainingSuitability);
    query.bindValue(":currentTraining", currentTraining);
    query.bindValue(":intelligence", intelligence);
    query.bindValue(":apartmentCompatibility", apartmentCompatibility);
    query.bindValue(":timeCommitment", timeCommitment);
    query.bindValue(":kidFriendliness", kidFriendliness);

    query.bindValue(":id", id);

    query.exec();
    //qDebug()<<query.lastError()<<endl;
}

void DBQuery::insertClientIntoTable(QString name, QString address, QString phoneNo, QString email)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Clients(name, animalPrefType, address, phoneNo, email,"
                  "opennessToExp, conscientiousness,"
                  "extraversion, agreeableness, neuroticism,"
                  "agePref,genderPref, sizePref,"
                  "kidFriendlinessPref, costPref,"
                  "currTrainPref, intelligencePref, timeCommitPref,"
                  "sheddingPref, aptCompatibilityPref,trainSuitPref ) "
                  "VALUES (:name, :animalPrefType, :address, :phoneNo, :email,"
                  ":opennessToExp, :conscientiousness,"
                  ":extraversion, :agreeableness, :neuroticism,"
                  ":agePref,:genderPref, :sizePref,"
                  ":kidFriendlinessPref, :costPref,"
                  ":currTrainPref, :intelligencePref, :timeCommitPref,"
                  ":sheddingPref, :aptCompatibilityPref,:trainSuitPref )");
    query.bindValue(":name", name);
    query.bindValue(":animalPrefType", EMPTYENTRY);
    query.bindValue(":address", address);
    query.bindValue(":phoneNo", phoneNo);
    query.bindValue(":email", email);
    query.bindValue(":opennessToExp", EMPTYENTRY);
    query.bindValue(":conscientiousness", EMPTYENTRY);
    query.bindValue(":extraversion", EMPTYENTRY);
    query.bindValue(":agreeableness", EMPTYENTRY);
    query.bindValue(":neuroticism", EMPTYENTRY);
    query.bindValue(":agePref", EMPTYENTRY);
    query.bindValue(":genderPref", EMPTYENTRY);
    query.bindValue(":sizePref", EMPTYENTRY);
    query.bindValue(":kidFriendlinessPref", EMPTYENTRY);
    query.bindValue(":costPref", EMPTYENTRY);
    query.bindValue(":currTrainPref", EMPTYENTRY);
    query.bindValue(":intelligencePref", EMPTYENTRY);
    query.bindValue(":timeCommitPref", EMPTYENTRY);
    query.bindValue(":sheddingPref" , EMPTYENTRY);
    query.bindValue(":aptCompatibilityPref", EMPTYENTRY);
    query.bindValue(":trainSuitPref", EMPTYENTRY);


    query.exec();
    //qDebug()<<query.lastError()<<endl;
}

void DBQuery::editClientInTable(int id, QString name, QString address, QString animalPrefType,
                                QString phoneNo, QString email,QString agePref,
                                QString genderPref,QString sizePref,QString kidFriendlinessPref,
                                QString costPref,QString currTrainPref,QString intelligencePref,QString timeCommitPref,
                                QString sheddingPref,QString aptCompatibilityPref,QString trainSuitPref){
    QSqlQuery query;
    query.prepare("UPDATE Clients "
                  "SET name=:name, address=:address, animalPrefType=:animalPrefType, phoneNo=:phoneNo, "
                  "email=:email,"
                  "agePref=:agePref, genderPref=:genderPref, sizePref=:sizePref,"
                  "kidFriendlinessPref=:kidFriendlinessPref, costPref=:costPref,"
                  "currTrainPref=:currTrainPref, intelligencePref=:intelligencePref, timeCommitPref=:timeCommitPref,"
                  "sheddingPref=:sheddingPref, aptCompatibilityPref=:aptCompatibilityPref,trainSuitPref=:trainSuitPref "
                  "WHERE id=:id");
    query.bindValue(":name", name);
    query.bindValue(":address", address);
    query.bindValue(":animalPrefType", animalPrefType);
    query.bindValue(":phoneNo", phoneNo);
    query.bindValue(":email", email);

    query.bindValue(":agePref", agePref);
    query.bindValue(":genderPref", genderPref);
    query.bindValue(":sizePref", sizePref);
    query.bindValue(":kidFriendlinessPref", kidFriendlinessPref);
    query.bindValue(":costPref", costPref);
    query.bindValue(":currTrainPref", currTrainPref);
    query.bindValue(":intelligencePref", intelligencePref);
    query.bindValue(":timeCommitPref", timeCommitPref);
    query.bindValue(":sheddingPref" , sheddingPref);
    query.bindValue(":aptCompatibilityPref", aptCompatibilityPref);
    query.bindValue(":trainSuitPref", trainSuitPref);
    query.bindValue(":id", id);
    query.exec();
}
void DBQuery::editClientBigFive(int id, QString opennessToExp,QString conscientiousness, QString extraversion,
                                QString agreeableness, QString neuroticism){

    QSqlQuery query;
    query.prepare("UPDATE Clients "
                  "SET opennessToExp=:opennessToExp, conscientiousness=:conscientiousness,"
                  "extraversion=:extraversion, agreeableness=:agreeableness, neuroticism=:neuroticism "
                  "WHERE id=:id");
    query.bindValue(":opennessToExp", opennessToExp);
    query.bindValue(":conscientiousness", conscientiousness);
    query.bindValue(":extraversion", extraversion);
    query.bindValue(":agreeableness", agreeableness);
    query.bindValue(":neuroticism", neuroticism);
    query.bindValue(":id", id);
    query.exec();


    qDebug()<<query.lastError()<<endl;

}
