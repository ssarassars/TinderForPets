#include "ManageClientsView.h"
#include "ui_ManageClientsView.h"

ManageClientsView::ManageClientsView(QWidget *parent, Control* cntrl, ClientTableModel *clientTableModel):
    QMainWindow(parent),
    ui(new Ui::ManageClientsView)
{
    ui->setupUi(this);
    this->cntrl = cntrl;
    this->clientTableModel = clientTableModel;
//    setWindowState(Qt::WindowFullScreen);
    setWindowTitle("cuACS - Manage Clients");
    ui->clientTableView->verticalHeader()->setVisible(false);
    ui->clientTableView->resizeColumnsToContents();
    ui->clientTableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:white}");
    ui->clientTableView->setStyleSheet("QHeaderView::section{background-color:blue}");
    ui->clientTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->clientTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->clientTableView->setShowGrid(false);
    ui->clientTableView->setModel(this->clientTableModel);
    ui->clientTableView->setColumnWidth(0,70);
    ui->clientTableView->setColumnWidth(1,135);
    ui->addButton->setToolTip("<b>Add a new Client to cuACS</b>" );

    connect(ui->clientTableView,SIGNAL(clicked(QModelIndex)), this, SLOT(on_clientTableView_clicked(QModelIndex)));

}
ManageClientsView::~ManageClientsView()
{
    delete ui;

}

void ManageClientsView::onViewButtonClick()
{
    this->show();
}

void ManageClientsView::on_clientTableView_clicked(const QModelIndex &index)
{
    int selectedClientID = ui->clientTableView->model()->index(index.row(),0).data().toInt();
    Client* clientSelected = cntrl->getSelectedClientObject(selectedClientID);
    QString clientAddress = clientSelected->getAddress();
    QString clientEmail = clientSelected->getEmail();
    QString clientAnimalPrefType = clientSelected->getAnimalPrefType();
    QString clientPhoneNo = clientSelected->getPhoneNo();
    QString clientName = clientSelected->getName();
    QString clientExtraversion = clientSelected->getExtraversion();
    QString clientAgreeableness = clientSelected->getAgreeableness();
    QString clientConscientiousness = clientSelected->getConscientiousness();
    QString clientNeuroticism = clientSelected->getNeuroticism();
    QString clientOpenness = clientSelected->getOpennessToExp();
    QString prefAge = clientSelected->getAgePref();
    QString prefsize = clientSelected->getSizePref();
    QString prefGender = clientSelected->getGenderPref();
    QString prefCost = clientSelected->getCostPref();
    QString prefKidFriendly = clientSelected->getKidFriendlyPref();
    QString prefCurrentTraining = clientSelected->getCurrTrainingPref();
    QString prefIntelligence = clientSelected->getIntelligencePref();
    QString prefTimeCommitment = clientSelected->getTimeCommitPref();
    QString prefShedding = clientSelected->getSheddingPref();
    QString prefApartmentCompatibility = clientSelected->getAptCompatibilityPref();
    QString prefTrainingSuit = clientSelected->getTrainSuitabilityPref();

    ui->displayID->setNum(selectedClientID);
    ui->displayEmail->setText(clientEmail);
    ui->displayAddress->setText(clientAddress);
    ui->displayName->setText(clientName);
    ui->displayPhoneNo->setText(clientPhoneNo);
    ui->displayExtraversion->setText(clientExtraversion);
    ui->displayAgreeableness->setText(clientAgreeableness);
    ui->displayConscientiousness->setText(clientConscientiousness);
    ui->displayNeuroticism->setText(clientNeuroticism);
    ui->displayOpenness->setText(clientOpenness);
    ui->displayAge->setText(prefAge);
    ui->displaySize->setText(prefsize);
    ui->displayType_2->setText(clientAnimalPrefType);
    ui->displayGender->setText(prefGender);
    ui->displayCost->setText(prefCost);
    ui->displayCurrentTraining->setText(prefCurrentTraining);
    ui->displayKidFriendliness->setText(prefKidFriendly);
    ui->displayIntelligence->setText(prefIntelligence);
    ui->displayTimeComm->setText(prefTimeCommitment);
    ui->displayShedding->setText(prefShedding);
    ui->displayApartmentCompatibility->setText(prefApartmentCompatibility);
    ui->displayTrainingSuitability->setText(prefTrainingSuit);
}

void ManageClientsView::on_addButton_clicked()
{
    addClientView = new AddClientDialog(this, cntrl);
    addClientView->show();

}

