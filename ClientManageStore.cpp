#include "ClientManageStore.h"
#include "ui_ClientManageStore.h"

ClientManageStore::ClientManageStore(QWidget *parent, Control *cntrl) :
    QWidget(parent),
    ui(new Ui::ClientManageStore)
{
    ui->setupUi(this);
    this->cntrl = cntrl;
    this->sideBarClient = new SidebarClient(NULL);
    sideBarClient->show();
    ui->sideBarClient->layout()->addWidget(sideBarClient);
    this->login = new Login(NULL, cntrl);
    this->browseAnimals = new BrowseAnimals(NULL,cntrl, cntrl->getModelAnimal());
    setWindowTitle("cuACS - Client Main Store");
    ui->stackedWidgetClient->layout()->addWidget(browseAnimals);
    ui->stackedWidgetClient->layout()->addWidget(login);

    switchToBrowseAnimalsView();
    connect(sideBarClient, SIGNAL(browseAnimalsView()), this, SLOT(switchToBrowseAnimalsView()));
    connect(sideBarClient, SIGNAL(backToLoginScreen()), this, SLOT(switchToCuacsAppView()));
    connect(sideBarClient, SIGNAL(showDefaultScreen()), this, SLOT(switchToDefault()));
    connect(sideBarClient, SIGNAL(editClientView()), this, SLOT(switchToEditClientView()));


    //connect(browseAnimals, SIGNAL(backToMainClientStore()), this, SLOT(switchToMainStoreClientScreen()));
    //main store button signal slots CONNECTION here
}

ClientManageStore::~ClientManageStore()
{
    delete browseAnimals;
    delete sideBarClient;
    delete login;
    delete ui;
}

void ClientManageStore::switchToCuacsAppView()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

void ClientManageStore::switchToBrowseAnimalsView()
{
    ui->stackedWidgetClient->setCurrentWidget(browseAnimals);
}

void ClientManageStore::switchToDefault()
{
    ui->stackedWidgetClient->setCurrentWidget(defaultScreen);
}

void ClientManageStore::setCurrClient(int clientID)
{
    currClient = cntrl->getSelectedClientObject(clientID);

}

void ClientManageStore::switchToEditClientView()

{
    clientProfileEdit = new EditClientDialog(this, cntrl, this->currClient);
    clientProfileEdit->show();
}

