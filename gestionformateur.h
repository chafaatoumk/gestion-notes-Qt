#ifndef GESTIONFORMATEUR_H
#define GESTIONFORMATEUR_H

#include <QMainWindow>

namespace Ui {
class GestionFormateur;
}

class GestionFormateur : public QMainWindow
{
    Q_OBJECT

public:
    explicit GestionFormateur(QWidget *parent = nullptr);
    GestionFormateur(QObject* controller = nullptr);
    ~GestionFormateur();

    bool getInputs(int* identifiant, QString &nom, QString &email, QString &module, QString &classe, bool* operation);
    void initializeInputs();

private:
    Ui::GestionFormateur *ui;
};

#endif // GESTIONFORMATEUR_H
