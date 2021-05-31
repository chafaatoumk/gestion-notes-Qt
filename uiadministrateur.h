#ifndef UIADMINISTRATEUR_H
#define UIADMINISTRATEUR_H

#include <QMainWindow>

namespace Ui {
class UIAdministrateur;
}

class UIAdministrateur : public QMainWindow
{
    Q_OBJECT

public:
    UIAdministrateur(QWidget *parent = nullptr);
    UIAdministrateur(QObject* controller = nullptr);
    ~UIAdministrateur();

    bool getInputs(int* identifiant, QString &login, QString &password, QString &type, bool* operation);
    void initializeInputs();

private:
    Ui::UIAdministrateur *ui;
};

#endif // UIADMINISTRATEUR_H
