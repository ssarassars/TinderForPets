#ifndef KUHNMUNKRES_H
#define KUHNMUNKRES_H

#include <QVector>
#include <QPair>


class KuhnMunkres
{
public:
    KuhnMunkres();
    KuhnMunkres(QVector<QVector<float>>);
    void setMatrix(QVector<QVector<float>>);
    /*
    Function   : printMatrix
    Purpose    : quick and dirty print of the values in the matrix
    Parameters : none
    */
    void printMatrix();
    /*
    Function   : printMatrix
    Purpose    : quick and dirty print of the values in the stateMatrix (starred/primed zero locations)
    Parameters : input: stepNo, type, int: tells us which step the state Matrix is in (for debugging)
    */
    void printMatrix(int stepNo);
    /*
    Function   : assign
    Purpose    : runs the whole Kuhn-Munkres algorithm in a loop until done
    Parameters : output: assignments, type: QVector<QPair<int, int>>, vector of QPair objects containing x and y coordinates (of the starred zeros)
    */
    QVector<QPair<int, int>> assign();
    float totalError();
private:
    QVector<QVector<float>> matrix;
    int rows;
    int cols;

    int pathRowAddress;
    int pathColAddress;
    QVector<QVector<int>> stateMatrix;
    QVector<int> rowsCovered;
    QVector<int> colsCovered;

    /*
    Function   : matrixSetup
    Purpose    : initializes stateMatrix (which zeroes are starred/primed/unstarred), establishes threshold (matches above a certain error rating will not be allowed)
    Parameters : none
    */
    void matrixSetup();
    /*
    Function   : stepOne
    Purpose    : for each row of the matrix, finds the smallest element and subtracts it from every element in its row
    Parameters : output: stepNo, type: int, tells the loop to head to step 2
    */
    int stepOne();
    /*
    Function   : stepTwo
    Purpose    : finds a 0 in the matrix, stars it if there is no starred zero in its row or column, repeats for each element in the matrix
    Parameters : output: stepNo, type: int, tells the loop to head to step 3
    */
    int stepTwo();
    /*
    Function   : stepThree
    Purpose    : covers each column with a starred zero; if there are as many columns covered as there are columns OR rows, the process is finished, otherwise keep going
    Parameters : output: stepNo, type: int, tells the loop to head to step 7 if finished or 4 if not
    */
    int stepThree();
    /*
    Function   : stepFour
    Purpose    : checks for uncovered zeros
    Parameters : output: stepNo, type: int, tells the loop to head to step 5 or 6
    */
    int stepFour();
    /*
    Function   : stepFive
    Purpose    : augmenting path algorithm for solving maximal matching
    Parameters : output: stepNo, type: int, tells the loop to head back to step 3
    */
    int stepFive();
    /*
    Function   : stepSix
    Purpose    : adds smallest uncovered value to each element of each covered row, subtracts smallest uncovered value from each element of each covered column
    Parameters : output: stepNo, type: int, tells the loop to head back to step 4
    */
    int stepSix();
    /*
    Function   : locateUncoveredZero
    Purpose    : finds row/column location of a zero that has not been "covered" (had a line drawn through it)
    Parameters : input/output: row, type: &int, row coordinate of uncovered zero (-1 if not found)
                               col, type: &int, column coordinate of uncovered zero (-1 if not found)
    */
    void locateUncoveredZero(int &row, int &col);
    /*
    Function   : rowStarred
    Purpose    : checks to see if given row contains a starred zero
    Parameters : input: row, type: int, row being checked
                 output: type: bool, whether or not row had starred zero
    */
    bool rowStarred(int row);
    /*
    Function   : locateRowStar
    Purpose    : finds starred zero in given row
    Parameters : input: row, type: int, row being checked
                 output: col, type: int, column location of starred zero (-1 if not found)
    */
    int locateRowStar(int row);
    /*
    Function   : locateColStar
    Purpose    : finds starred zero in given column
    Parameters : input: col, type: int, row being checked
                 output: row, type: int, column location of starred zero (-1 if not found)
    */
    int locateColStar(int col);
    /*
    Function   : locateRowPrime
    Purpose    : finds primed zero in given row
    Parameters : input: row, type: int, row being checked
                 output: col, type: int, column location of primed zero (-1 if not found)
    */
    int locateRowPrime(int row);
    /*
    Function   : augmentPath
    Purpose    : uses augmented path array to star/unstar zeros
    Parameters : input: path, type: int[][], augmented path array
                        pCount, type: int, tells the for loop how long to execute for
    */
    void augmentPath(int path[][2], int pCount);
    /*
    Function   : storeIndexes
    Purpose    : for MatchingAlgorithm - stores row and column coordinates of starred zeros (i.e., chosen assignments) for easy access
    Parameters : input/output: assignments, type: QVector<QPair<int, int>>, vector of QPair objects containing x and y coordinates
    */
    QVector<QPair<int, int>> storeIndexes(QVector<QPair<int, int>> assignments);
};

#endif // KUHNMUNKRES_H
