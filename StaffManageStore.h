#ifndef STAFFMANAGESTORE_H
#define STAFFMANAGESTORE_H

#include <QWidget>
#include "Control.h"
#include "ManageClientsView.h"
#include "ManageAnimalsView.h"
#include "ManageMatchesView.h"
#include "AnimalTableModel.h"
#include "ClientTableModel.h"
#include "SidebarStaff.h"
#include "DBHandler.h"
#include "Animal.h"
#include "Client.h"
#include "Login.h"
#include "Store.h"
#include "Default.h"
#include <QDebug>

class Control;
class Store;
class Login;
class SidebarStaff;
class ManageClientsView;
class ManageAnimalsView;
class ManageMatchesView;
class Default;

namespace Ui {
class StaffManageStore;
}

class StaffManageStore : public QWidget
{
    Q_OBJECT

public:
    explicit StaffManageStore(QWidget *parent = 0, Control* cntrl =0);
    ~StaffManageStore();
    /*
       Function   : showScreen
       Purpose    : displays the manage store ui
       Parameters : none

       */
       void showScreen();
   //signals:
   //    void manageAnimalsOptionWanted();
   //    void manageClientsOptionWanted();

   private slots:
       /*
       Function   : showManageAnimalsView
       Purpose    : hides current view and displays manage animals view ui after call to control
       Parameters : none

       */
       void showManageAnimalsView();
       /*
       Function   : presentMatches
       Purpose    : presents a table of matches that can be clicked to view match details
       Parameters : none

       */
       void presentMatches();
       /*
       Function   : showManageClientsView
       Purpose    : display all clients of cuACS in a table which can be clicked to view individual client details
       Parameters : none

       */
       void showManageClientsView();

       /*
       Function   : switchToCuacsLogin
       Purpose    : returns to login screen
       Parameters : none

       */
       void switchToCuacsLogin();


private:
    Ui::StaffManageStore *ui;
        Control *cntrl;
        Login *login;
        Default *defaultScreen;
        SidebarStaff *sideBarStaff;
        ManageClientsView *manageClientsView;
        ManageAnimalsView *manageAnimalsView;
        ManageMatchesView *manageMatchesView;
};

#endif // STAFFMANAGESTORE_H
