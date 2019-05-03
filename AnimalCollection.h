#ifndef ANIMALCOLLECTION_H
#define ANIMALCOLLECTION_H
#include "Animal.h"
#include <QVector>
#include <QDebug>

class AnimalCollection
{
public:
    AnimalCollection(QVector<Animal*> animalVector);
     ~AnimalCollection();
    /*
    Function   : addToAnimalVector
    Purpose    : to add an animal to the AnimalCollection's vector
    Parameters :input:
                animalToAdd, type: Animal, animal being added
    */
    void addToAnimalVector(Animal* animalToAdd);
    /*
    Function   : editAnimal
    Purpose    : to add an animal to the AnimalCollection's vector,
                 this variant of editAnimal is just for testing purposes
    Parameters :input: type: int, id
                       type: QSTring, age
    */
    void editAnimal(int id, QString age);
    /*
    Function   : editAnimal
    Purpose    : to edit an animal in the AnimalCollection
    Parameters :
                input:
                id, type: int, ID number of animal to identify it
                name, type: QString, name of animal entered by user
                age, type: QString, age range of animal entered by user
                gender, type: QString, gender of animal selected by user
                type, type: QString, species of animal selected by user
                size, type: QString, size of animal
                shedding, type: QString, how much the animal sheds
                cost, type: QString, how much would the animal cost to maintain
                timidity, type: QString, how timid is the animal
                sociability, type: QString, extent to which animal is willing to socialize
                aggression, type: QString, extent to which animal can be agressive
                obedience, type: QString, extent to which animal will listen to authority
                loyalty, type: QString, extent to which animal is typically loyal
                affection, type: QString, extent to which animal is willing to be affective
                activity, type: QString, extent to which animal is typically active
                excitability, type: QString, extent to which animal is excitable
                expressiveness, type: QString, animal's skill with expressing their needs
                trainingSuitability, type: QString, How effective training will be in altering the animal’s natural behaviour.
                currentTraining, type: QString, extent to which the animal has already been trained
                intelligence, type: QString, how smart the animal is - this affects its ability to perform tasks.
                apartmentCompatibility, type: QString, How well-suited the animal is to living in an apartment.
                timeCommitment,type: QString, how much time per day the animal will require in order to be satisfied.
                kidFriendliness, type: QString, rating of how well animal copes with children, selected by user

    */
    void editAnimal(int id, QString name, QString gender, QString type, QString age, QString size,
                    QString shedding, QString cost, QString timidity,  QString sociability, QString aggression, QString obedience,
                    QString loyalty, QString affection, QString activity, QString excitability, QString expressiveness,
                    QString trainingSuitability, QString currentTraining, QString intelligence, QString apartmentCompatibility,
                    QString timeCommitment,QString kidFriendliness);
    /*
    Function   : getAnimalObjectWithId
    Purpose    : return animal object with input animal ID
    Parameters : int, ID
    Return     : type: Animal*, animal object
    */
    Animal* getAnimalObjectWithId(int id);
    /*
    Function   : getAnimalVector
    Purpose    : return animal vector with all animals in the database
    Parameters : none
    Return     : type: QVector
    */
    QVector<Animal*> getAnimalVector();
private:
    QVector<Animal*> animalVector;
};

#endif // ANIMALCOLLECTION_H
