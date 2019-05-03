#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "Control.h"
#include <qdebug.h>

class Control;

namespace Ui {
class Login;
}
class Login : public QWidget
{
    Q_OBJECT
public:
    explicit Login(QWidget *parent = nullptr, Control *cntrl = 0);
    ~Login();

private:
    Ui::Login *ui;
    Control *cntrl;

signals:
    /* Function   : loginPassedAsStaff
     * Purpose    : to give a signal indicating that the staff info enetred
     *              for login is valid
     * Parameters : none
    */
    void loginPassedAsStaff();
    /* Function   : loginPassedAsClient
     * Purpose    : to give a signal indicating that the client info enetred
     *              for login is valid
     * Parameters : int, the id of the client passing
    */
    void loginPassedAsClient(int clientID);


public slots:
private slots:
    /* Function   : on_loginButton_clicked
     * Purpose    : to perform the user authentication process once
     *              the login button is clicked. If login was not
     *              successful the user will be notified.
     * Parameters : none
    */
    void on_loginButton_clicked();
};

#endif // LOGIN_H
