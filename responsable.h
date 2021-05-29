#ifndef RESPONSABLE_H
#define RESPONSABLE_H

#include <QMainWindow>

namespace Ui {
class Responsable;
}

class Responsable : public QMainWindow
{
    Q_OBJECT

public:
    Responsable(QWidget *parent = nullptr);
    Responsable(QObject* controller = nullptr);
    ~Responsable();

private:
    Ui::Responsable *ui;
};

#endif // RESPONSABLE_H
