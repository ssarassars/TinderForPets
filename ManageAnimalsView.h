#ifndef MANAGEANIMALSVIEW_H
#define MANAGEANIMALSVIEW_H
#include <QMainWindow>
#include <QApplication>
#include <QCoreApplication>
#include <QHeaderView>
#include "AnimalTableModel.h"
//#include "Control.h"
#include "AddAnimalDialog.h"
#include "EditAnimalDialog.h"
#include "QTableWidget"
#include <QDebug>

class Control;
class AddAnimalDialog;
class EditAnimalDialog;

namespace Ui {
class ManageAnimalsView;
}
class ManageAnimalsView : public QMainWindow
{
    Q_OBJECT
public:
    explicit ManageAnimalsView(QWidget *parent, Control* cntrl, AnimalTableModel *animalTableModel);
    ~ManageAnimalsView();

public slots:
    /*
    Function   : onViewButtonClick
    Purpose    : displays the manage animals view ui
    Parameters : none
    */
    void onViewButtonClick();
    /*
    Function   : setClickedRowFalse
    Purpose    : removes highlight from row, clears sidebar display
    Parameters : none
    */
    void setClickedRowFalse();

private slots:
    /*
    Function   : on_animalTableView_clicked
    Purpose    : shows the selected table record attributes on the display section
    Parameters : index, type: QModelIndex, used to locate a piece of data in the model
    */
    void on_animalTableView_clicked(const QModelIndex &index);
    /*
    Function   : on_addButton_clicked
    Purpose    : creates the add animal dialog widget and displays in ui
    Parameters : none
    */
    void on_addButton_clicked();

    /*
    Function   : on_editButton_clicked
    Purpose    : creates the edit animal dialog widget and displays in ui
    Parameters : none
    */
    void on_editButton_clicked();
    /*
    Function   : enableEditButton
    Purpose    : renders edit button clickable
    Parameters : none
    */
    void enableEditButton();

private:
    Ui::ManageAnimalsView *ui;
    QStringList horizontalHeader;
    Control *cntrl;
    Animal* selectedAnimalOnTable;
    AddAnimalDialog *addAnimalView;
    EditAnimalDialog *editAnimalView;
    AnimalTableModel *animalTableModel;

};

#endif // MANAGEANIMALSVIEW_H
