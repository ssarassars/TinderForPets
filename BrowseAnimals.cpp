#include "BrowseAnimals.h"
#include "ui_BrowseAnimals.h"

BrowseAnimals::BrowseAnimals(QWidget *parent, Control* cntrl, AnimalTableModel *animalTableModel) :
    QWidget(parent),
    ui(new Ui::BrowseAnimals)
{
    ui->setupUi(this);
    //WE DONT NEED CONTROL HERE
    this->cntrl = cntrl;
    this->animalTableModel = animalTableModel;
    setWindowState(Qt::WindowFullScreen);
    setWindowTitle("cuACS - Browse Animals");
    ui->animalTableView->verticalHeader()->setVisible(false);
    ui->animalTableView->resizeColumnsToContents();
    ui->animalTableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:white}");
    ui->animalTableView->setStyleSheet("QHeaderView::section{background-color:blue}");
    ui->animalTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->animalTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->animalTableView->setShowGrid(false);
    ui->animalTableView->setModel(animalTableModel);
    ui->animalTableView->setColumnWidth(0,60);
    ui->animalTableView->setColumnWidth(1,105);
    ui->animalTableView->setColumnWidth(2,105);
    ui->animalTableView->setColumnWidth(4,115);
    connect(ui->animalTableView,SIGNAL(clicked(QModelIndex)), this, SLOT(on_animalTableView_clicked(QModelIndex)));
}

BrowseAnimals::~BrowseAnimals()
{
    delete ui;
}

void BrowseAnimals::on_animalTableView_clicked(const QModelIndex &index)
{
    int selectedAnimalID = ui->animalTableView->model()->index(index.row(),0).data().toInt();
    Animal* animalSelected = cntrl->getSelectedAnimalObject(selectedAnimalID);

    QString age = animalSelected->getAge();
    QString gender = animalSelected->getGender();
    QString type = animalSelected->getType();
    QString name = animalSelected->getName();
    QString timidity = animalSelected->getTimidity();
    QString sociability = animalSelected->getSociability();
    QString aggression = animalSelected->getAggression();
    QString obedience = animalSelected->getObedience();
    QString loyalty = animalSelected->getLoyalty();
    QString affection = animalSelected->getAffection();
    QString activity = animalSelected->getActivity();
    QString excitability = animalSelected->getExcitability();
    QString expressiveness = animalSelected->getExpressiveness();
    QString size = animalSelected->getSize();
    QString shedding = animalSelected->getShedding();
    QString trainSuit = animalSelected->getTrainingSuitability();
    QString currTrain = animalSelected->getCurrentTraining();
    QString intelligence = animalSelected->getIntelligence();
    QString cost = animalSelected->getCost();
    QString timeCommit = animalSelected->getTimeCommitment();
    QString aptCompatibility = animalSelected->getApartmentCompatibility();
    QString kidFriendliness = animalSelected->getKidfriendliness();

    ui->displayID->setNum(selectedAnimalID);
    ui->displayAge->setText(age);
    ui->displayName->setText(name);
    ui->displayGender->setText(gender);
    ui->displayType->setText(type);
    ui->displayTimidity->setText(timidity);
    ui->displaySociability->setText(sociability);
    ui->displayAggression->setText(aggression);
    ui->displayObedience->setText(obedience);
    ui->displayLoyalty->setText(loyalty);
    ui->displayAffection->setText(affection);
    ui->displayActivity->setText(activity);
    ui->displayExcitability->setText(excitability);
    ui->displayExpressiveness->setText(expressiveness);
    ui->displaySize->setText(size);
    ui->displayShedding->setText(shedding);
    ui->displayTrainingSuitability->setText(trainSuit);
    ui->displayCurrTraining->setText(currTrain);
    ui->displayIntelligence->setText(intelligence);
    ui->displayCost->setText(cost);
    ui->displayTime->setText(timeCommit);
    ui->displayAptCompatibility->setText(aptCompatibility);
    ui->displayKidFriendliness->setText(kidFriendliness);
}

//void BrowseAnimals::on_pushButtonMainStore_clicked()
//{
//    emit backToMainClientStore();
//}
