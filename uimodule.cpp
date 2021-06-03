#include "uimodule.h"
#include "ui_uimodule.h"

UIModule::UIModule(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UIModule)
{
    ui->setupUi(this);
}

UIModule::UIModule(QObject *controller)
    : ui(new Ui::UIModule)
{
    ui->setupUi(this);

    connect(ui->pushButtonValider, SIGNAL(clicked()),
            controller, SLOT(onUIModuleValiderClicked()));
    connect(ui->pushButtonSupprimer, SIGNAL(clicked()),
            controller, SLOT(onUIModuleSupprimerClicked()));
    connect(ui->pushButtonListerModules, SIGNAL(clicked()),
            controller, SLOT(onUIModuleListerClicked()));
}

bool UIModule::getInputs(int* identifiant, QString &nom, QString &volumeHoraire, bool* operation)
{
    if (ui->lineEditID->text().compare("") != 0)
    //{
       *identifiant = ui->lineEditID->text().toInt();

        nom = ui->lineEditNom->text();
        //volumeHoraire = ui->lineEditVolume->text();
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

UIModule::~UIModule()
{
    delete ui;
}
