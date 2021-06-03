#include "gestionetudiant.h"
#include "ui_gestionetudiant.h"

GestionEtudiant::GestionEtudiant(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GestionEtudiant)
{
    ui->setupUi(this);
}

GestionEtudiant::GestionEtudiant(QObject *controller)
    : ui(new Ui::GestionEtudiant)
{
    ui->setupUi(this);

    connect(ui->pushButtonValider, SIGNAL(clicked()),
            controller, SLOT(onUIGestionFormateurValiderClicked()));
    connect(ui->pushButtonSupprimer, SIGNAL(clicked()),
            controller, SLOT(onUIGestionFormateurSupprimerClicked()));
    connect(ui->pushButtonListerEtudiants, SIGNAL(clicked()),
            controller, SLOT(onUIGestionFormateurListerClicked()));
}

GestionEtudiant::~GestionEtudiant()
{
    delete ui;
}
