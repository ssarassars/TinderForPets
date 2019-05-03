#ifndef MATCHINGALGORITHM_H
#define MATCHINGALGORITHM_H
#include <QVector>
#include <QMap>
#include <QPair>
#include "Animal.h"
#include "Client.h"
#include "Constants.h"
#include <QMapIterator>
#include <cmath>
#include <math.h>
#include "qdebug.h"
#include "KuhnMunkres.h"

class MatchingAlgorithm
{
public:

    MatchingAlgorithm(QVector<Animal*>& animals,QVector<Client*>& clients);
    ~MatchingAlgorithm();

    /* Function   : updateAnimalScore
     * Purpose    : maintains complete graph (bcs it is redundant to keep re-calulcating this every time the algorithm is run)
     *              must be called with every edit/add
     * Parameters : input: animal object, type: Animal*, the animal object related to the scores
     * Returns    : type: int, updated animal score
    */
    int updateAnimalScore(Animal* animal);
    /* Function   : updateClientScore
     * Purpose    : maintains complete graph (bcs it is redundant to keep re-calulcating this every time the algorithm is run)
     *              must be called with every edit/add
     * Parameters : input: client object, type: Client*, the client object related to the scores
     * Returns    : type: int, updated client score
    */
    int updateClientScore(Client* client);
    /* Function   : clientScoreVectorMap
     * Purpose    : returns score in client vector from the enum order of attributes
     * Parameters : input: clientID, type: int, the client id in match pair
     *                      animalID, type: int, the animal id in match pair
     *                      position, tyope: int, the position from enum order
     * Returns    : type: float, client score from client vector at enum position order of attribute
    */
    float clientScoreVectorMap(int clientID, int animalID, int position);
    /* Function   : animalScoreVectorMap
     * Purpose    : returns score in animal vector from the enum order of attributes
     * Parameters : input: clientID, type: int, the client id in match pair
     *                      animalID, type: int, the animal id in match pair
     *                      position, type: int, the position from enum order
     * Returns    : type: float, animal score from animal vector at enum position order of attribute
    */
    float animalScoreVectorMap(int clientID, int animalID, int position);

    /* Function   : getClientAnimalMap
     * Purpose    : returns map of client and animal ID matches
     * Parameters : input: none
     * Returns    : type: QMap<int, int>, map of client and animal ID matches
    */
    QMap<int, int> getClientAnimalMap();
    /* Function   : finalMatchScoreMap
     * Purpose    : returns score in final match score map from the enum order of attributes
     * Parameters : input: clientID, type: int, the client id in match pair
     *                      animalID, type: int, the animal id in match pair
     * Returns    : type: float, match score from final match score map
    */
    float finalMatchScoreMap(int clientID, int animalID);

private:
    QVector<Animal*> animalVertices;
    QVector<Client*> clientVertices;
    // animals - columns
    // clients - rows
    QVector<QVector<float>> matrix;
    KuhnMunkres kmSolver;
    float cost;
    QMap<QPair<int, int>, float> individualCosts;
    QMap<int, int> idToIndAnimal;
    QMap<int, int> idToIndClient;
    /*
    Function: makeMatrix
    Purpose : makes the initial matrix and updates the matrix attribute, based on animal and client vertices
    Input   : None
    Output  : None
    */
    void makeMatrix();
    /*
    Function: computeScore
    Purpose : To compute the score of a hypothetical match between a given animal and client
    Input   : Animal* a, a pointer to an animal object
              Client* c, a pointer to a client object
    Output  : return float, the score of a hypothetical match betweenthe given animal and client
    */
    float computeScore(Animal* a, Client* c);
    /* Function: mse
       Purpose : to compute the mean squared error of two given vetcors with floats
                 (in our case, these two vectors would be parallel client and animal vectors
                  where each contains a numerical score for a particular attribute )
       Input   : QVector<float>, vector containing numerical scores for particular attributes of an animal
                 QVector<float>, vector containing numerical scores for particular attributes of a client
       Output  : return float, the mean squared error of the two vectors given
    */
    float mse(QVector<float>& animalVector, QVector<float>& clientVector);
    /*
    Function : average
    Purpose  : computes the average of values given in a vector
    Input    : QVector<float>, vector of floats
    Output   : return float, the average of the given floats inside the given vector
    */
    float average(QVector<float> valueHolder);
  /*
    Function : personalityComponents
    Purpose  : computes personality components for both the animal and client vectors
    Input    : Animal* animal, pointer to animal object, needed to access personality scores
               Client* client, pointer to client object, needed to access personality scores
    Output   : output parameters: (Note: parallel vectors)
                                  QVector<float>* an animal vector of floats (scores of particular personality atributes)
                                  QVector<float>* a client vector of floats (scores of particular personality atributes)
    */
    void personalityComponents(Animal* animal, Client* client, QVector<float>* aVecPersonality, QVector<float>* cVecPersonality, QVector<float>* fullAVecPer, QVector<float>* fullCVecPer);
    /*
    Function : matchPrefComponents
    Purpose  : computes matching preferences components for both the animal and client vectors
    Input    : Animal* animal, pointer to animal object, needed to access matching preferences scores
               Client* client, pointer to client object, needed to access matching preferences scores
    Output   : output parameters: (Note: parallel vectors)
                                  QVector<float>* an animal vector of floats (scores of particular matching preferences atributes)
                                  QVector<float>* a client vector of floats (scores of particular matching preferences atributes)
    */
  void matchPrefComponents(Animal* animal, Client* client, QVector<float>* aVecPersonality, QVector<float>* cVecPersonality, QVector<float>* fullAVec, QVector<float>* fullCVec);
    /*
     Function : addClientVertex
     Purpose  : updates the list of client vertices being maintained
     Input    : Client* , a pointer to a client object
     Output   : None
    */
  void addClientVertex(Client* client);
    /*
     Function : addClientVertex
     Purpose  : updates the list of animal vertices being maintained
     Input    : Animal*, a pointer to an animal object
     Output   : None
    */
    void addAnimalVertex(Animal* animal);

    //Just a test method, used for launching tests
    void matrixTestPrint();

    QPair<int, int> clientAnimalTuple;
    QMap<QPair<int, int>, QVector<float>> clientScoreVectorMapFull;
    QMap<QPair<int, int>, QVector<float>> animalScoreVectorMapFull;
    /*
     Function : match
     Purpose  : runs the Kuhn-Munkres algorithm to derive the optimal set of animal-client matches from the score matrix
     Input    : None
     Output   : matches, a QMap<int, int> with client IDs as keys and the matched animal IDs as values
    */
    QMap<int, int> match();
    /*
     Function : testOne
     Purpose  : proves that this class can find the optimal set of matches in an easy case
                based on "simple example" from https://www.geeksforgeeks.org/hungarian-algorithm-assignment-problem-set-1-introduction/
                note that values have been divided by 10000 to avoid interfering with threshold
     Input    : None
     Output   : None
    */
    void testOne();
    /*
     Function : testTwo
     Purpose  : proves that this class can find the optimal set of matches in a moderately hard case
                based on "tricky example" from https://www.geeksforgeeks.org/hungarian-algorithm-assignment-problem-set-1-introduction/
                note that values have been divided by 10000 to avoid interfering with threshold
     Input    : None
     Output   : None
    */
    void testTwo();
    /*
     Function : testThree
     Purpose  : proves that this class can find the optimal set of matches in a hard case
                based on "worst-case example" from http://csclab.murraystate.edu/~bob.pilgrim/445/munkres.html
                note that values have been divided by 10 to avoid interfering with threshold
     Input    : None
     Output   : None
    */
    void testThree();
    /*
     Function : testFour
     Purpose  : proves that matches of 1.4 or higher are not allowed
                in theory, best assignment would be row 1 gets the 1.4 match and row 2 gets the 0.2 match
                however, with threshold at 1.4, the 1.4 match should be impossible - so instead row 1 will get 1.39 and row 2 will get 1.1
     Input    : None
     Output   : None
    */
    void testFour();
    float getCost();



};

#endif // MATCHINGALGORITHM_H
