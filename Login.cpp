#include "Login.h"
#include "ui_Login.h"

Login::Login(QWidget *parent, Control *cntrl) : QWidget(parent), ui(new Ui::Login)
{

    ui->setupUi(this);
    this->cntrl = cntrl;
    QPixmap logoPic(":/Images/images/cuacs_logo.png");
    ui->cuacs_logo->setScaledContents(true);
    ui->cuacs_logo->setPixmap(logoPic);
    ui->loginButton->setToolTip("<b>Login to cuACS</b>" );

}
Login::~Login(){
    delete ui;
}

void Login::on_loginButton_clicked()
{
    int userIDEntered = ui->userIDLineEdit->text().toInt();
    if(ui->clientRadioButton->isChecked()){
        if(cntrl->attemptLoginAsClient(userIDEntered)){
            ui->errorLabel->setText("");
            emit loginPassedAsClient(userIDEntered);
        }else {
            ui->errorLabel->setText("Incorrect Pet Adopter User ID. Try again.");
        }
    }
    else if(ui->staffRadioButton->isChecked()){
        if(cntrl->attemptLoginAsStaff(userIDEntered)){
            ui->errorLabel->setText("");
            emit loginPassedAsStaff();
        }else{
            ui->errorLabel->setText("Incorrect Staff User ID. Try again.");
        }

    }else{
        ui->errorLabel->setText("Error: Staff member or Pet Adopter? Please select an option.");
    }


}
