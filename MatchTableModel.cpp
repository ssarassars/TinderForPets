#include "MatchTableModel.h"

MatchTableModel::MatchTableModel(QMap<int, int> matchMap, QObject *parent): QAbstractTableModel(parent), matchMap()
{
    this->matchMap = matchMap;
    this->numColumns = 2;
}

MatchTableModel::~MatchTableModel()
{
    //delete *matchMap;
}

int MatchTableModel::rowCount(const QModelIndex & parent) const
{   Q_UNUSED(parent);
   return matchMap.count();
}

QVariant MatchTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal){
        if(role == Qt::DisplayRole){
            switch(section){
            case 0:
                return "Client"; break;
            case 1:
                return "Animal"; break;
            default:
                return ""; break;
            }
        }
    }
    return QVariant();
}

int MatchTableModel::columnCount(const QModelIndex & parent) const
{   Q_UNUSED(parent);

    return this->numColumns;
}

QVariant MatchTableModel::data(const QModelIndex &index, int role) const
{
        if (index.row() < 0 || index.row() >= matchMap.count() || role != Qt::DisplayRole) {
            return QVariant();
        }
        if (index.column() == 0)
            return matchMap.keys().at(index.row());
        if (index.column() == 1)
            return matchMap.values().at(index.row());
        return QVariant();

}
