#ifndef STAFFCOLLECTION_H
#define STAFFCOLLECTION_H
#include <QVector>
#include <QtSql>
#include <QSqlQuery>
#include "Staff.h"
#include "DBHandler.h"
#include "DBQuery.h"

class StaffCollection : public QObject
{
    Q_OBJECT
public:
    StaffCollection(QVector<Staff*> staffVector);
    ~StaffCollection();
    /* Function   : checkIfStaffExists
     * Purpose    : to verify that the entered staff user id is valid for logging in
     * Parameters : input: userID, type: int, the user id entered for logging in as staff
     * Returns    : type: bool, true if the userID is that of an existing staff member, false otherwise
    */
    bool checkIfStaffExists(int userID);
private:
    QVector<Staff*> staffVector;
//    DBQuery *dbQuery;
//    QString tableName;
//    DBHandler *dbHandler;
};

#endif // STAFFCOLLECTION_H
