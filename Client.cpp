#include "Client.h"

Client::Client(int id, QString name, QString email, QString animalPrefType,QString address, QString phoneNo){
    this->id = id;
    this->name = name;
    this->email = email;
    this->animalPrefType = animalPrefType;
    this->address = address;
    this->phoneNo = phoneNo;
    //Client Personality
    this->opennessToExp = EMPTYENTRY;
    this->conscientiousness= EMPTYENTRY;
    this->extraversion= EMPTYENTRY;
    this->agreeableness= EMPTYENTRY;
    this->neuroticism= EMPTYENTRY;
    //Client Match Prefs
    this->agePref= EMPTYENTRY;
    this->genderPref= EMPTYENTRY;
    this->sizePref= EMPTYENTRY;
    this->kidFriendlyPref= EMPTYENTRY;
    this->costPref= EMPTYENTRY;
    this->currTrainPref= EMPTYENTRY;
    this->intelliPref= EMPTYENTRY;
    this->timeCommitPref= EMPTYENTRY;
    this->shedPref= EMPTYENTRY;
    this->aptCompatPref= EMPTYENTRY;
    this->trainSuitPref= EMPTYENTRY;

}
Client::Client(int id, QString name, QString email, QString animalPrefType,QString address, QString phoneNo,
       QString opennessToExp, QString conscientiousness,
       QString extraversion,QString agreeableness,QString neuroticism,QString agePref,
       QString genderPref,QString sizePref,QString kidFriendlinessPref,
       QString costPref,QString currTrainPref,QString intelligencePref,QString timeCommitPref,
       QString sheddingPref,QString aptCompatibilityPref,QString trainSuitPref)
{
    this->id = id;
    this->name = name;
    this->email = email;
    this->animalPrefType = animalPrefType;
    this->address = address;
    this->phoneNo = phoneNo;
    //Client Personality
    this->opennessToExp = opennessToExp;
    this->conscientiousness= conscientiousness;
    this->extraversion= extraversion;
    this->agreeableness= agreeableness;
    this->neuroticism= neuroticism;
    //Client Match Prefs
    this->agePref= agePref;
    this->genderPref= genderPref;
    this->sizePref= sizePref;
    this->kidFriendlyPref= kidFriendlinessPref;
    this->costPref= costPref;
    this->currTrainPref= currTrainPref;
    this->intelliPref= intelligencePref;
    this->timeCommitPref= timeCommitPref;
    this->shedPref= sheddingPref;
    this->aptCompatPref= aptCompatibilityPref;
    this->trainSuitPref= trainSuitPref;

    QMap<QString, QVector<QString>> opennessToExpAnimalPref = {

        {"Very High", {"Very Low Timidity", "Very High Activity", "Very High Excitability"}},
        {"High", {"Low Timidity", "High Activity", "High Excitability"}},
        {"Moderate", {"Moderate Timidity", "Moderate Obedience", "Moderate Activity", "Moderate Excitability"}},
        {"Low", {"High Obedience", "Low Activity"}},
        {"Very Low", {"Very High Obedience", "Very Low Activity"}},

    };

    QMap<QString, QVector<QString>> conscientiousnessAnimalPref = {

        {"Very High", {"Very High Obedience", "Very Low Activity"}},
        {"High", {"Low Activity", "High Obedience"}},
        {"Moderate", {"Moderate Obedience", "Moderate Activity", "Moderate Excitability"}},
        {"Low", {"High Loyalty", "Low Obedience", "High Excitability"}},
        {"Very Low", {"Very Low Obedience", "Very High Loyalty", "Very High Excitability"}},

    };

    QMap<QString, QVector<QString>> extraversionAnimalPref = {

        {"Very High", {"Very High Sociability", "Very High Excitability", "Very High Expressiveness"}},
        {"High", {"High Sociability", "High Excitability", "High Expressiveness"}},
        {"Moderate", {"Moderate Sociability", "Moderate Expressiveness", "Moderate Excitability"}},
        {"Low", {"High Sociability", "Low Excitability"}},
        {"Very Low", {"Very Low Sociability", "Very Low Excitability"}},

    };

    QMap<QString, QVector<QString>> agreeablenessAnimalPref = {

        {"Very High", {"Very High Aggression", "Very High Loyalty", "Very High Affection"}},
        {"High", {"High Aggression", "High Loyalty", "High Affection"}},
        {"Moderate", {"Moderate Timidity", "Moderate Sociability", "Moderate Aggression", "Moderate Loyalty", "Moderate Affection"}},
        {"Low", {"Low Timidity", "Low Sociability", "Low Affection"}},
        {"Very Low", {"Very Low Timidity", "Very Low Sociability", "Very Low Affection"}},

    };

    QMap<QString, QVector<QString>> neuroticismAnimalPref = {

        {"Very High", {"Very High Loyalty", "Very Low Aggression", "Very High Affection", "Very High Expressiveness"}},
        {"High", {"Low Aggression", "High Loyalty", "High Affection", "High Expressiveness"}},
        {"Moderate", {"Moderate Loyalty", "Moderate Aggression", "Moderate Affection", "Moderate Expressiveness"}},

    };

    this->neuroticismAnimalPref=neuroticismAnimalPref;
    this->agreeablenessAnimalPref=agreeablenessAnimalPref;
    this->extraversionAnimalPref=extraversionAnimalPref;
    this->agreeablenessAnimalPref=agreeablenessAnimalPref;
    this->conscientiousnessAnimalPref=conscientiousnessAnimalPref;

}

//Client::Client(int id, QString name, QString address, QString phoneNo){
//    this->id = id;
//    this->name = name;
//    this->animalPrefType = this->emptySelect;
//    this->address = address;
//    this->phoneNo = phoneNo;
//}
Client::~Client(){

}


//QMap<QString, QVector<QString>> Client::getOpennessToExpAnimalPref(){
//    return opennessToExpAn
//}

int Client::getID() const{
    return this->id;
}
QString Client::getName() const{
    return this->name;
}
QString Client::getEmail() const{
    return this->email;
}
QString Client::getAnimalPrefType() const{
    return this->animalPrefType;
}
QString Client::getAddress() const{
    return this->address;
}
QString Client::getPhoneNo() const{
    return this->phoneNo;
}
QString Client::getAgePref() const
{
    return this->agePref;
}
QString Client::getGenderPref() const
{
    return this->genderPref;
}

QString Client::getSizePref() const
{
    return this->sizePref;
}
QString Client::getKidFriendlyPref() const
{
    return this->kidFriendlyPref;
}
QString Client::getCostPref() const
{
    return this->costPref;
}
QString Client::getCurrTrainingPref() const
{
    return this->currTrainPref;
}
QString Client::getIntelligencePref() const
{
    return this->intelliPref;
}
QString Client::getTimeCommitPref() const
{
    return this->timeCommitPref;
}
QString Client::getSheddingPref() const
{
    return this->shedPref;
}
QString Client::getAptCompatibilityPref() const
{
    return this->aptCompatPref;
}
QString Client::getTrainSuitabilityPref() const
{
    return this->trainSuitPref;
}

QString Client::getOpennessToExp() const
{
    return this->opennessToExp;
}

QMap<QString, QVector<QString>> Client::getOpennessToExpAnimalPref() const
{
    return this->opennessToExpAnimalPref;
}

QString Client::getConscientiousness() const
{
    return this->conscientiousness;
}

QMap<QString, QVector<QString>> Client::getConscientiousnessAnimalPref() const
{
    return this->conscientiousnessAnimalPref;
}

QString Client::getExtraversion() const
{
    return this->extraversion;
}

QMap<QString, QVector<QString>> Client::getExtraversionAnimalPref() const
{
    return this->extraversionAnimalPref;
}

QString Client::getAgreeableness() const
{
    return this->agreeableness;
}

QMap<QString, QVector<QString>> Client::getAgreeablenessAnimalPref() const
{
    return this->agreeablenessAnimalPref;
}

QString Client::getNeuroticism() const
{
    return this->neuroticism;
}
QMap<QString, QVector<QString>> Client::getNeuroticismAnimalPref() const
{
    return this->neuroticismAnimalPref;
}

void Client::setAgePref(QString agePref)
{
    this->agePref = agePref;
}
void Client::setGenderPref(QString genderPref)
{
    this->genderPref = genderPref;
}

void Client::setSizePref(QString sizePref)
{
    this->sizePref = sizePref;
}
void Client::setKidFriendlyPref(QString kidFriendlyPref)
{
    this->kidFriendlyPref = kidFriendlyPref;
}
void Client::setCostPref(QString costPref)
{
    this->costPref = costPref;
}
void Client::setCurrTrainingPref(QString currTrainPref)
{
    this->currTrainPref = currTrainPref;
}
void Client::setIntelligencePref(QString intelliPref)
{
    this->intelliPref = intelliPref;
}
void Client::setTimeCommitPref(QString timeCommitPref)
{
    this->timeCommitPref = timeCommitPref;
}
void Client::setSheddingPref(QString shedPref)
{
    this->shedPref = shedPref;
}
void Client::setAptCompatibilityPref(QString aptCompatPref)
{
    this->aptCompatPref = aptCompatPref;
}
void Client::setTrainSuitabilityPref(QString trainSuitPref)
{
    this->trainSuitPref = trainSuitPref;
}

void Client::setName(QString name){
    this->name = name;
}
void Client::setEmail(QString email){
    this->email = email;
}
void Client::setAnimalPrefType(QString animalPrefType){
    this->animalPrefType = animalPrefType;
}
void Client::setAddress(QString address){
    this->address = address;
}
void Client::setPhoneNo(QString phoneNo){
    this->phoneNo = phoneNo;
}
void Client::setOpennessToExp(QString opennessToExp)
{
    this->opennessToExp = opennessToExp;

}
void Client::setConscientiousness(QString conscientiousness)
{
    this->conscientiousness = conscientiousness;
}
void Client::setExtraversion(QString extraversion)
{
    this->extraversion = extraversion;
}
void Client::setAgreeableness(QString agreeableness)
{
    this->agreeableness = agreeableness;
}
void Client::setNeuroticism(QString neuroticism)
{
    this->neuroticism = neuroticism;
}
bool Client::bigFiveComplete()
{
    if((this->neuroticism != EMPTYENTRY && this->neuroticism!="")
            && (this->agreeableness != EMPTYENTRY && this->agreeableness!="")
            && (this->extraversion != EMPTYENTRY && this->extraversion!="")
            && (this->conscientiousness != EMPTYENTRY && this->conscientiousness!="")
            && (this->opennessToExp != EMPTYENTRY && this->opennessToExp!="")){
        return true;
    }
    return false;
}

void Client::computeBigFive(QVector<float>* ansVector)

{
    //expecting scores to be between 1 and 5
    float neuroScore = 0;
    float openScore = 0;
    float agreeScore = 0;
    float conscienScore = 0;
    float extraverScore = 0;
    int qNum  = 0;

    for(int i = 0; i < ansVector->length() ; i++){
        qNum = i+1;
        if(qNum==6 || qNum==21 || qNum==31 || qNum==2 || qNum==12 || qNum ==27 || qNum == 37 || qNum == 8 || qNum == 18 || qNum==23||
                qNum == 43 || qNum == 9 || qNum==24 || qNum ==34 || qNum==35 || qNum==41){
            //adjust reverse scored item
            ansVector->insert( i, 6 - ansVector->at(i));

        }
        if(qNum ==1 || qNum == 6 || qNum ==11 || qNum == 16 || qNum == 21 || qNum ==26 || qNum==31 || qNum==36){
            //Extraversion
            extraverScore = extraverScore + ansVector->at(i);

        }else if(qNum == 2 || qNum == 7 || qNum == 12 || qNum == 17 ||
                 qNum == 22 || qNum == 27 || qNum ==32 || qNum==37 || qNum == 42){
            //Agreeableness
            agreeScore = agreeScore + ansVector->at(i);
        }else if(qNum == 3 || qNum == 8 || qNum==13 || qNum ==18 || qNum == 23 || qNum==28 || qNum == 33||
                 qNum == 38 || qNum==43){
            //Consciensciousness
            conscienScore = conscienScore + ansVector->at(i);

        }else if(qNum == 4 || qNum == 9 || qNum == 14 || qNum == 19
                 || qNum == 24 || qNum==29 || qNum == 34 || qNum==39){
            //Neuroticism
            neuroScore = neuroScore + ansVector->at(i);

        }else{
            //Openness
            openScore = openScore + ansVector->at(i);

        }
    }

    //calculate average
    extraverScore =  extraverScore/8;
    agreeScore = agreeScore/9;
    conscienScore = conscienScore/9;
    neuroScore = neuroScore/8 ;
    openScore = openScore/10;


    //turn to categorical and set

    this->setExtraversion(bigFiveNumToCategory(extraverScore));
    this->setAgreeableness(bigFiveNumToCategory(agreeScore));
    this->setConscientiousness(bigFiveNumToCategory(conscienScore));
    this->setNeuroticism(bigFiveNumToCategory(neuroScore));
    this->setOpennessToExp(bigFiveNumToCategory(openScore));
}

QString Client::bigFiveNumToCategory(float num)
{
    QVector<QString> scale = getFiveCatScale();
    if(num <= 1.8){
        return scale[0];

    }else if(num <= 2.6){
        return scale[1];

    }else if(num <= 3.4){
        return scale[2];

    }else if(num <= 4.2){
        return scale[3];

    }else{
        return scale[4];
    }
}
QVector<QString> Client::getFiveCatScale(){
    QVector<QString> scale;
    scale.append("Very Low");
    scale.append("Low");
    scale.append("Medium");
    scale.append("High");
    scale.append("Very High");
    return scale;

}

float Client::getAgePrefNum() {
    return Animal::ageToNum(this->agePref);
}
float Client::getGenderPrefNum() {
    return Animal::genderToNum(this->genderPref);
}
float Client::getSizePrefNum() {
    return Animal::sizeToNum(this->sizePref);
}
float Client::getKidFriendlyPrefNum() {
    return Animal::kidFriendToNum(this->kidFriendlyPref);
}
float Client::getCostPrefNum() {
    return Animal::costToNum(this->costPref);
}
float Client::getCurrTrainingPrefNum() {
    return Animal::currTrainToNum(this->currTrainPref);
}
float Client::getIntelligencePrefNum(){
    return Animal::intelToNum(this->intelliPref);
}
float Client::getTimeCommitPrefNum(){
    return Animal::timeCommitToNum(this->timeCommitPref);
}
float Client::getSheddingPrefNum(){
    return Animal::shedToNum(this->shedPref);
}
float Client::getAptCompatibilityPrefNum(){
    return Animal::aptCompatToNum(this->aptCompatPref);
}
float Client::getTrainSuitabilityPrefNum(){
    return Animal::trainSuitToNum(this->trainSuitPref);
}
bool Client::isEmptyEntry(QString entry){
    if(entry == EMPTYENTRY || entry == ""){
        return true;
    }
    return false;
}
//at least one match pref is not empty, means these have been submitted.
bool Client::matchPrefsComplete(){
    if(isEmptyEntry(agePref) && isEmptyEntry(animalPrefType) && isEmptyEntry(genderPref)
            && isEmptyEntry(sizePref) && isEmptyEntry(kidFriendlyPref) && isEmptyEntry(costPref)
            && isEmptyEntry(currTrainPref) && isEmptyEntry(trainSuitPref) && isEmptyEntry(aptCompatPref)
            && isEmptyEntry(intelliPref) && isEmptyEntry(timeCommitPref) && isEmptyEntry(shedPref)){
        return false;

    }
    return true;
}

bool Client::profileIncomplete(){
    if(!bigFiveComplete() || !matchPrefsComplete()){
        return true;
    }
    return false;
}

QHash<QString, float> Client::getPersonalityWeights(){
    QHash<QString, float> basicWeights;
    QVector<QString> personalityScale = getFiveCatScale();

    basicWeights[personalityScale[0]] = 0.0;
    basicWeights[personalityScale[1]] = 0.25;
    basicWeights[personalityScale[2]] = 0.5;
    basicWeights[personalityScale[3]] = 0.75;
    basicWeights[personalityScale[4]] = 1.0;
    return basicWeights;
}

float Client::average(QVector<float> valueHolder){
    float total = 0;
    for(int i=0; i<valueHolder.length(); i++){
        total = total+valueHolder.at(i);
    }
    return total/valueHolder.length();
}

float Client::idealTimidity(){

    QVector<float> valueHolder;
    QHash<QString, float> basicWeights = getPersonalityWeights();
    QVector<QString> personalityScale = getFiveCatScale();

    if(this->opennessToExp == personalityScale[4]){
        valueHolder.append(basicWeights[personalityScale[0]]);
    }else if(this->opennessToExp == personalityScale[3]){
        valueHolder.append(basicWeights[personalityScale[1]]);
    }else if(this->opennessToExp == personalityScale[2]){
        valueHolder.append(basicWeights[personalityScale[2]]);
    }

    if(this->agreeableness == personalityScale[0]){
        valueHolder.append(basicWeights[personalityScale[0]]);
    }else if(this->agreeableness == personalityScale[1]){
        valueHolder.append(basicWeights[personalityScale[1]]);
    }else if(this->agreeableness == personalityScale[2]){
        valueHolder.append(basicWeights[personalityScale[2]]);
    }
    float result;
    if(valueHolder.length() > 0){
        result = average(valueHolder);
    }else{
        // indicates indifference
        result = -1.0;
    }

    return result;

}

float Client::idealSociability(){
    QVector<float> valueHolder;
    QHash<QString, float> basicWeights = getPersonalityWeights();
    QVector<QString> personalityScale = getFiveCatScale();

    if(this->extraversion == personalityScale[0]){
        valueHolder.append(basicWeights[personalityScale[0]]);
    }else if(this->extraversion == personalityScale[1]){
        valueHolder.append(basicWeights[personalityScale[1]]);
    }else if(this->extraversion == personalityScale[2]){
        valueHolder.append(basicWeights[personalityScale[2]]);
    }else if(this->extraversion == personalityScale[3]){
        valueHolder.append(basicWeights[personalityScale[3]]);
    }else if(this->extraversion == personalityScale[4]){
        valueHolder.append(basicWeights[personalityScale[4]]);
    }

    if(this->agreeableness == personalityScale[0]){
        valueHolder.append(basicWeights[personalityScale[0]]);
    }else if(this->agreeableness == personalityScale[1]){
        valueHolder.append(basicWeights[personalityScale[1]]);
    }else if(this->agreeableness == personalityScale[2]){
        valueHolder.append(basicWeights[personalityScale[2]]);
    }


    float result;
    if(valueHolder.length() > 0){
        result = average(valueHolder);
    }else{
        // indicates indifference
        result = -1.0;
    }
    return result;
}

float Client::idealAggression(){
    QVector<float> valueHolder;
    QHash<QString, float> basicWeights = getPersonalityWeights();
    QVector<QString> personalityScale = getFiveCatScale();

    if(this->agreeableness == personalityScale[2]){
        valueHolder.append(basicWeights[personalityScale[2]]);
    }else if(this->agreeableness == personalityScale[3]){
        valueHolder.append(basicWeights[personalityScale[3]]);
    }else if(this->agreeableness == personalityScale[4]){
        valueHolder.append(basicWeights[personalityScale[4]]);
    }

    if(this->neuroticism == personalityScale[2]){
        valueHolder.append(basicWeights[personalityScale[2]]);
    }else if(this->neuroticism == personalityScale[3]){
        valueHolder.append(basicWeights[personalityScale[3]]);
    }else if(this->neuroticism == personalityScale[4]){
        valueHolder.append(basicWeights[personalityScale[4]]);
    }


    float result;
    if(valueHolder.length() > 0){
        result = average(valueHolder);
    }else{
        // indicates indifference
        result = -1.0;
    }
    return result;
}

float Client::idealObedience(){
    QVector<float> valueHolder;
    QHash<QString, float> basicWeights = getPersonalityWeights();
    QVector<QString> personalityScale = getFiveCatScale();

    if(this->opennessToExp == personalityScale[0]){
        valueHolder.append(basicWeights[personalityScale[4]]);
    }else if(this->opennessToExp == personalityScale[1]){
        valueHolder.append(basicWeights[personalityScale[3]]);
    }else if(this->opennessToExp == personalityScale[2]){
        valueHolder.append(basicWeights[personalityScale[2]]);
    }

    if(this->conscientiousness == personalityScale[0]){
        valueHolder.append(basicWeights[personalityScale[0]]);
    }else if(this->conscientiousness == personalityScale[1]){
        valueHolder.append(basicWeights[personalityScale[1]]);
    }else if(this->conscientiousness == personalityScale[2]){
        valueHolder.append(basicWeights[personalityScale[2]]);
    }else if(this->conscientiousness == personalityScale[3]){
        valueHolder.append(basicWeights[personalityScale[3]]);
    }else if(this->conscientiousness == personalityScale[4]){
        valueHolder.append(basicWeights[personalityScale[4]]);
    }


    float result;
    if(valueHolder.length() > 0){
        result = average(valueHolder);
    }else{
        // indicates indifference
        result = -1.0;
    }
    return result;

}
float Client::idealLoyalty(){
    QVector<float> valueHolder;
    QHash<QString, float> basicWeights = getPersonalityWeights();
    QVector<QString> personalityScale = getFiveCatScale();

    if(this->conscientiousness == personalityScale[0]){
        valueHolder.append(basicWeights[personalityScale[4]]);
    }else if(this->conscientiousness == personalityScale[1]){
        valueHolder.append(basicWeights[personalityScale[3]]);
    }else if(this->conscientiousness == personalityScale[2]){
        valueHolder.append(basicWeights[personalityScale[2]]);
    }

    if(this->agreeableness == personalityScale[2]){
        valueHolder.append(basicWeights[personalityScale[2]]);
    }else if(this->agreeableness == personalityScale[3]){
        valueHolder.append(basicWeights[personalityScale[3]]);
    }else if(this->agreeableness == personalityScale[4]){
        valueHolder.append(basicWeights[personalityScale[4]]);
    }
    if(this->neuroticism == personalityScale[2]){
        valueHolder.append(basicWeights[personalityScale[2]]);
    }else if(this->neuroticism == personalityScale[3]){
        valueHolder.append(basicWeights[personalityScale[3]]);
    }else if(this->neuroticism == personalityScale[4]){
        valueHolder.append(basicWeights[personalityScale[4]]);
    }

    float result;
    if(valueHolder.length() > 0){
        result = average(valueHolder);
    }else{
        // indicates indifference
        result = -1.0;
    }
    return result;

}
float Client::idealAffection(){
    QVector<float> valueHolder;
    QHash<QString, float> basicWeights = getPersonalityWeights();
    QVector<QString> personalityScale = getFiveCatScale();

    if(this->agreeableness == personalityScale[0]){
        valueHolder.append(basicWeights[personalityScale[0]]);
    }else if(this->agreeableness == personalityScale[1]){
        valueHolder.append(basicWeights[personalityScale[1]]);
    }else if(this->agreeableness == personalityScale[2]){
        valueHolder.append(basicWeights[personalityScale[2]]);
    }else if(this->agreeableness == personalityScale[3]){
        valueHolder.append(basicWeights[personalityScale[3]]);
    }else if(this->agreeableness == personalityScale[4]){
        valueHolder.append(basicWeights[personalityScale[4]]);
    }

    if(this->neuroticism == personalityScale[2]){
        valueHolder.append(basicWeights[personalityScale[2]]);
    }else if(this->neuroticism == personalityScale[3]){
        valueHolder.append(basicWeights[personalityScale[3]]);
    }else if(this->neuroticism == personalityScale[4]){
        valueHolder.append(basicWeights[personalityScale[4]]);
    }


    float result;
    if(valueHolder.length() > 0){
        result = average(valueHolder);
    }else{
        // indicates indifference
        result = -1.0;
    }
    return result;

}
float Client::idealActivity(){
    QVector<float> valueHolder;
    QHash<QString, float> basicWeights = getPersonalityWeights();
    QVector<QString> personalityScale = getFiveCatScale();



    if(this->opennessToExp == personalityScale[0]){
        valueHolder.append(basicWeights[personalityScale[0]]);
    }else if(this->opennessToExp == personalityScale[1]){
        valueHolder.append(basicWeights[personalityScale[1]]);
    }else if(this->opennessToExp == personalityScale[2]){
        valueHolder.append(basicWeights[personalityScale[2]]);
    }else if(this->opennessToExp == personalityScale[3]){
        valueHolder.append(basicWeights[personalityScale[3]]);
    }else if(this->opennessToExp == personalityScale[4]){
        valueHolder.append(basicWeights[personalityScale[4]]);
    }

    if(this->conscientiousness == personalityScale[2]){
        valueHolder.append(basicWeights[personalityScale[2]]);
    }else if(this->conscientiousness == personalityScale[1]){
        valueHolder.append(basicWeights[personalityScale[3]]);
    }else if(this->conscientiousness == personalityScale[4]){
        valueHolder.append(basicWeights[personalityScale[0]]);
    }


    float result;
    if(valueHolder.length() > 0){
        result = average(valueHolder);
    }else{
        // indicates indifference
        result = -1.0;
    }
    return result;

}
float Client::idealExcitability(){
    QVector<float> valueHolder;
    QHash<QString, float> basicWeights = getPersonalityWeights();
    QVector<QString> personalityScale = getFiveCatScale();

    if(this->opennessToExp == personalityScale[2]){
        valueHolder.append(basicWeights[personalityScale[2]]);
    }else if(this->opennessToExp == personalityScale[3]){
        valueHolder.append(basicWeights[personalityScale[3]]);
    }else if(this->opennessToExp == personalityScale[4]){
        valueHolder.append(basicWeights[personalityScale[4]]);
    }

    if(this->conscientiousness == personalityScale[0]){
        valueHolder.append(basicWeights[personalityScale[4]]);
    }else if(this->conscientiousness == personalityScale[1]){
        valueHolder.append(basicWeights[personalityScale[3]]);
    }else if(this->conscientiousness == personalityScale[2]){
        valueHolder.append(basicWeights[personalityScale[2]]);
    }

    if(this->extraversion == personalityScale[0]){
        valueHolder.append(basicWeights[personalityScale[0]]);
    }else if(this->extraversion == personalityScale[1]){
        valueHolder.append(basicWeights[personalityScale[1]]);
    }else if(this->extraversion == personalityScale[2]){
        valueHolder.append(basicWeights[personalityScale[2]]);
    }else if(this->extraversion == personalityScale[3]){
        valueHolder.append(basicWeights[personalityScale[3]]);
    }else if(this->extraversion == personalityScale[4]){
        valueHolder.append(basicWeights[personalityScale[4]]);
    }



    float result;
    if(valueHolder.length() > 0){
        result = average(valueHolder);
    }else{
        // indicates indifference
        result = -1.0;
    }
    return result;

}
float Client::idealExpressiveness(){
    QVector<float> valueHolder;
    QHash<QString, float> basicWeights = getPersonalityWeights();
    QVector<QString> personalityScale = getFiveCatScale();


    if(this->extraversion == personalityScale[2]){
        valueHolder.append(basicWeights[personalityScale[2]]);
    }else if(this->extraversion == personalityScale[3]){
        valueHolder.append(basicWeights[personalityScale[3]]);
    }else if(this->extraversion == personalityScale[4]){
        valueHolder.append(basicWeights[personalityScale[4]]);
    }

    if(this->neuroticism == personalityScale[2]){
        valueHolder.append(basicWeights[personalityScale[2]]);
    }else if(this->neuroticism == personalityScale[3]){
        valueHolder.append(basicWeights[personalityScale[3]]);
    }else if(this->neuroticism == personalityScale[4]){
        valueHolder.append(basicWeights[personalityScale[4]]);
    }

    float result;
    if(valueHolder.length() > 0){
        result = average(valueHolder);
    }else{
        // indicates indifference
        result = -1.0;
    }
    return result;

}

