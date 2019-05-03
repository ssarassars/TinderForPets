#ifndef SIDEBARCLIENT_H
#define SIDEBARCLIENT_H

#include <QWidget>

namespace Ui {
class SidebarClient;
}

class SidebarClient : public QWidget
{
    Q_OBJECT

public:
    explicit SidebarClient(QWidget *parent = 0);
    ~SidebarClient();

signals:
    void browseAnimalsView();
    void backToLoginScreen();
    void showDefaultScreen();
    void editClientView();

private slots:
    /*
    Function   : on_browseButton_clicked
    Purpose    : shows animal browsing section
    Parameters : none
    */
    void on_browseButton_clicked();

    /*
    Function   : on_editButton_clicked
    Purpose    : shows client's profile for editing purposes
    Parameters : none
    */
    void on_editButton_clicked();

    /*
    Function   : on_logoutButton_clicked
    Purpose    : returns client to login menu
    Parameters : none
    */
    void on_logoutButton_clicked();

private:
    Ui::SidebarClient *ui;
};

#endif // SIDEBARCLIENT_H
