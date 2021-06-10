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
    this->setUpTableView();

    connect(ui->pushButtonValider, SIGNAL(clicked()),
            controller, SLOT(onUIModuleValiderClicked()));
    connect(ui->pushButtonSupprimer, SIGNAL(clicked()),
            controller, SLOT(onUIModuleSupprimerClicked()));
    connect(ui->pushButtonLister, SIGNAL(clicked()),
            controller, SLOT(onUIModuleListerClicked()));
    connect(ui->pushButtonRechercherPar, SIGNAL(clicked()),
            controller, SLOT(onUIClasseRechercherClicked()));
    connect(ui->pushButtonEffacer, SIGNAL(clicked()),
            controller, SLOT(onUIModuleEffacerClicked()));
    connect(ui->pushButtonExit, SIGNAL(clicked()),
            controller, SLOT(onUIModuleExitClicked()));
}

void UIModule::setUpTableView()
{
    //liaison entre le tableView et la BD
    moduleModel = new ModuleModel(DBAccess::getInstance());
    ui->tableView->setModel(moduleModel);
    moduleModel->readAll();
}

bool UIModule::getInputs(int* identifiant, QString &nom, uint &volumeHoraire, bool* operation)
{
       *identifiant = ui->lineEditID->text().toInt();
        nom = ui->lineEditNom->text();
        volumeHoraire = ui->spinBoxVolumeHoraire->value();
        *operation = ui->radioButtonCreer->isChecked(); // true si creation ...

        if(operation)
        {
             return true; // true si creation ...
        }
        else{
            return false;
        }
}

void UIModule::initializeInputs()
{
    ui->lineEditID->setText("");
    ui->lineEditNom->setText("");
    ui->spinBoxVolumeHoraire->cleanText();
}

ModuleModel* UIModule::getModuleModel()
{
    return moduleModel;
}

QTableView* UIModule::getTableView()
{
    return ui->tableView;
}

QString UIModule::getCritere()
{
    return ui->comboBoxRechercherPar->currentText();
}

QString UIModule::getRechercherInput()
{
    return ui->lineEditRechercher->text();
}

void UIModule::on_tableView_clicked(const QModelIndex &index)
{
    QSqlRecord record;
    int i = index.row(); // now you know which record was selected
    record = moduleModel->record(i);
    // getting data from selected row of the tableView to inputs
    ui->lineEditID->setText(record.value(0).toString());
    ui->lineEditNom->setText(record.value(1).toString());
    ui->spinBoxVolumeHoraire->setValue(record.value(3).toUInt());
}

void UIModule::notificationError(QString message)
{
    QMessageBox::critical(this, "Error", message, QMessageBox::Ok);
}

void UIModule::notificationInformation(QString message)
{
    QMessageBox::information(this, "Information", message, QMessageBox::Ok);
}


UIModule::~UIModule()
{
    delete ui;
    delete moduleModel;
}
