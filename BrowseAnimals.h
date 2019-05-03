#ifndef BROWSEANIMALS_H
#define BROWSEANIMALS_H

#include <QWidget>
#include <QMainWindow>
#include <QApplication>
#include <QCoreApplication>
#include <QHeaderView>
#include "AnimalTableModel.h"
#include "Control.h"
#include "QTableWidget"
#include <QDebug>

class Control;

namespace Ui {
class BrowseAnimals;
}

class BrowseAnimals : public QWidget
{
    Q_OBJECT

public:
    explicit BrowseAnimals(QWidget *parent, Control* cntrl, AnimalTableModel *animalTableModel);
    ~BrowseAnimals();
//signals:
//    void backToMainClientStore();
private slots:
    /*
    Function   : on_animalTableView_clicked
    Purpose    : when a row in the Animal table is clicked, displays that Animal's specific details in the sidebar
    Parameters : input :
                 index, type: QModelIndex, used to specify which row has been clicked
    */
    void on_animalTableView_clicked(const QModelIndex &index);

   // void on_pushButtonMainStore_clicked();

private:
    Ui::BrowseAnimals *ui;
    QStringList horizontalHeader;
    Control *cntrl;
    AnimalTableModel *animalTableModel;
};

#endif // BROWSEANIMALS_H
