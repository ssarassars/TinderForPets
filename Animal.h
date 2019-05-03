#ifndef ANIMAL_H
#define ANIMAL_H
#include <QString>
#include <QDebug>
#include "Constants.h"

class Animal
{
public:
    Animal(int id, QString name, QString type, QString gender, QString age, QString size,
           QString shedding, QString cost, QString timidity,  QString sociability, QString aggression, QString obedience,
           QString loyalty, QString affection, QString activity, QString excitability, QString expressiveness,
           QString trainingSuitability, QString currentTraining, QString intelligence, QString apartmentCompatibility,
           QString timeCommitment,QString kidFriendliness);

    ~Animal();
    int getID() const;
    QString getName() const;
    QString getType() const;
    QString getGender() const;
    float getGenderNum() ;
    static float genderToNum(QString);
    QString getAge() const;
    float getAgeNum() ;
    static float ageToNum(QString);
    QString getSize() const;
    float getSizeNum() ;
    static float sizeToNum(QString);
    QString getShedding() const;
    float getSheddingNum() ;
    static float shedToNum(QString);
    QString getTimidity() const;
    float getTimidityNum() ;
    QString getSociability() const;
    float getSociabilityNum() ;
    QString getAggression() const;
    float getAggressionNum() ;
    QString getObedience() const;
    float getObedienceNum();
    QString getLoyalty() const;
    float getLoyaltyNum() ;
    QString getAffection() const;
    float getAffectionNum() ;
    QString getActivity() const;
    float getActivityNum() ;
    QString getExcitability() const;
    float getExcitabilityNum() ;
    QString getExpressiveness() const;
    float getExpressivenessNum() ;
    QString getTrainingSuitability() const;
    float getTrainSuitNum() ;
    static float trainSuitToNum(QString) ;
    QString getCurrentTraining() const;
    float getCurrentTrainingNum() ;
    static float currTrainToNum(QString) ;
    QString getIntelligence() const;
    float getIntelligenceNum() ;
    static float intelToNum(QString) ;
    QString getKidfriendliness() const;
    float getKidFriendlinessNum() ;
    static float kidFriendToNum(QString) ;
    QString getCost() const;
    float getCostNum() ;
    static float costToNum(QString) ;
    QString getTimeCommitment() const;
    float getTimeCommitNum() ;
    static float timeCommitToNum(QString) ;
    QString getApartmentCompatibility() const;
    float getAptCompatNum() ;
    static float aptCompatToNum(QString) ;


    void setName(QString newName);
    void setType(QString newType);
    void setGender(QString newGender);
    void setAge(QString newAge);
    void setSize(QString newSize);
    void setShedding(QString newShedding);
    void setTimidity(QString newTimidity);
    void setSociability(QString newSociability);
    void setAggression(QString newAggression);
    void setObedience(QString newObedience);
    void setLoyalty(QString newLoyalty);
    void setAffection(QString newAffection);
    void setActivity(QString newActivity);
    void setExcitability(QString newExcitability);
    void setExpressiveness(QString newExpressiveness);
    void setTrainingSuitability(QString newTrainingSuitability);
    void setCurrentTraining(QString newCurrentTraining);
    void setIntelligence(QString newIntelligence);
    void setCost(QString newCost);
    void setTimeCommitment(QString newTime);
    void setApartmentCompatibility(QString newAptCompatibility);
    void setKidFriendliness(QString newKidFriendliness);

    /*
     Function : profileIncomplete
     Purpose  : to indicate if an animal profile is complete (all attributes have been filled up with a descriptive choice)
     Input    : None
     Output   : return bool, true indicates an incomplete profile, false otherwise
    */
    bool profileIncomplete();
    /*
     Function : isEmptyEntry
     Purpose  : small helper to define in more detail what it means to be an empty entry for an animal
     Input    : QString entry, a string containing an entry , typically for an attribute of the animal
     Output   : return bool, a boolean indicating if an entry is empty (return true if so , otherwise false)
    */
    static bool isEmptyEntry(QString entry);

private:
    int id;
    QString name;
    QString type;
    QString gender;
    QString age;
    QString size;
    QString shedding;
    QString timidity;
    QString sociability;
    QString aggression;
    QString obedience;
    QString loyalty;
    QString affection;
    QString activity;
    QString excitability;
    QString expressiveness;
    QString trainingSuitability;
    QString currentTraining;
    QString intelligence;
    QString cost;
    QString timeCommitment;
    QString apartmentCompatibility;
    QString kidFriendliness;
    /*
     Function : fiveOptNonPhysAttToNum
     Purpose  : helper for converting a standard 5 option attribute to a number
     Input    : QString opt, string representing a standard 5-option-scaled attribute
     Output   : float, a float indicating the numerical value of the option given
    */
    static float fiveOptNonPhysAttToNum(QString opt);
    /*
     Function : threeOptAttToNum
     Purpose  : helper for converting a standard 3 option attribute to a number
     Input    : QString opt, string representing a standard 3-option-scaled attribute
     Output   : float, a float indicating the numerical value of the option given
    */
    static float threeOptAttToNum(QString opt);

};

#endif // ANIMAL_H
