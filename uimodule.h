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

    bool getInputs(int* identifiant, QString &nom, uint &volumeHoraire, bool* operation);
    void initializeInputs();

private:
    Ui::UIModule *ui;
};

#endif // UIMODULE_H
