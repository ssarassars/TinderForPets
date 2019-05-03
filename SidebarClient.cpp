#include "SidebarClient.h"
#include "ui_SidebarClient.h"

SidebarClient::SidebarClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SidebarClient)
{
    ui->setupUi(this);
    ui->browseButton->setToolTip("<b>Browse Animals</b>"
                                        "<ul>"
                                        "<li>View All Animals</li>"
                                        "<li>View Animal Details</li>"
                                        "</ul>"
                                        );
    ui->editButton->setToolTip("<b>Edit Own Profile</b>"
                                        "<ul>"
                                        "<li>View Profile Details</li>"
                                        "<li>Edit Basic Details</li>"
                                        "<li>Attempt Personality Quiz</li>"
                                        "<li>Modify Matching Preferences</li>"
                                        "</ul>"
                                        );
    ui->logoutButton->setToolTip("<b>Back to Login Screen</b>");
}

SidebarClient::~SidebarClient()
{
    delete ui;
}


void SidebarClient::on_browseButton_clicked()
{
 //   void userToSwitchContextTo(DetailViewType);
    emit browseAnimalsView();
}

void SidebarClient::on_editButton_clicked()
{
    emit editClientView();
}

void SidebarClient::on_logoutButton_clicked()
{
    emit backToLoginScreen();
}
