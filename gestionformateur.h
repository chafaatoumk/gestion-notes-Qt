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

private:
    Ui::GestionFormateur *ui;
};

#endif // GESTIONFORMATEUR_H
