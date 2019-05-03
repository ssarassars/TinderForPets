#ifndef DEFAULT_H
#define DEFAULT_H

#include <QWidget>

namespace Ui {
class Default;
}

class Default : public QWidget
{
    Q_OBJECT

public:
    explicit Default(QWidget *parent = 0);
    ~Default();

private:
    Ui::Default *ui;
};

#endif // DEFAULT_H
