#ifndef MANAGECLIENTSVIEW_H
#define MANAGECLIENTSVIEW_H
#include <QMainWindow>
#include <QApplication>
#include <QCoreApplication>
#include <QHeaderView>
#include "ClientTableModel.h"
#include "Control.h"
#include <QDebug>
#include "AddAnimalDialog.h"
#include "AddClientDialog.h"
#include "QTableWidget"

class Control;
class AddClientDialog;

namespace Ui {
    class ManageClientsView;
}
class ManageClientsView : public QMainWindow
{
    Q_OBJECT
public:
    explicit ManageClientsView(QWidget *parent, Control* cntrl, ClientTableModel *clientTableModel);
    ~ManageClientsView();
public slots:
    /*
    Function   : onViewButtonClick
    Purpose    : displays the manage clients view ui
    Parameters : none
    */
    void onViewButtonClick();

private slots:

    /*
    Function   : on_clientTableView_clicked
    Purpose    : shows the selected table record attributes on the display section
    Parameters : index, type: QModelIndex, used to locate a piece of data in the model
    */
    void on_clientTableView_clicked(const QModelIndex &index);

    /*
    Function   : on_addButton_clicked
    Purpose    : creates the add client dialog widget and displays in ui
    Parameters : none
    */
    void on_addButton_clicked();

private:
    Ui::ManageClientsView *ui;
    QStringList horizontalHeader;
    Control *cntrl;
    AddClientDialog *addClientView;
    ClientTableModel *clientTableModel;

};

#endif // MANAGECLIENTSVIEW_H
