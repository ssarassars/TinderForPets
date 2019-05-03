#ifndef MATCHTABLEMODEL_H
#define MATCHTABLEMODEL_H

#include <QMap>
#include <QAbstractTableModel>
#include "Animal.h"
#include "Client.h"

class MatchTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    MatchTableModel(QMap<int, int> matchMap, QObject *parent=0);
    ~MatchTableModel();
    enum MapRoles {
            KeyRole = Qt::UserRole + 1,
            ValueRole
        };
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

private:
    QMap<int, int> matchMap;
    int numColumns;

};

#endif // MATCHTABLEMODEL_H
