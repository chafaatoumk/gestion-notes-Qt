#ifndef UIMODULE_H
#define UIMODULE_H

#include <QMainWindow>

namespace Ui {
class UIModule;
}

class UIModule : public QMainWindow
{
    Q_OBJECT

public:
    explicit UIModule(QWidget *parent = nullptr);
    UIModule(QObject* controller = nullptr);
    ~UIModule();

    bool getInputs(int* identifiant, QString &nom, QString &volumeHoraire, bool* operation);

private:
    Ui::UIModule *ui;
};

#endif // UIMODULE_H
