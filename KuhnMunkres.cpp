#include "KuhnMunkres.h"
#include "float.h"
#include <QDebug>

KuhnMunkres::KuhnMunkres(){
    pathRowAddress = 0;
    pathColAddress = 0;
}

KuhnMunkres::KuhnMunkres(QVector<QVector<float>> m)
{
    pathRowAddress = 0;
    pathColAddress = 0;
    this->matrix = m;
    matrixSetup();
    rowsCovered.fill(0, rows);
    colsCovered.fill(0, cols);
}

void KuhnMunkres::setMatrix(QVector<QVector<float>> m){
    pathRowAddress = 0;
    pathColAddress = 0;
    this->matrix = m;
    matrixSetup();
    rowsCovered.fill(0, rows);
    colsCovered.fill(0, cols);
}

void KuhnMunkres::matrixSetup(){
    rows = matrix.length();
    cols = matrix.at(0).length();
    stateMatrix.clear();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > 1.3999){
                matrix[i][j] = 10000;
            }
        }
    }
    //Establishing threshold - anything greater than 1.3999 will be almost unchoosable


    for (int i = 0; i < rows; i++) {
        QVector<int>* currRow = new QVector<int>();
        for (int j = 0; j < cols; j++) {
            currRow->append(0);
        }
        stateMatrix.append(*currRow);
    }
}


void KuhnMunkres::printMatrix(){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            qDebug()<<matrix[i][j];
        }
        qDebug()<<"End of row\n";
    }
}

void KuhnMunkres::printMatrix(int stepNo){
    QString result = "";

    for (int i = 0; i < rows; i++) {
        result.clear();
        for (int j = 0; j < cols; j++) {
            //qDebug()<<matrix[i][j];
            result += QString::number(stateMatrix[i][j]);
        }
        qDebug()<<result;
    }

    qDebug()<<"";
    qDebug()<<"Step"<<stepNo;
}

QVector<QPair<int, int>> KuhnMunkres::assign(){

    bool finished = false;
    int stepNo = 1;
    QVector<QPair<int, int>> assignments;

    while (!finished){
        if (stepNo == 1) {

            stepNo = stepOne();

            //finished = true;
        }
        if (stepNo == 2) {
            stepNo = stepTwo();
        }
        if (stepNo == 3) {
            stepNo = stepThree();
        }
        if (stepNo == 4) {
            stepNo = stepFour();
        }
        if (stepNo == 5) {
            stepNo = stepFive();
        }
        if (stepNo == 6) {
            stepNo = stepSix();
        }
        if (stepNo == 7) {
            finished = true;
        }

    }
    assignments = storeIndexes(assignments);
    return assignments;

}

int KuhnMunkres::stepOne(){
    float min;
    for (int i = 0; i < rows; i++) {
        min = FLT_MAX;
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] < min)
                min = matrix[i][j];
        }
        for (int k = 0; k < cols; k++) {
            matrix[i][k] -= min;
        }
    }

    //Column subtraction (unnecessary?)
    //    for (int i = 0; i < cols; i++) {
    //        min = FLT_MAX;
    //        for (int j = 0; j < rows; j++) {
    //            if (matrix[j][i] < min)
    //                min = matrix[j][i];
    //        }
    //        for (int k = 0; k < rows; k++) {
    //            matrix[k][i] -= min;
    //        }
    //    }

    return 2;
}

int KuhnMunkres::stepTwo(){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (matrix[i][j] == 0 && rowsCovered[i] == 0 && colsCovered[j] == 0) {
                stateMatrix[i][j] = 1;
                rowsCovered[i] = 1;
                colsCovered[j] = 1;
            }
        }
    }
    for (int i = 0; i < rows; i++) {
        rowsCovered[i] = 0;
    }
    for (int j = 0; j < cols; j++) {
        colsCovered[j] = 0;
    }

    return 3;
}

int KuhnMunkres::stepThree(){
    int colsFinished;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (stateMatrix[i][j] == 1) {
                colsCovered[j] = 1;
            }
        }
    }

    colsFinished = 0;
    for (int i = 0; i < cols; i++) {
        if (colsCovered[i] == 1) {
            colsFinished += 1;
        }
    }

    if (colsFinished >= cols || colsFinished >= rows) {
        return 7;
    }
    else {
        return 4;
    }
}

void KuhnMunkres::locateUncoveredZero(int &row, int &col) {
    row = -1;
    col = -1;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0 && rowsCovered[i] == 0 && colsCovered[j] == 0) {
                row = i;
                col = j;
                return;
            }
        }
    }
}

bool KuhnMunkres::rowStarred(int row) {
    for (int i = 0; i < cols; i++)
        if (stateMatrix[row][i] == 1)
            return true;
    return false;
}

int KuhnMunkres::locateRowStar(int row) {
    int col = -1;
    for (int i = 0; i < cols; i++)
        if (stateMatrix[row][i] == 1)
            col = i;
    return col;
}

int KuhnMunkres::stepFour(){
    int row = -1;
    int col = -1;

    while (true) {
        locateUncoveredZero(row, col);

        if (row == -1) {
            return 6;
        }
        else
        {
            stateMatrix[row][col] = 2;
            if (rowStarred(row)) {
                col = locateRowStar(row);
                rowsCovered[row] = 1;
                colsCovered[col] = 0;
            }
            else
            {

                pathRowAddress = row;
                pathColAddress = col;
                return 5;
            }
        }
    }
}

int KuhnMunkres::locateColStar(int col) {
    int row = -1;
    for (int i = 0; i < rows; i++)
        if (stateMatrix[i][col] == 1)
            row = i;
    return row;
}

int KuhnMunkres::locateRowPrime(int row) {
    int col = -1;
    for (int j = 0; j < cols; j++)
        if (stateMatrix[row][j] == 2)
            col = j;
    return col;
}

void KuhnMunkres::augmentPath(int path[][2], int pCount) {
    //qDebug()<<path[0][0];
    //qDebug()<<path[0][1];
    for (int p = 0; p < pCount; p++) {
        if (stateMatrix[path[p][0]][path[p][1]] == 1){
            stateMatrix[path[p][0]][path[p][1]] = 0;
        }
        else {
            stateMatrix[path[p][0]][path[p][1]] = 1;
        }
    }
}

int KuhnMunkres::stepFive(){
    bool done;
    int r = -1;
    int c = -1;
    int pathSize = 0;

    //maximum length of augmented path is (min(rows, cols) * 2) + 1

    if (rows < cols) {
        pathSize = (rows * 2) + 1;
    }
    else {
        pathSize = (cols * 2) + 1;
    }

    int path [pathSize][2] = {{}};



    int path_count = 1;
    path[path_count - 1][0] = pathRowAddress;
    path[path_count - 1][1] = pathColAddress;
    done = false;
    while (!done)
    {
        r = locateColStar(path[path_count - 1][1]);

        if (r > -1)
        {
            path_count += 1;
            path[path_count - 1][0] = r;
            path[path_count - 1][1] = path[path_count - 2][1];
        }
        else {
            done = true;
        }
        if (!done)
        {
            c = locateRowPrime(path[path_count - 1][0]);
            path_count += 1;
            path[path_count - 1][0] = path[path_count - 2][0];
            path[path_count - 1][1] = c;
        }
    }

    augmentPath(path, path_count);

    //now resetting to go back to step 3

    for (int i = 0; i < rows; i++) {
        rowsCovered[i] = 0;
    }
    for (int j = 0; j < cols; j++) {
        colsCovered[j] = 0;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (stateMatrix[i][j] == 2) {
                stateMatrix[i][j] = 0;
            }
        }
    }

    return 3;
}

int KuhnMunkres::stepSix(){
    float min = FLT_MAX;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (rowsCovered[i] == 0 && colsCovered[j] == 0) {
                if (matrix[i][j] < min) {
                    min = matrix[i][j];
                }
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (rowsCovered[i] == 1)
                matrix[i][j] += min;
            if (colsCovered[j] == 0)
                matrix[i][j] -= min;
        }
    }
    return 4;
}

QVector<QPair<int, int>> KuhnMunkres::storeIndexes(QVector<QPair<int, int>> assignments) {
    for (int i = 0; i < rows; i++) {
        QPair<int, int> pair;
        for (int j = 0; j < cols; j++) {
            if (stateMatrix[i][j] == 1){
                pair.first = i;
                pair.second = j;
            }
        }
        assignments.append(pair);
    }
    return assignments;
}
