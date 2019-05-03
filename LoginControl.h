#ifndef LOGINCONTROL_H
#define LOGINCONTROL_H
#include <QDebug>
#include "Store.h"

class Store;

class LoginControl
{
public:
    LoginControl(Store* petStore=0);
    ~LoginControl();
    /* Function   : attemptLoginAsClient
     * Purpose    : to verify that the entered client user id is valid for logging in
     * Parameters : input: userID, type: int, the user id entered for logging in as client
     * Returns    : type: bool, true if the userID is that of an existing client, false otherwise
    */

    bool attemptLoginAsClient(int userID);


    /* Function   : attemptLoginAsStaff
     * Purpose    : to verify that the entered staff user id is valid for logging in
     * Parameters : input: userID, type: int, the user id entered for logging in as staff
     * Returns    : type: bool, true if the userID is that of an existing staff member, false otherwise
    */
    bool attemptLoginAsStaff(int userID);

private:
    Store* petStore;

};

#endif // LOGINCONTROL_H
