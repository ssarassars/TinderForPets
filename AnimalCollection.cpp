#include "AnimalCollection.h"

AnimalCollection::AnimalCollection(QVector<Animal*> animalVector)
{
this->animalVector = animalVector;
}

AnimalCollection::~AnimalCollection()
{
    qDeleteAll(animalVector);
}

void AnimalCollection::addToAnimalVector(Animal* animalToAdd){
    animalVector.append(animalToAdd);
}

//DEMO DEMO DEMO
void AnimalCollection::editAnimal(int id, QString age)
{
    QVectorIterator<Animal*> i(animalVector);
    Animal* currAnimal;
    while (i.hasNext()){
        currAnimal = i.next();
        if (currAnimal->getID() == id){
            currAnimal->setAge(age);
        }
    }

}

//REAL REAL REAL
void AnimalCollection::editAnimal(int id, QString name, QString gender, QString type, QString age, QString size,
                                  QString shedding, QString cost, QString timidity,  QString sociability, QString aggression, QString obedience,
                                  QString loyalty, QString affection, QString activity, QString excitability, QString expressiveness,
                                  QString trainingSuitability, QString currentTraining, QString intelligence, QString apartmentCompatibility,
                                  QString timeCommitment,QString kidFriendliness)
{
    QVectorIterator<Animal*> i(animalVector);
    Animal* currAnimal;
    while (i.hasNext()){
        currAnimal = i.next();
        if (currAnimal->getID() == id){
            currAnimal->setSize(size);
            currAnimal->setShedding(shedding);
            currAnimal->setCost(cost);
            currAnimal->setTimidity(timidity);
            currAnimal->setSociability(sociability);
            currAnimal->setAggression(aggression);
            currAnimal->setObedience(obedience);
            currAnimal->setLoyalty(loyalty);
            currAnimal->setAffection(affection);
            currAnimal->setActivity(activity);
            currAnimal->setExcitability(excitability);
            currAnimal->setExpressiveness(expressiveness);
            currAnimal->setTrainingSuitability(trainingSuitability);
            currAnimal->setCurrentTraining(currentTraining);
            currAnimal->setIntelligence(intelligence);
            currAnimal->setApartmentCompatibility(apartmentCompatibility);
            currAnimal->setTimeCommitment(timeCommitment);
            currAnimal->setKidFriendliness(kidFriendliness);
            currAnimal->setAge(age);
            currAnimal->setName(name);
            currAnimal->setType(type);
            currAnimal->setGender(gender);
        }
    }

}
Animal* AnimalCollection::getAnimalObjectWithId(int idIn){
    for(Animal* a: animalVector){
        if(a->getID()==idIn){
            return a;
        }
    }
    return NULL;
}

QVector<Animal*> AnimalCollection::getAnimalVector(){
    return animalVector;
}
