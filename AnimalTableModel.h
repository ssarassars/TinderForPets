#ifndef ANIMALTABLEMODEL_H
#define ANIMALTABLEMODEL_H

#include <QVector>
#include <QtSql>
#include <QDebug>
#include <QSqlQuery>
#include "Animal.h"
#include "DBHandler.h"
#include "DBQuery.h"


class AnimalTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:

    AnimalTableModel(QVector<Animal*> animalVector, QObject *parent =0);
    ~AnimalTableModel();
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
    Purpose    : assign header labels for table view of animals
    Parameters : input:
                 section, type: int, this is the animal object
                 orientation, type: Qt::Orientation, this gives the horizontal fill of labels
                 role, type: int, depicts the display role
    */
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    /*
    Function   : addToAnimalVector
    Purpose    : adds a given animal object to the
                 animal vector maintained by the model
    Parameters : input:
                 animalToAdd, type: Animal pointer, this is the animal object pointer
                 that we wish to add to our collection of animals to be modelled
                 by a table.
    */
    void addNewAnimalToVector(Animal*);
signals:
    void animalHasBeenAdded();

private slots:
    /*
    Function   : update
    Purpose    : triggers the adding of an Animal to the vector, then signals the View to update
    Parameters : input:
                 type: Animal, the Animal object being added
    */
        void update(Animal*);
private:
    QVector<Animal*> animalVector;
//    DBHandler *dbHandler;
//    DBQuery *dbQuery;
    int numColumns;
//    QString tableName;

};

#endif // ANIMALTABLEMODEL_H
