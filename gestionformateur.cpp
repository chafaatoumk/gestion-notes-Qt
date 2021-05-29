#include "gestionformateur.h"
#include "ui_gestionformateur.h"

GestionFormateur::GestionFormateur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GestionFormateur)
{
    ui->setupUi(this);
}

GestionFormateur::GestionFormateur(QObject *controller)
    : ui(new Ui::GestionFormateur)
{
    ui->setupUi(this);

    connect(ui->pushButtonValider, SIGNAL(clicked()),
            controller, SLOT(onUIGestionFormateurValiderClicked()));
    connect(ui->pushButtonSupprimer, SIGNAL(clicked()),
            controller, SLOT(onUIGestionFormateurSupprimerClicked()));
    connect(ui->pushButtonListerFormateurs, SIGNAL(clicked()),
            controller, SLOT(onUIGestionFormateurListerClicked()));
}

GestionFormateur::~GestionFormateur()
{
    delete ui;
}
