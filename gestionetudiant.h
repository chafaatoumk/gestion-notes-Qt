#ifndef GESTIONETUDIANT_H
#define GESTIONETUDIANT_H

#include <QMainWindow>

namespace Ui {
class GestionEtudiant;
}

class GestionEtudiant : public QMainWindow
{
    Q_OBJECT

public:
    explicit GestionEtudiant(QWidget *parent = nullptr);
    GestionEtudiant(QObject* controller = nullptr);
    ~GestionEtudiant();

private:
    Ui::GestionEtudiant *ui;
};

#endif // GESTIONETUDIANT_H
