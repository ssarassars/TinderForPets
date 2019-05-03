#ifndef CLIENTMANAGESTORE_H
#define CLIENTMANAGESTORE_H
#include "Control.h"
#include "BrowseAnimals.h"
#include <QWidget>
#include <QDebug>
#include "SidebarClient.h"
#include "EditClientDialog.h"
#include "Login.h"
#include "Default.h"
#include "Client.h"

class Control;
class EditClientDialog;
class BrowseAnimals;
class SidebarClient;
class Login;
class Default;

namespace Ui {
class ClientManageStore;
}

class ClientManageStore : public QWidget
{
    Q_OBJECT

public:
    explicit ClientManageStore(QWidget *parent = 0, Control* cntrl =0);
    /*
    Function   : setCurrClient
    Purpose    :
    Parameters : input :
                index, type: QModelIndex, used to locate a piece of data in the model
    */
    void setCurrClient(int clientID);
    ~ClientManageStore();

private slots:
//    void on_exploreAnimals_clicked();
    void switchToCuacsAppView();
    void switchToBrowseAnimalsView();
    void switchToDefault();
    void switchToEditClientView();

private:
    Ui::ClientManageStore *ui;
    Control *cntrl;
    Default *defaultScreen;
    BrowseAnimals *browseAnimals;
    EditClientDialog *clientProfileEdit;
    SidebarClient *sideBarClient;
    Login *login;
    Client *currClient;

};

#endif // CLIENTMANAGESTORE_H
