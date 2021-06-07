#ifndef UICLASSE_H
#define UICLASSE_H

#include <QMainWindow>

namespace Ui {
class UIClasse;
}

class UIClasse : public QMainWindow
{
    Q_OBJECT

public:
    explicit UIClasse(QWidget *parent = nullptr);
    ~UIClasse();

private:
    Ui::UIClasse *ui;
};

#endif // UICLASSE_H
