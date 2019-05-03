#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include "Constants.h"
#include <QVector>
#include "Animal.h"
#include <QMap>

class Client
{
public:
    //for adding to db
    Client(int id, QString name, QString email, QString animalPrefType,QString address, QString phoneNo);
//    Client(int id, QString name, QString animalPrefType,QString address, QString phoneNo); //should this constructor exist?
//    Client(int id, QString name, QString address, QString phoneNo);
    //for full fledged retreival
    Client(int id, QString name, QString email, QString animalPrefType,QString address, QString phoneNo,
           QString opennessToExp, QString conscientiousness,
           QString extraversion,QString agreeableness,QString neuroticism,QString agePref,
           QString genderPref,QString sizePref,QString kidFriendlinessPref,
           QString costPref,QString currTrainPref,QString intelligencePref,QString timeCommitPref,
           QString sheddingPref,QString aptCompatibilityPref,QString trainSuitPref);
    ~Client();
    int getID() const;
    QString getName() const;
    QString getEmail() const;
    QString getAnimalPrefType() const;
    QString getAddress() const;
    QString getPhoneNo() const;
    QString getAgePref() const;
    QString getGenderPref() const;
    QString getSizePref() const;
    QString getKidFriendlyPref() const;
    QString getCostPref() const;
    QString getCurrTrainingPref() const;
    QString getIntelligencePref() const;
    QString getTimeCommitPref() const;
    QString getSheddingPref() const;
    QString getAptCompatibilityPref() const;
    QString getTrainSuitabilityPref() const;

    QString getOpennessToExp() const;
    QMap<QString, QVector<QString>> getOpennessToExpAnimalPref() const;
    QString getConscientiousness() const;
    QMap<QString, QVector<QString>> getConscientiousnessAnimalPref() const;
    QString getExtraversion() const;
    QMap<QString, QVector<QString>> getExtraversionAnimalPref() const;
    QString getAgreeableness() const;
    QMap<QString, QVector<QString>> getAgreeablenessAnimalPref() const;
    QString getNeuroticism() const;
    QMap<QString, QVector<QString>> getNeuroticismAnimalPref() const;

    void setName(QString name);
    void setEmail(QString email);
    void setAnimalPrefType(QString animalPrefType);
    void setAddress(QString address);
    void setPhoneNo(QString phoneNo);
    void setAgePref(QString agePref);
    void setGenderPref(QString genderPref);
    void setSizePref(QString sizePref) ;
    void setKidFriendlyPref(QString kidFriendlyPref) ;
    void setCostPref(QString costPref) ;
    void setCurrTrainingPref(QString currTrainPref) ;
    void setIntelligencePref(QString intelliPref) ;
    void setTimeCommitPref(QString timeCommitPref) ;
    void setSheddingPref(QString shedPref) ;
    void setAptCompatibilityPref(QString aptCompatPref) ;
    void setTrainSuitabilityPref(QString trainSuitPref) ;

    void setOpennessToExp(QString opennessToExp);
    void setConscientiousness(QString conscientiousness);
    void setExtraversion(QString extraversion);
    void setAgreeableness(QString agreeableness);
    void setNeuroticism(QString neuroticism);

    /*
    Function   : bigFiveComplete
    Purpose    : tells the display whether or not this client has finished the personality quiz
    Parameters : output:
                 type, bool: true if they have filled out they quiz, false if not
    */
    bool bigFiveComplete();
    /*
    Function   : computeBigFive
    Purpose    : given quiz answers, computes a client's personality scores
    Parameters : input:
                 ansVector, type, QVector<float>: the answers to the quiz selected by the client
    */
    void computeBigFive(QVector<float>* ansVector);
    /*
    Function   : bigFiveNumToCategory
    Purpose    : converts a real-valued Big Five score to a string
    Parameters : input:
                 num, type, float: the score for a given attribute
                 output:
                 type, QString: the corresponding string value to the numerical score
    */
    QString bigFiveNumToCategory(float num);
    /*
     Function : profileIncomplete
     Purpose  : determines if the client's profile is complete and ready for matching
     Input    : None
     Output   : None
    */
    bool profileIncomplete();
    float getAgePrefNum() ;
    float getGenderPrefNum() ;
    float getSizePrefNum() ;
    float getKidFriendlyPrefNum() ;
    float getCostPrefNum() ;
    float getCurrTrainingPrefNum() ;
    float getIntelligencePrefNum() ;
    float getTimeCommitPrefNum() ;
    float getSheddingPrefNum();
    float getAptCompatibilityPrefNum() ;
    float getTrainSuitabilityPrefNum() ;


    /* The following are simple functions that return
     * an ideal animal score for an animal personality trait
     * based on client personality traits.
    */
    float idealTimidity();
    float idealSociability();
    float idealAggression();
    float idealObedience();
    float idealLoyalty();
    float idealAffection();
    float idealActivity();
    float idealExcitability();
    float idealExpressiveness();
    QMap<QString, QVector<QString>> opennessToExpAnimalPref;
    QMap<QString, QVector<QString>> conscientiousnessAnimalPref;
    QMap<QString, QVector<QString>> extraversionAnimalPref;
    QMap<QString, QVector<QString>> agreeablenessAnimalPref;
    QMap<QString, QVector<QString>> neuroticismAnimalPref;


private:

    //Note for D4: we will not save the compatible animal scores.
    //They will be computed on the fly when required (which is only in ACM algo),
    //since that would be a collection of very cheap operations.
    QString emptySelect;
    int id;
    QString name;
    QString email;
    QString animalPrefType;
    QString address;
    QString phoneNo;
    //Client Personality
    QString opennessToExp;
    QString conscientiousness;
    QString extraversion;
    QString agreeableness;
    QString neuroticism;
    //Client Match Prefs
    QString agePref;
    QString genderPref;
    QString sizePref;
    QString kidFriendlyPref;
    QString costPref;
    QString currTrainPref;
    QString intelliPref;
    QString timeCommitPref;
    QString shedPref;
    QString aptCompatPref;
    QString trainSuitPref;
    /*
     Function : isEmptyEntry
     Purpose  : small helper to define in more detail what it means to be an empty entry for a client
     Input    : QString entry, a string containing an entry , typically for an attribute of the client
     Output   : return bool, a boolean indicating if an entry is empty (return true if so , otherwise false)
    */
    bool isEmptyEntry(QString entry);
    /*
     Function : matchPrefsComplete
     Purpose  : checks if at least one matching preference has been selected
     Input    : None
     Output   : return bool, a boolean indicating if the client's matching preferences
                part has been submitted for matching
    */
    bool matchPrefsComplete();
    /*
     Function : average
     Purpose  : computes the average of entries in a given vector
     Input    : QVector<float>, a vector of floats
     Output   : float, the computed average
    */
    float average(QVector<float> valueHolder);
    /*
     Function : getPersonalityWeights
     Purpose  : constructs a map from standard personality strings on the
                five category scale to numerical scores
     Input    : None
     Output   : returns QHash<QString, float>, a map of personality weights
    */
    QHash<QString, float> getPersonalityWeights();
    /*
     Function : getFiveCatScale
     Purpose  : to obtain strings for the standard five category scale for personality attributes
     Input    : None
     Output   : return QVector<QString>, a vector containing strings for the five category scale
    */
    QVector<QString> getFiveCatScale();

};

#endif // CLIENT_H
