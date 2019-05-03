#ifndef CLIENTTABLEMODEL_H
#define CLIENTTABLEMODEL_H

#include <QVector>
#include <QtSql>
#include <QDebug>
#include <QSqlQuery>
#include "Client.h"
#include "DBHandler.h"
#include "DBQuery.h"

class ClientTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    ClientTableModel(QVector<Client*> clientVector, QObject *parent =0);
    ~ClientTableModel();
    /*
    Function   : rowCount
    Purpose    : gives back the number of rows in the table model
    Parameters : input :
                index, type: QModelIndex, used to locate a piece of data in the model
    */
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    /*
    Function   : columnCount
    Purpose    : gives back the number of columns in the table model
    Parameters : input :
                index, type: QModelIndex, used to locate a piece of data in the model
    */
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    /*
    Function   : data
    Purpose    : depending on what index and Display Role (this is Qt terminology) were
                 requested, it returns the data correspoding to that role at that index.
    Parameters : input:
                 index, type: QModelIndex, used to locate a piece of data in the model
                 role, type: int, used to specify a requested data role (usually
                 display roles for table model).
    */
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    /*
    Function   : headerData
    Purpose    : assign header labels for table view of clients
    Parameters : input:
                 section, type: int, this is the client object
                 orientation, type: Qt::Orientation, this gives the horizontal fill of labels
                 role, type: int, depicts the display role
    */
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    /*
    Function   : addToClientVector
    Purpose    : adds a given client object to the
                 client vector maintained by the model
    Parameters : input:
                 clientToAdd, type: Client pointer, this is a pointer to the client object
                 that we wish to add to our collection of clients to be modelled
                 by a table.

    void addToClientVector(Client* clientToAdd);
    */
    void addNewClientToVector(Client* client);
private slots:
    /*
    Function   : update
    Purpose    : triggers the adding of a Client to the vector, then signals the View to update
    Parameters : input:
                 type: Client, the Client object being added
    */
    void update(Client*);

private:
    QVector<Client*> clientVector;
//    DBHandler *dbHandler;
    int numColumns;
//    DBQuery *dbQuery;
//    QString tableName;

};

#endif // CLIENTTABLEMODEL_H


