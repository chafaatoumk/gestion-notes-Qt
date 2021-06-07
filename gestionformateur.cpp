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

bool GestionFormateur::getInputs(int* identifiant, QString &nom, QString &email, QString &module, QString &classe, bool* operation)
{
    if (ui->lineEditID->text().compare("") != 0)
    //{
       *identifiant = ui->lineEditID->text().toInt();

        nom = ui->lineEditNom->text();
        email = ui->lineEditEmail->text();
        module = ui->comboBoxModule->itemText(0);
        classe = ui->comboBoxClasse->itemText(0);
        *operation = ui->radioButtonCreer->isChecked(); // true si creation ...

        return true;
    //}
    /*
    else
    {
        return false;
    }
    */
}

void GestionFormateur::initializeInputs()
{
    ui->lineEditID->text().toInt();

    ui->lineEditNom->text();
    ui->lineEditEmail->text();
    ui->comboBoxModule->itemText(0);
    ui->comboBoxClasse->itemText(0);
}

GestionFormateur::~GestionFormateur()
{
    delete ui;
}
