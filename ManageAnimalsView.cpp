#include "ManageAnimalsView.h"
#include "ui_ManageAnimalsView.h"

ManageAnimalsView::ManageAnimalsView(QWidget *parent, Control* cntrl, AnimalTableModel *animalTableModel):
    QMainWindow(parent),
    ui(new Ui::ManageAnimalsView)
{
    ui->setupUi(this);
    this->cntrl = cntrl;
    // GET ANIMAL TABLE MODEL FROM CONTROL
    this->animalTableModel = animalTableModel;
    setWindowState(Qt::WindowFullScreen);
    setWindowTitle("cuACS - Manage Animals");
    ui->editButton->setEnabled(false);
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
    ui->addButton->setToolTip("<b>Add a new Animal to shelter</b>" );
    ui->editButton->setToolTip("<b>Edit an existing Animal Detail</b>");
    connect(ui->animalTableView,SIGNAL(clicked(QModelIndex)), this, SLOT(on_animalTableView_clicked(QModelIndex)));
    connect(ui->animalTableView,SIGNAL(clicked(QModelIndex)), this, SLOT(enableEditButton()));
}
ManageAnimalsView::~ManageAnimalsView()
{
    delete ui;

}

void ManageAnimalsView::setClickedRowFalse()
{
    ui->animalTableView->clearSelection();
    ui->displayID->clear();
    ui->displayAge->clear();
    ui->displayName->clear();
    ui->displayGender->clear();
    ui->displayType->clear();
    ui->displayTimidity->clear();
    ui->displaySociability->clear();
    ui->displayAggression->clear();
    ui->displayObedience->clear();
    ui->displayLoyalty->clear();
    ui->displayAffection->clear();
    ui->displayActivity->clear();
    ui->displayExcitability->clear();
    ui->displayExpressiveness->clear();
    ui->displaySize->clear();
    ui->displayShedding->clear();
    ui->displayTrainingSuitability->clear();
    ui->displayCurrTraining->clear();
    ui->displayIntelligence->clear();
    ui->displayCost->clear();
    ui->displayTime->clear();
    ui->displayAptCompatibility->clear();
    ui->displayKidFriendliness->clear();
}

void ManageAnimalsView::onViewButtonClick()
{
    this->show();
}

void ManageAnimalsView::enableEditButton()
{
    ui->editButton->setEnabled(true);
}

void ManageAnimalsView::on_animalTableView_clicked(const QModelIndex &index)
{
    int selectedAnimalID = ui->animalTableView->model()->index(index.row(),0).data().toInt();
    Animal* animalSelected = cntrl->getSelectedAnimalObject(selectedAnimalID);
    this->selectedAnimalOnTable = animalSelected;

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

void ManageAnimalsView::on_addButton_clicked()
{
    addAnimalView = new AddAnimalDialog(this, cntrl);
    addAnimalView->show();
}

void ManageAnimalsView::on_editButton_clicked()
{
    editAnimalView = new EditAnimalDialog(this, cntrl, selectedAnimalOnTable);
    connect(editAnimalView,SIGNAL(editSignal()), this, SLOT(setClickedRowFalse()));
    editAnimalView->show();
}
