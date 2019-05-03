#include "ClientTableModel.h"

ClientTableModel::ClientTableModel(QVector<Client*> clientVector, QObject *parent): QAbstractTableModel(parent), clientVector()
{
    this->clientVector = clientVector;
    this->numColumns = 2;
}

ClientTableModel::~ClientTableModel(){
    qDeleteAll(this->clientVector);
}

int ClientTableModel::rowCount(const QModelIndex & parent) const
{   Q_UNUSED(parent);
   return clientVector.size();
}

QVariant ClientTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal){
        if(role == Qt::DisplayRole){
            switch(section){
            case 0:
                return "ID"; break;
            case 1:
                return "Name"; break;
            default:
                return ""; break;
            }
        }
    }
    return QVariant();
}

int ClientTableModel::columnCount(const QModelIndex & parent) const
{   Q_UNUSED(parent);

    return this->numColumns;
}

QVariant ClientTableModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole){
        const Client& myClient = *clientVector.at(index.row());
        if(index.column()== 0)
            return myClient.getID();
        if(index.column()== 1)
            return myClient.getName();
    }
    return QVariant();

}

void ClientTableModel::update(Client* client){
        layoutAboutToBeChanged();
        addNewClientToVector(client);
        layoutChanged();
}

void ClientTableModel::addNewClientToVector(Client* client)
{
    clientVector.append(client);
}





