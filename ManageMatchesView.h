#ifndef MANAGEMATCHESVIEW_H
#define MANAGEMATCHESVIEW_H

#include <QMainWindow>
#include "Animal.h"
#include "Client.h"
#include "MatchTableModel.h"
#include "Control.h"

class Control;

enum attributeType {
    Timidity,
    Sociability,
    Aggression,
    Obedience,
    Loyalty,
    Affection,
    Activity,
    Excitability,
    Expressive,
    Age,
    Gender,
    Size,
    Kidfriendliness,
    Cost,
    CurrentTraining,
    Intelligence,
    TimeCommitment,
    Shedding,
    AptCompatibility,
    TrainingSuitability
};

namespace Ui {
class ManageMatchesView;
}

class ManageMatchesView : public QMainWindow
{
    Q_OBJECT

public:
    explicit ManageMatchesView(QWidget *parent, Control* cntrl, MatchTableModel *matchTableModel);
    ~ManageMatchesView();

private slots:
    void on_matchesTableView_clicked(const QModelIndex &index);

private:
    Ui::ManageMatchesView *ui;
    Control *cntrl;
    Animal* selectedAnimalOnTable;
    MatchTableModel *matchTableModel;
    QMap<QString, QVector<QString>> opennessToExpAnimalPref;
    QMap<QString, QVector<QString>> conscientiousnessAnimalPref;
    QMap<QString, QVector<QString>> extraversionAnimalPref;
    QMap<QString, QVector<QString>> agreeablenessAnimalPref;
    QMap<QString, QVector<QString>> neuroticismAnimalPref;
};

#endif // MANAGEMATCHESVIEW_H
