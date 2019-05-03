#-------------------------------------------------
#
# Project created by QtCreator 2018-02-01T13:10:09
#
#-------------------------------------------------

QT       += core gui sql

CONFIG += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cuACS
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    Control.cpp \
    Animal.cpp \
    AnimalTableModel.cpp \
    ManageAnimalsView.cpp \
    AddAnimalDialog.cpp \
    Store.cpp \
    ClientTableModel.cpp \
    Client.cpp \
    DBHandler.cpp \
    ManageClientsView.cpp \
    Login.cpp \
    CuacsAppView.cpp \
    ClientManageStore.cpp \
    BrowseAnimals.cpp \
    Staff.cpp \
    StaffCollection.cpp \
    AddClientDialog.cpp \
    SidebarClient.cpp \
    SidebarStaff.cpp \
    StaffManageStore.cpp \
    Default.cpp \
    DBQuery.cpp \
    AnimalCollection.cpp \
    ClientCollection.cpp \
    StoreControl.cpp \
    EditAnimalDialog.cpp \
    LoginControl.cpp \
    EditClientDialog.cpp \
    ManageMatchesView.cpp \
    MatchTableModel.cpp \
    MatchingAlgorithm.cpp \
    KuhnMunkres.cpp



HEADERS += \
    Control.h \
    Animal.h \
    AnimalTableModel.h \
    ManageAnimalsView.h \
    AddAnimalDialog.h \
    Store.h \
    ClientTableModel.h \
    Client.h \
    DBHandler.h \
    ManageClientsView.h \
    Login.h \
    CuacsAppView.h \
    ClientManageStore.h \
    BrowseAnimals.h \
    Staff.h \
    StaffCollection.h \
    AddClientDialog.h \
    SidebarClient.h \
    SidebarStaff.h \
    StaffManageStore.h \
    Default.h \
    DBQuery.h \
    AnimalCollection.h \
    ClientCollection.h \
    StoreControl.h \
    EditAnimalDialog.h \
    LoginControl.h \
    EditClientDialog.h \
    Constants.h \
    ManageMatchesView.h \
    MatchTableModel.h \
    MatchingAlgorithm.h \
    KuhnMunkres.h

FORMS += \
    ManageAnimalsView.ui \
    AddAnimalDialog.ui \
    ManageClientsView.ui \
    Login.ui \
    CuacsAppView.ui \
    ClientManageStore.ui \
    BrowseAnimals.ui \
    AddClientDialog.ui \
    SidebarClient.ui \
    SidebarStaff.ui \
    StaffManageStore.ui \
    Default.ui \
    EditAnimalDialog.ui \
    EditAnimalDialog.ui \
    EditClientDialog.ui \
    ManageMatchesView.ui

RESOURCES += \
    stylesheet.qrc

