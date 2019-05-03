#ifndef CUACSAPPVIEW_H
#define CUACSAPPVIEW_H

#include <QWidget>
#include "Login.h"
#include "StaffManageStore.h"
#include "Control.h"
#include "ClientManageStore.h"

class StaffManageStore;
class Login;
class ClientManageStore;
class Control;

namespace Ui {
class CuacsAppView;
}

class CuacsAppView : public QWidget
{
    Q_OBJECT

public:
    explicit CuacsAppView(QWidget *parent = 0, Control *cntrl =0);
    ~CuacsAppView();


private:
    Ui::CuacsAppView *ui;
    Login *loginView;
    StaffManageStore *manageStoreView;
    ClientManageStore *clientStoreView;
    Control *cntrl;

public slots:
    /*
    Function   : switchToStaffStoreView
    Purpose    : displays interface for Staff users
    Parameters :
    */
    void switchToStaffStoreView();
    /*
    Function   : switchToClientHomeView
    Purpose    : displays interface for given client user
    Parameters :
               input:
               currClientID, type, int: ID of client currently logging in
    */
    void switchToClientHomeView(int currClientID);

};

#endif // CUACSAPPVIEW_H
