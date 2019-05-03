#include "AnimalTableModel.h"

AnimalTableModel::AnimalTableModel(QVector<Animal*> animalVector, QObject *parent): QAbstractTableModel(parent), animalVector()
{
    this->animalVector = animalVector;
    this->numColumns = 5;
}


AnimalTableModel::~AnimalTableModel()
{
    qDeleteAll(this->animalVector);
}

int AnimalTableModel::rowCount(const QModelIndex & parent) const
{   Q_UNUSED(parent);
   return animalVector.size();
}

QVariant AnimalTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal){
        if(role == Qt::DisplayRole){
            switch(section){
            case 0:
                return "ID"; break;
            case 1:
                return "Name"; break;
            case 2:
                return "Age"; break;
            case 3:
                return "Gender"; break;
            case 4:
                return "Type"; break;
            default:
                return ""; break;
            }
        }
    }
    return QVariant();
}

int AnimalTableModel::columnCount(const QModelIndex & parent) const
{   Q_UNUSED(parent);

    return this->numColumns;
}

QVariant AnimalTableModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole){
        const Animal& myAnimal = *animalVector.at(index.row());
        if(index.column()== 0)
            return myAnimal.getID();
        if(index.column()== 1)
            return myAnimal.getName();
        if(index.column()== 2)
            return myAnimal.getAge();
        if(index.column()== 3)
            return myAnimal.getGender();
        if(index.column()== 4)
            return myAnimal.getType();
    }
    return QVariant();

}

void AnimalTableModel::update(Animal* animal){
        layoutAboutToBeChanged();
        this->addNewAnimalToVector(animal);
        layoutChanged();
}

void AnimalTableModel::addNewAnimalToVector(Animal* animal)
{
    animalVector.append(animal);
}

