#include "gestionetudiant.h"
#include "ui_gestionetudiant.h"

GestionEtudiant::GestionEtudiant(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GestionEtudiant)
{
    ui->setupUi(this);
}

GestionEtudiant::~GestionEtudiant()
{
    delete ui;
}
