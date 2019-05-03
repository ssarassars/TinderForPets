#ifndef SIDEBARSTAFF_H
#define SIDEBARSTAFF_H

#include <QWidget>

namespace Ui {
class SidebarStaff;
}

class SidebarStaff : public QWidget
{
    Q_OBJECT

public:
    explicit SidebarStaff(QWidget *parent = 0);
    ~SidebarStaff();
signals:
    void manageAnimalsView();
    void manageClientsView();
    void backToLogin();
    void showMatches();


private slots:
    /*
    Function   : on_manageAnimalsButton_clicked
    Purpose    : shows animal management section
    Parameters : none
    */
    void on_manageAnimalsButton_clicked();

    /*
    Function   : on_manageClientsButton_clicked
    Purpose    : shows client management section
    Parameters : none
    */
    void on_manageClientsButton_clicked();

    /*
    Function   : on_logout_clicked
    Purpose    : returns user to login screen
    Parameters : none
    */
    void on_logout_clicked();

    //this function currently is not implemented
    void on_getMatchesButton_clicked();

private:
    Ui::SidebarStaff *ui;
};

#endif // SIDEBARSTAFF_H
