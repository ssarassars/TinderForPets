#include "CuacsAppView.h"
#include "ui_CuacsAppView.h"

CuacsAppView::CuacsAppView(QWidget *parent, Control *cntrl) :
    QWidget(parent),
    ui(new Ui::CuacsAppView)
{
    this->cntrl = cntrl;
    this->manageStoreView = new StaffManageStore(NULL, cntrl);
    this->loginView = new Login(NULL, cntrl);
    this->clientStoreView = new ClientManageStore(NULL, cntrl);
    ui->setupUi(this);
    setWindowTitle("cuACS - Carleton University Animal Care System");
    ui->stackedWidget->insertWidget(1, loginView);
    ui->stackedWidget->insertWidget(2, manageStoreView);
    ui->stackedWidget->insertWidget(3, clientStoreView);
    ui->stackedWidget->setCurrentIndex(1);
    connect(loginView, SIGNAL(loginPassedAsStaff()), this, SLOT(switchToStaffStoreView()));
    connect(loginView, SIGNAL(loginPassedAsClient(int)), this , SLOT(switchToClientHomeView(int)));

}

CuacsAppView::~CuacsAppView()
{
    delete manageStoreView;
    delete loginView;
    delete clientStoreView;
    delete ui;
}
void CuacsAppView::switchToStaffStoreView(){
    ui->stackedWidget->setCurrentIndex(2);
}
void CuacsAppView::switchToClientHomeView(int currClientID){
    clientStoreView->setCurrClient(currClientID);
    ui->stackedWidget->setCurrentIndex(3);
}
