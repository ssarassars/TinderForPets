#include "SidebarStaff.h"
#include "ui_SidebarStaff.h"

SidebarStaff::SidebarStaff(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SidebarStaff)
{
    ui->setupUi(this);
    ui->manageAnimalsButton->setToolTip("<b>Manage Animals</b>"
                                        "<ul>"
                                        "<li>View All Animals</li>"
                                        "<li>View Animal Details</li>"
                                        "<li>Add an Animal</li>"
                                        "<li>Edit an Animal</li>"
                                        "</ul>"
                                        );
    ui->manageClientsButton->setToolTip("<b>Manage Clients</b>"
                                        "<ul>"
                                        "<li>View All Clients</li>"
                                        "<li>View Client Details</li>"
                                        "<li>Add a Client</li>"
                                        "</ul>"
                                        );
    ui->getMatchesButton->setToolTip("<b>Get Matches</b>"
                                     "<ul>"
                                     "<li>View All Matches</li>"
                                     "<li>View Match Details</li>"
                                     "</ul>"
                                     );
    ui->logout->setToolTip("<b>Back to Login Screen</b>" );
}

SidebarStaff::~SidebarStaff()
{
    delete ui;
}

void SidebarStaff::on_manageAnimalsButton_clicked()
{
    emit manageAnimalsView();
}

void SidebarStaff::on_manageClientsButton_clicked()
{
    emit manageClientsView();
}

void SidebarStaff::on_logout_clicked()
{
    emit backToLogin();
}

void SidebarStaff::on_getMatchesButton_clicked()
{
    emit showMatches();
}
