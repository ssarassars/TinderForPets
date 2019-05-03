#include "LoginControl.h"

LoginControl::LoginControl(Store *petStore)
{
    this->petStore=petStore;
}

LoginControl::~LoginControl(){

}

bool LoginControl::attemptLoginAsClient(int userID)
{
    return petStore->checkIfClientExists(userID);

}

bool LoginControl::attemptLoginAsStaff(int userID)
{
    return petStore->checkIfStaffExists(userID);

}
