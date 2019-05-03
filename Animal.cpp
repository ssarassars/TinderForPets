
#include "Animal.h"

Animal::Animal(int id, QString name, QString type, QString gender, QString age, QString size,
               QString shedding, QString cost, QString timidity,  QString sociability, QString aggression, QString obedience,
               QString loyalty, QString affection, QString activity, QString excitability, QString expressiveness,
               QString trainingSuitability, QString currentTraining, QString intelligence, QString apartmentCompatibility,
               QString timeCommitment,QString kidFriendliness)
{
 this->id = id;
 this->name = name;
 this->type = type;
 this->gender = gender;
 this->age = age;
 this->size = size;
 this->shedding = shedding;
 this->cost = cost;
 this->timidity = timidity;
 this->sociability = sociability;
 this->aggression = aggression;
 this->obedience = obedience;
 this->loyalty = loyalty;
 this->affection = affection;
 this->activity = activity;
 this->excitability = excitability;
 this->expressiveness = expressiveness;
 this->trainingSuitability = trainingSuitability;
 this->currentTraining =currentTraining;
 this->intelligence = intelligence;
 this->apartmentCompatibility = apartmentCompatibility;
 this->timeCommitment = timeCommitment;
 this->kidFriendliness = kidFriendliness;

}

Animal::~Animal(){
}

// --- getters ---

int Animal::getID() const{
    return id;
}
QString Animal::getName() const{
    return name;
}
QString Animal::getType() const{
    return type;
}
QString Animal::getGender() const{
    return gender;
}
QString Animal::getAge() const{
    return age;
}
QString Animal::getSize() const{
    return size;
}

QString Animal::getShedding() const{
    return shedding;
}

QString Animal::getCost() const{
    return cost;
}
QString Animal::getTimidity() const{
    return timidity;
}
QString Animal::getSociability() const{
    return sociability;
}
QString Animal::getAggression() const{
    return aggression;
}
QString Animal::getObedience() const{
    return obedience;
}
QString Animal::getLoyalty() const{
    return loyalty;
}

QString Animal::getAffection() const{
    return affection;
}
QString Animal::getActivity() const{
    return activity;
}
QString Animal::getExcitability() const{
    return excitability;
}

QString Animal::getExpressiveness() const{
    return expressiveness;
}
QString Animal::getTrainingSuitability() const{
    return trainingSuitability;
}
QString Animal::getCurrentTraining() const{
    return currentTraining;
}
QString Animal::getIntelligence() const{
    return intelligence;
}

QString Animal::getApartmentCompatibility() const{
    return apartmentCompatibility;
}
QString Animal::getTimeCommitment() const{
    return timeCommitment;
}
QString Animal:: getKidfriendliness() const{
    return kidFriendliness;
}
// --- getters values ---

//int Animal::getGenderValue() const{
//    if(gender[0] == "M"){
//        return 0;
//    }else{
//        return 1;
//    }
//}



float Animal::getGenderNum() {
   return genderToNum(this->gender);
}
float Animal::genderToNum(QString gender){
    if(isEmptyEntry(gender)){
        return -1.0;
    }
    QString lGender = gender.toLower();
    if(lGender == "male"){
        return 0.0;
    }
    else{
        // female
        return 1;
    }
}


float Animal::getAgeNum() {
    return ageToNum(this->age);
}
float Animal::ageToNum(QString age){
    if(isEmptyEntry(age)){
        return -1.0;
    }
    QString lAge = age.toLower();
    if(lAge == "baby"){
        return 0.0;
    }
    else if(lAge == "young adult"){
        return 0.25;
    }
    else if(lAge == "adult"){
        return 0.5;
    }
    else if(lAge == "old adult"){
        return 0.75;
    }
    else{
        //senior
        return 1.0;
    }
}

float Animal::getSizeNum() {
   return sizeToNum(this->size);
}
float Animal::sizeToNum(QString size){
    if(isEmptyEntry(size)){
        return -1.0;
    }
    QString lSize = size.toLower();
    if(lSize == "very small"){
        return 0.0;
    }
    else if(lSize == "small"){
        return 0.25;
    }
    else if(lSize == "medium"){
        return 0.5;
    }
    else if(lSize == "large"){
        return 0.75;
    }
    else{
        // very large
        return 1.0;
    }
}



float Animal::getSheddingNum() {
    return shedToNum(this->shedding);
}
float Animal::shedToNum(QString shed){
    if(isEmptyEntry(shed)){
        return -1.0;
    }
    QString lShed = shed.toLower();
    if(lShed == "very low"){
        return 0.0;
    }
    else if(lShed == "low"){
        return 0.25;
    }
    else if(lShed == "average"){
        return 0.5;
    }
    else if(lShed == "high"){
        return 0.75;
    }
    else {
        // very high
        return 1.0;
    }
}


float Animal::getTimidityNum() {
    return fiveOptNonPhysAttToNum(timidity);
}
float Animal::getSociabilityNum() {
    return fiveOptNonPhysAttToNum(sociability);
}
float Animal::getAggressionNum() {
    return fiveOptNonPhysAttToNum(aggression);
}
float Animal::getObedienceNum(){
    return fiveOptNonPhysAttToNum(obedience);
}
float Animal::getLoyaltyNum() {
    return fiveOptNonPhysAttToNum(loyalty);
}
float Animal::getAffectionNum() {
    return fiveOptNonPhysAttToNum(affection);
}
float Animal::getActivityNum() {
    return fiveOptNonPhysAttToNum(activity);
}
float Animal::getExcitabilityNum() {
    return fiveOptNonPhysAttToNum(excitability);
}
float Animal::getExpressivenessNum() {
    return fiveOptNonPhysAttToNum(expressiveness);
}


float Animal::getTrainSuitNum() {
    return fiveOptNonPhysAttToNum(trainingSuitability);
}
float Animal::trainSuitToNum(QString trainSuit){
    if(isEmptyEntry(trainSuit)){
        return -1.0;
    }
    return fiveOptNonPhysAttToNum(trainSuit);
}




float Animal::getCurrentTrainingNum() {
    return currTrainToNum(this->currentTraining);
}
float Animal::currTrainToNum(QString currTrain){
    if(isEmptyEntry(currTrain)){
        return -1.0;
    }
    QString lCurrTrain = currTrain.toLower();
    if(lCurrTrain == "untrained"){
        return 0.0;
    }
    else if(lCurrTrain == "some training"){
        return 0.33333;
    }
    else if(lCurrTrain == "well trained"){
        return 0.66666;
    }
    else{
        //highly trained
        return 1.0;
    }
}


float Animal::getIntelligenceNum(){
    return fiveOptNonPhysAttToNum(intelligence);
}
float Animal::intelToNum(QString intel){
    if(isEmptyEntry(intel)){
        return -1.0;
    }
    return fiveOptNonPhysAttToNum(intel);
}



float Animal::getKidFriendlinessNum() {
   return kidFriendToNum(this->kidFriendliness);
}
float Animal::kidFriendToNum(QString kidFriend){
    if(isEmptyEntry(kidFriend)){
        return -1.0;
    }
    QString lKidFriend = kidFriend.toLower();
    if(lKidFriend == "not at all"){
        return 0.0;
    }
    else if(lKidFriend == "slightly"){
        return 0.33333;
    }
    else if(lKidFriend == "moderately"){
        return 0.66666;

    }else{
        return 1.0;
    }
}



float Animal::getCostNum() {
    return threeOptAttToNum(cost);

}
float Animal::costToNum(QString costIn){
    if(isEmptyEntry(costIn)){
        return -1.0;
    }
    return threeOptAttToNum(costIn);
}


float Animal::getTimeCommitNum() {
    return threeOptAttToNum(timeCommitment);
}
float Animal::timeCommitToNum(QString timeCommit){
    if(isEmptyEntry(timeCommit)){
        return -1.0;
    }
    return threeOptAttToNum(timeCommit);
}



float Animal::getAptCompatNum() {
    return aptCompatToNum(this->apartmentCompatibility);
}
float Animal::aptCompatToNum(QString aptCompat){
    if(isEmptyEntry(aptCompat)){
        return -1.0;
    }
    QString lAptCompat = aptCompat.toLower();
    if(lAptCompat == "not suitable"){
        return 0.0;
    }
    else if(lAptCompat == "with training"){
        return 0.5;
    }
    else{
        //suitable
        return 1.0;
    }
}



float Animal::fiveOptNonPhysAttToNum(QString opt) {
    QString lOpt = opt.toLower();
    if(lOpt.contains("not at all")){
        return 0.0;
    }
    else if(lOpt.contains("not very")){
        return 0.25;
    }
    else if(lOpt.contains("moderately")){
        return 0.5;
    }
    else if(lOpt.contains("very")){
        return 1.0;
    }
    else{
        // the one above moderately.
        // Made into an else case, since it varies according to the attribute.
        return 0.75;
    }
}
float Animal::threeOptAttToNum(QString opt){
    QString lOpt = opt.toLower();
    if(lOpt.contains("low")){
        return 0.0;
    }
    else if(lOpt.contains("average")){
        return 0.5;
    }
    else{
        //high
        return 1.0;
    }

}


// --------Setters------
void Animal::setName(QString newName){
    this->name = newName;
}
void Animal::setType(QString newType){
    this->type = newType;
}
void Animal::setGender(QString newGender){
    this->gender = newGender;
}
void Animal::setAge(QString newAge){
    this->age = newAge;
}

void Animal::setSize(QString newSize){
    this->size = newSize;
}

void Animal::setShedding(QString newShedding) {
    this->shedding = newShedding;
}

void Animal::setTimidity(QString newTimidity){
    this->timidity = newTimidity;
}

void Animal::setSociability(QString newSociability){
    this->sociability = newSociability;
}
void Animal::setAggression(QString newAggression){
    this->aggression = newAggression;
}
void Animal::setObedience(QString newObedience) {
    this->obedience = newObedience;
}

void Animal::setLoyalty(QString newLoyalty){
    this->loyalty = newLoyalty;
}
void Animal::setAffection(QString newAffection){
    this->affection = newAffection;
}
void Animal::setActivity(QString newActivity){
    this->activity = newActivity;
}
void Animal::setExcitability(QString newExcitability){
    this->excitability = newExcitability;
}
void Animal::setExpressiveness(QString newExpressiveness){
    this->expressiveness = newExpressiveness;
}

void Animal::setTrainingSuitability(QString newTrainingSuitability){
    this->trainingSuitability = newTrainingSuitability;
}

void Animal::setCurrentTraining(QString newCurrentTraining){
    this->currentTraining = newCurrentTraining;
}

void Animal::setIntelligence(QString newIntelligence){
    this->intelligence = newIntelligence;
}

void Animal::setCost(QString newCost){
    this->cost = newCost;
}

void Animal::setTimeCommitment(QString newTime){
    this->timeCommitment = newTime;
}

void Animal::setApartmentCompatibility(QString newAptComptibility){
    this->apartmentCompatibility = newAptComptibility;
}
void Animal::setKidFriendliness(QString newKidfriendly){
    this->kidFriendliness = newKidfriendly;
}
bool Animal::isEmptyEntry(QString entry){
    if(entry == EMPTYENTRY || entry == ""){
        return true;
    }
    return false;
}
bool Animal::profileIncomplete(){
    if(isEmptyEntry(this->age) || isEmptyEntry(this->gender) || isEmptyEntry(this->type)
            || isEmptyEntry(this->size) || isEmptyEntry(this->kidFriendliness) || isEmptyEntry(this->cost)
            || isEmptyEntry(this->kidFriendliness) || isEmptyEntry(this->cost) || isEmptyEntry(this->obedience)
            || isEmptyEntry(this->loyalty) || isEmptyEntry(this->affection) || isEmptyEntry(this->expressiveness)
            || isEmptyEntry(this->currentTraining) || isEmptyEntry(this->intelligence) || isEmptyEntry(this->timeCommitment)
            || isEmptyEntry(this->shedding) || isEmptyEntry(this->apartmentCompatibility) || isEmptyEntry(this->excitability)
            || isEmptyEntry(this->timidity) || isEmptyEntry(this->activity) || isEmptyEntry(this->sociability)
            || isEmptyEntry(this->trainingSuitability) || isEmptyEntry(this->aggression)){
        return true;

    }
    return false;
}
