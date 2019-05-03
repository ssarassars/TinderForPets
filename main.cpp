
#include "Control.h"
#include "CuacsAppView.h"
#include <QApplication>
#include <QDebug>

//BAD INCLUDES FOR TESTING, DELETE
#include <QVector>
#include "KuhnMunkres.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Control *cntrlObj = new Control();
    CuacsAppView *cuacsAppViewObj = new CuacsAppView(NULL, cntrlObj);
    cuacsAppViewObj->show();


    return a.exec();

}
