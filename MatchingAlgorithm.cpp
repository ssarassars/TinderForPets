#include "MatchingAlgorithm.h"

MatchingAlgorithm::MatchingAlgorithm(QVector<Animal*>& animals, QVector<Client*>& clients)
{    
    cost = 0.0;
    int count =0;

    // we first filter out all of the incomplete profiles
    for(int i=0; i<animals.length(); i++){
        Animal* currAnimal = animals.at(i);
        if(! currAnimal->profileIncomplete()){
            animalVertices.append(currAnimal);
            idToIndAnimal.insert(currAnimal->getID(), count);
            ++count;

        }
    }
    count =0;
    for(int i=0; i<clients.length(); i++){
        Client* currClient = clients.at(i);
        if(! currClient->profileIncomplete()){
            clientVertices.append(currClient);
            idToIndClient.insert(currClient->getID(), count);
            ++count;
        }

    }
    makeMatrix();

    //matrixTestPrint();


}
void MatchingAlgorithm::makeMatrix(){
    float score;
    for(int i = 0; i<clientVertices.length(); i++){
        QVector<float>* currRow = new QVector<float>();
        for(int j = 0; j<animalVertices.length(); j++){
            score = computeScore(animalVertices.at(j), clientVertices.at(i));
            currRow->append(score);
        }
        matrix.append(*currRow);
    }
}

MatchingAlgorithm::~MatchingAlgorithm(){
}

void MatchingAlgorithm::matrixTestPrint(){
    //    //test part
    /* this is for testing the matrix construction
    for(int i =0; i<this->matrix.length(); i++){
        qDebug()<<"client: "<<clientVertices.at(i)->getID();
        for(int j=0; j<this->matrix.at(0).length(); j++){
            qDebug()<<"With animal: "<<animalVertices.at(j)->getID()<<" score is: "<<this->matrix.at(i).at(j);

        }
    }*/

    qDebug()<<"Main matching";
    match();
    testOne();
    testTwo();
    testThree();
    testFour();

    //    //threshold test - in theory, best assignment would be row 1 gets the 1.4 match and row 2 gets the 0.2 match
    //    //however, with threshold at 1.4, the 1.4 match should be impossible - so instead row 1 will get 1.39 and row 2 will get 1.1
    //    QVector<QVector<float>> m;
    //    QVector<float>* rowOne = new QVector<float>();
    //    rowOne->append(1.39);
    //    rowOne->append(1.4);
    //    QVector<float>* rowTwo = new QVector<float>();
    //    rowTwo->append(0.2);
    //    rowTwo->append(1.1);
    //    m.append(*rowOne);
    //    m.append(*rowTwo);

    //    cost = hung.assign(m, assignment);

    //    for (int i = 0; i < m.length(); i++)
    //        qDebug() << "Client ID#" << i << ", Animal ID#" << assignment[i];

    //    qDebug() << "\nTotal: " << cost;

}

QMap<int, int> MatchingAlgorithm::match(){
    cost = 0.0;
    individualCosts.clear();
    QMap<int, int> matches;
    QVector<QPair<int, int>> matchLocations;
    QPair<int, int> pair;
    int cli = 0;
    int ani = 0;
    int temp1 = 0;
    int temp2 = 0;

    kmSolver.setMatrix(matrix);
    matchLocations = kmSolver.assign();

    foreach(pair, matchLocations){
        temp1 = pair.first;
        temp2 = pair.second;
        cli = clientVertices.at(temp1)->getID();
        ani = animalVertices.at(temp2)->getID();
        matches[cli]=ani;
        pair.first=cli;
        pair.second=ani;
        individualCosts[pair]=matrix[temp1][temp2];
        cost += individualCosts[pair];
    }

    //Enable following code to see content of returned matches
    QMap<int, int>::iterator i;
    for (i = matches.begin(); i != matches.end(); ++i)
        qDebug() << "Client" << i.key()<<": Animal" << i.value();

    QMap<QPair<int, int>, float>::iterator j;
    for (j = individualCosts.begin(); j != individualCosts.end(); ++j)
        qDebug() << j.key()<<": Cost" << j.value();

    qDebug()<<"Total cost:"<<cost;
    //Disable above code for clean output

    return matches;
}

float MatchingAlgorithm::getCost(){
    return cost;
}

// assumes the animal profile is complete
void MatchingAlgorithm::addAnimalVertex(Animal* animal){
    this->animalVertices.append(animal);
    idToIndAnimal.insert(animal->getID(),this->animalVertices.length()-1);
    float score = 0;
    QVector<float> currRow;
    //The matrix's rows correspond to clients and column correspond to animals
    for(int i = 0; i<clientVertices.length(); i++){
        score = computeScore(animal, clientVertices.at(i));
        currRow = matrix[i];
        currRow.append(score);
    }
}
//assumes the client profile is complete
void MatchingAlgorithm::addClientVertex(Client* client){
    this->clientVertices.append(client);
    idToIndAnimal.insert(client->getID(), this->clientVertices.length()-1);
    QVector<float>* currRow = new QVector<float>();
    float score;
    //The matrix's rows correspond to clients and column correspond to animals
    for(int i = 0; i<animalVertices.length(); i++){
        score = computeScore(animalVertices.at(i), client);
        currRow->append(score);
    }
    matrix.append(*currRow);

}

int MatchingAlgorithm::updateAnimalScore(Animal* animal){
    if(animal->profileIncomplete()){
        //return -1 if the animal profile is incomplete and could not be considered for algo
        qDebug()<<"Incomplete animal profile...so we will not update the scores for it.";
        return -1;
    }

    //in case it was there
    if(this->idToIndAnimal.contains(animal->getID())){
        float score;
        int col;
        for(int i = 0; i<clientVertices.length(); i++){
            score = computeScore(animal, clientVertices.at(i));
            col = this->idToIndAnimal[animal->getID()];
            matrix[i][col] = score;
        }

    }else{

        // in case it wasn't there (bcs it was incomplete and now is complete) or bcs it just got added
        addAnimalVertex(animal);
    }

    //return 0 for success
    return 0;
}



int MatchingAlgorithm::updateClientScore(Client* client){
    if(client->profileIncomplete()){
        //return -1 if the animal profile is incomplete and could not be considered for algo
        qDebug()<<"Incomplete client profile...so we will not update the scores for it.";
        return -1;
    }

    //in case it was there
    if(this->idToIndClient.contains(client->getID())){
        float score;
        int row = this->idToIndClient[client->getID()];
        for(int i = 0; i<animalVertices.length(); i++){
            score = computeScore(animalVertices.at(i), client);
            this->matrix[row][i] = score;
        }

    }else{
        // in case it wasn't there (bcs it was incomplete and now is complete) or bcs it just got added
        addClientVertex(client);
    }

    //return 0 for success
    return 0;
}

// this assumes that the profiles are all complete, which makes sense since they have been filtered
void MatchingAlgorithm::personalityComponents(Animal* animal, Client* client, QVector<float>* aVecPersonality,
                                              QVector<float>* cVecPersonality, QVector<float>* fullAVecPer, QVector<float>* fullCVecPer){
    // construct client vector's personality part and its parallel for animal

    int numPrefs = 9;

        float idealTimidity = client->idealTimidity();
        fullCVecPer->append(idealTimidity);
        fullAVecPer->append(animal->getTimidityNum());
        float idealSociability = client->idealSociability();
        fullCVecPer->append(idealSociability);
        fullAVecPer->append(animal->getSociabilityNum());
        float idealAggression = client->idealAggression();
        fullCVecPer->append(idealAggression);
        fullAVecPer->append(animal->getAggressionNum());
        float idealObedience = client->idealObedience();
        fullCVecPer->append(idealObedience);
        fullAVecPer->append(animal->getObedienceNum());
        float idealLoyalty = client->idealLoyalty();
        fullCVecPer->append(idealLoyalty);
        fullAVecPer->append(animal->getLoyaltyNum());
        float idealAffection = client->idealAffection();
        fullCVecPer->append(idealAffection);
        fullAVecPer->append(animal->getAffectionNum());
        float idealActivity = client->idealActivity();
        fullCVecPer->append(idealActivity);
        fullAVecPer->append(animal->getActivityNum());
        float idealExcitability = client->idealExcitability();
        fullCVecPer->append(idealExcitability);
        fullAVecPer->append(animal->getExcitabilityNum());
        float idealExpressive = client->idealExpressiveness();
        fullCVecPer->append(idealExpressive);
        fullAVecPer->append(animal->getExpressivenessNum());


    for(int i =0; i<numPrefs; i++){
        if(fullCVecPer->at(i) != -1.0){
            cVecPersonality->append(fullCVecPer->at(i));
            aVecPersonality->append(fullAVecPer->at(i));

        }
    }


}

void MatchingAlgorithm::matchPrefComponents(Animal* animal, Client* client, QVector<float>* aVec,
                                              QVector<float>* cVec, QVector<float>* fullAVec, QVector<float>* fullCVec){
    int numPrefs = 11;

    fullAVec->append(animal->getAgeNum());
    //append age label to labels vector
    fullAVec->append(animal->getGenderNum());
    fullAVec->append(animal->getSizeNum());
    fullAVec->append(animal->getKidFriendlinessNum());
    fullAVec->append(animal->getCostNum());
    fullAVec->append(animal->getCurrentTrainingNum());
    fullAVec->append(animal->getIntelligenceNum());
    fullAVec->append(animal->getTimeCommitNum());
    fullAVec->append(animal->getSheddingNum());
    fullAVec->append(animal->getAptCompatNum());
    fullAVec->append(animal->getTrainSuitNum());

    fullCVec->append(client->getAgePrefNum());
    fullCVec->append(client->getGenderPrefNum());
    fullCVec->append(client->getSizePrefNum());
    fullCVec->append(client->getKidFriendlyPrefNum());
    fullCVec->append(client->getCostPrefNum());
    fullCVec->append(client->getCurrTrainingPrefNum());
    fullCVec->append(client->getIntelligencePrefNum());
    fullCVec->append(client->getTimeCommitPrefNum());
    fullCVec->append(client->getSheddingPrefNum());
    fullCVec->append(client->getAptCompatibilityPrefNum());
    fullCVec->append(client->getTrainSuitabilityPrefNum());


    for(int i =0; i<numPrefs; i++){
        if(fullCVec->at(i) != -1.0){
            cVec->append(fullCVec->at(i));
            aVec->append(fullAVec->at(i));

        }
    }
}

float MatchingAlgorithm::computeScore(Animal* animal, Client* client){
    QVector<float> clientVector;
    QVector<float> animalVector;
    QVector<float> fullAVec;
    QVector<float> fullCVec;
    personalityComponents(animal, client,&animalVector, &clientVector, &fullAVec, &fullCVec);
    matchPrefComponents(animal, client,&animalVector, &clientVector, &fullAVec, &fullCVec);
    int clientID = client->getID();
    int animalID = animal->getID();
    this->clientAnimalTuple.first = clientID;
    this->clientAnimalTuple.second = animalID;
    this->clientScoreVectorMapFull.insert(this->clientAnimalTuple, fullCVec);
    this->animalScoreVectorMapFull.insert(this->clientAnimalTuple, fullAVec);

    float result;
    result = mse(animalVector, clientVector);

    if(!animal->isEmptyEntry(client->getAnimalPrefType()) && animal->getType()!=client->getAnimalPrefType()){
        return result+1;
    }
    else{
        return result;
    }
}

float MatchingAlgorithm::mse(QVector<float>& animalVector, QVector<float>& clientVector){

    float sumTotal = 0;
    for(int i = 0; i<animalVector.length(); i++){
        sumTotal = sumTotal + pow(animalVector.at(i) - clientVector.at(i), 2.0);
    }
    return sumTotal/animalVector.length();

}

float MatchingAlgorithm::clientScoreVectorMap(int clientID, int animalID, int position){
    float score = 0.0;
    if(clientScoreVectorMapFull.contains({clientID, animalID})){
        score = clientScoreVectorMapFull.value({clientID, animalID})[position];
    }

    return score;
}
float MatchingAlgorithm::animalScoreVectorMap(int clientID, int animalID, int position){
    float score = 0.0;
    if(animalScoreVectorMapFull.contains({clientID, animalID})){
        score = animalScoreVectorMapFull.value({clientID, animalID})[position];
    }

    return score;
}
void MatchingAlgorithm::testOne(){
    //based on "simple example" from https://www.geeksforgeeks.org/hungarian-algorithm-assignment-problem-set-1-introduction/
    //values have been divided by 10000 to avoid interfering with threshold
    qDebug()<<"Test #1";
    QVector<QVector<float>> m;
    QVector<float>* rowOne = new QVector<float>();
    rowOne->append(0.25);
    rowOne->append(0.4);
    rowOne->append(0.35);
    QVector<float>* rowTwo = new QVector<float>();
    rowTwo->append(0.4);
    rowTwo->append(0.6);
    rowTwo->append(0.35);
    QVector<float>* rowThree = new QVector<float>();
    rowThree->append(0.2);
    rowThree->append(0.4);
    rowThree->append(0.25);
    m.append(*rowOne);
    m.append(*rowTwo);
    m.append(*rowThree);

    cost = 0.0;
    individualCosts.clear();
    QMap<int, int> matches;
    QVector<QPair<int, int>> matchLocations;
    QPair<int, int> pair;
    int cli = 0;
    int ani = 0;

    kmSolver.setMatrix(m);
    matchLocations = kmSolver.assign();

    foreach(pair, matchLocations){
        cli = pair.first;
        ani = pair.second;
        matches[cli]=ani;
        individualCosts[pair]=m[cli][ani];
        cost += individualCosts[pair];
    }

    //Enable following code to see content of returned matches
    QMap<int, int>::iterator i;
    for (i = matches.begin(); i != matches.end(); ++i)
        qDebug() << "Client" << i.key()<<": Animal" << i.value();

    QMap<QPair<int, int>, float>::iterator j;
    for (j = individualCosts.begin(); j != individualCosts.end(); ++j)
        qDebug() << j.key()<<": Cost" << j.value();

    qDebug()<<"Total cost:"<<cost;

}

void MatchingAlgorithm::testTwo(){
    //based on "tricky example" from https://www.geeksforgeeks.org/hungarian-algorithm-assignment-problem-set-1-introduction/
    //values have been divided by 10000 to avoid interfering with threshold
    qDebug()<<"Test #2";
    QVector<QVector<float>> m;
    QVector<float>* rowOne = new QVector<float>();
    rowOne->append(0.15);
    rowOne->append(0.4);
    rowOne->append(0.45);
    QVector<float>* rowTwo = new QVector<float>();
    rowTwo->append(0.2);
    rowTwo->append(0.6);
    rowTwo->append(0.35);
    QVector<float>* rowThree = new QVector<float>();
    rowThree->append(0.2);
    rowThree->append(0.4);
    rowThree->append(0.25);
    m.append(*rowOne);
    m.append(*rowTwo);
    m.append(*rowThree);

    cost = 0.0;
    individualCosts.clear();
    QMap<int, int> matches;
    QVector<QPair<int, int>> matchLocations;
    QPair<int, int> pair;
    int cli = 0;
    int ani = 0;

    kmSolver.setMatrix(m);
    matchLocations = kmSolver.assign();

    foreach(pair, matchLocations){
        cli = pair.first;
        ani = pair.second;
        matches[cli]=ani;
        individualCosts[pair]=m[cli][ani];
        cost += individualCosts[pair];
    }

    //Enable following code to see content of returned matches
    QMap<int, int>::iterator i;
    for (i = matches.begin(); i != matches.end(); ++i)
        qDebug() << "Client" << i.key()<<": Animal" << i.value();

    QMap<QPair<int, int>, float>::iterator j;
    for (j = individualCosts.begin(); j != individualCosts.end(); ++j)
        qDebug() << j.key()<<": Cost" << j.value();

    qDebug()<<"Total cost:"<<cost;

}

void MatchingAlgorithm::testThree(){
    //based on "worst-case example" from http://csclab.murraystate.edu/~bob.pilgrim/445/munkres.html
    //values have been divided by 10 to avoid interfering with threshold
    qDebug()<<"Test #3";
    QVector<QVector<float>> m;
    QVector<float>* rowOne = new QVector<float>();
    rowOne->append(0.1);
    rowOne->append(0.2);
    rowOne->append(0.3);
    QVector<float>* rowTwo = new QVector<float>();
    rowTwo->append(0.2);
    rowTwo->append(0.4);
    rowTwo->append(0.6);
    QVector<float>* rowThree = new QVector<float>();
    rowThree->append(0.3);
    rowThree->append(0.6);
    rowThree->append(0.9);
    m.append(*rowOne);
    m.append(*rowTwo);
    m.append(*rowThree);

    cost = 0.0;
    individualCosts.clear();
    QMap<int, int> matches;
    QVector<QPair<int, int>> matchLocations;
    QPair<int, int> pair;
    int cli = 0;
    int ani = 0;

    kmSolver.setMatrix(m);
    matchLocations = kmSolver.assign();

    foreach(pair, matchLocations){
        cli = pair.first;
        ani = pair.second;
        matches[cli]=ani;
        individualCosts[pair]=m[cli][ani];
        cost += individualCosts[pair];
    }

    //Enable following code to see content of returned matches
    QMap<int, int>::iterator i;
    for (i = matches.begin(); i != matches.end(); ++i)
        qDebug() << "Client" << i.key()<<": Animal" << i.value();

    QMap<QPair<int, int>, float>::iterator j;
    for (j = individualCosts.begin(); j != individualCosts.end(); ++j)
        qDebug() << j.key()<<": Cost" << j.value();

    qDebug()<<"Total cost:"<<cost;

}

void MatchingAlgorithm::testFour(){
    //    threshold test - in theory, best assignment would be row 1 gets the 1.4 match and row 2 gets the 0.2 match
    //    however, with threshold at 1.4, the 1.4 match should be impossible - so instead row 1 will get 1.39 and row 2 will get 1.1

    qDebug()<<"Test #4";

    QVector<QVector<float>> m;
    QVector<float>* rowOne = new QVector<float>();
    rowOne->append(1.39);
    rowOne->append(1.4);
    QVector<float>* rowTwo = new QVector<float>();
    rowTwo->append(0.2);
    rowTwo->append(1.1);
    m.append(*rowOne);
    m.append(*rowTwo);

    cost = 0.0;
    individualCosts.clear();
    QMap<int, int> matches;
    QVector<QPair<int, int>> matchLocations;
    QPair<int, int> pair;
    int cli = 0;
    int ani = 0;

    kmSolver.setMatrix(m);
    matchLocations = kmSolver.assign();

    foreach(pair, matchLocations){
        cli = pair.first;
        ani = pair.second;
        matches[cli]=ani;
        individualCosts[pair]=m[cli][ani];
        cost += individualCosts[pair];
    }

    //Enable following code to see content of returned matches
    QMap<int, int>::iterator i;
    for (i = matches.begin(); i != matches.end(); ++i)
        qDebug() << "Client" << i.key()<<": Animal" << i.value();

    QMap<QPair<int, int>, float>::iterator j;
    for (j = individualCosts.begin(); j != individualCosts.end(); ++j)
        qDebug() << j.key()<<": Cost" << j.value();

    qDebug()<<"Total cost:"<<cost;

}

QMap<int, int> MatchingAlgorithm::getClientAnimalMap(){
    return this->match();
}

float MatchingAlgorithm::finalMatchScoreMap(int clientID, int animalID){
    float score = 0.0;
    if(individualCosts.contains({clientID, animalID})){
        score = individualCosts.value({clientID, animalID});
    }

    return score;
}
