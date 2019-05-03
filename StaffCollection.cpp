#include "StaffCollection.h"

StaffCollection::StaffCollection(QVector<Staff*> staffVector):staffVector()
{
    this->staffVector = staffVector;
//    this->tableName = "Staff";
//    this->dbHandler = dbHandler;
//    QSqlQuery query;
//    query = this->dbHandler->getStaffTable();
    //query = this->dbQuery->getTable(tableName);

//    while(query.next()){
//        int id = query.value(0).toInt();
//        this->staffVector<< new Staff(id);
//    }
}
StaffCollection::~StaffCollection()
{
    qDeleteAll(staffVector);
}
bool StaffCollection::checkIfStaffExists(int userID)
{
    int currIndex = 0;
    int currID;
    while(currIndex < staffVector.size()){
        currID = staffVector[currIndex]->getID();
        if(currID == userID){
            return true;
        }
        ++currIndex;
    }
    return false;
}
