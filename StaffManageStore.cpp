#include "StaffManageStore.h"
#include "ui_StaffManageStore.h"

StaffManageStore::StaffManageStore(QWidget *parent, Control *cntrl) :
    QWidget(parent),
    ui(new Ui::StaffManageStore)
  {
      ui->setupUi(this);
      this->cntrl = cntrl;
      this->sideBarStaff = new SidebarStaff(NULL);
      sideBarStaff->show();
      ui->sideBarStaff->layout()->addWidget(sideBarStaff);
      this->defaultScreen = new Default(NULL);
      this->login = new Login(NULL, cntrl);
      this->manageClientsView = new ManageClientsView(NULL,cntrl, cntrl->getModelClient());
      this->manageAnimalsView = new ManageAnimalsView(NULL,cntrl, cntrl->getModelAnimal());
      this->manageMatchesView = new ManageMatchesView(NULL, cntrl, cntrl->getModelMatch());
      setWindowTitle("cuACS - Staff Manage Store");
      ui->stackedWidgetStaff->layout()->addWidget(manageAnimalsView);
      ui->stackedWidgetStaff->layout()->addWidget(login);
//      ui->stackedWidgetStaff->layout()->addWidget(defaultScreen);
      ui->stackedWidgetStaff->layout()->addWidget(manageClientsView);
      ui->stackedWidgetStaff->layout()->addWidget(manageMatchesView);
      showManageAnimalsView();
      connect(sideBarStaff, SIGNAL(manageAnimalsView()), this, SLOT(showManageAnimalsView()));
      connect(sideBarStaff, SIGNAL(manageClientsView()), this, SLOT(showManageClientsView()));
      connect(sideBarStaff, SIGNAL(backToLogin()), this, SLOT(switchToCuacsLogin()));
      connect(sideBarStaff, SIGNAL(showMatches()), this, SLOT(presentMatches()));
      //main store button signal slots CONNECTION here
  }

  StaffManageStore::~StaffManageStore()
  {
      delete manageClientsView;
      delete manageAnimalsView;
      delete ui;
  }

  void StaffManageStore::showScreen()
  {
      this->show();
  }

  void StaffManageStore::showManageAnimalsView()
  {
      ui->stackedWidgetStaff->setCurrentWidget(manageAnimalsView);
  }
  void StaffManageStore::presentMatches()
  {
      ui->stackedWidgetStaff->setCurrentWidget(manageMatchesView);
  }

  void StaffManageStore::showManageClientsView()
  {
      ui->stackedWidgetStaff->setCurrentWidget(manageClientsView);
  }

  void StaffManageStore::switchToCuacsLogin()
  {

      qApp->quit();
      QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
  }


