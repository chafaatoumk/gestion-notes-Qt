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
    this->setUpTableView();

    connect(ui->pushButtonValider, SIGNAL(clicked()),
            controller, SLOT(onUIGestionFormateurValiderClicked()));
    connect(ui->pushButtonSupprimer, SIGNAL(clicked()),
            controller, SLOT(onUIGestionFormateurSupprimerClicked()));
    connect(ui->pushButtonLister, SIGNAL(clicked()),
            controller, SLOT(onUIGestionFormateurListerClicked()));
}

bool GestionFormateur::getInputs(int* identifiant, QString &nom, QString &email, QString &module, QString &classe, bool* operation)
{

       *identifiant = ui->lineEditId->text().toInt();

        nom = ui->lineEditNom->text();
        email = ui->lineEditEmail->text();
        module = ui->comboBoxModule->currentText();
        classe = ui->comboBoxClasse->currentText();
        *operation = ui->radioButtonCreer->isChecked(); // true si creation ...

        if(operation)
        {
             return true; // true si creation ...
        }
        else{
            return false;
        }
}

void GestionFormateur::setUpTableView()
{
    //liaison entre le tableView et la BD
    formateurModel = new FormateurModel(DBAccess::getInstance());
    ui->tableView->setModel(formateurModel);
    formateurModel->readAll();
}

FormateurModel* GestionFormateur::getFormateurModel()
{
    return formateurModel;
}

QTableView* GestionFormateur::getTableView()
{
    return ui->tableView;
}

QString GestionFormateur::getCritere()
{
    return ui->comboBoxRechercherPar->itemText(0);
}

QString GestionFormateur::getRechercherInput()
{
    return ui->lineEditRechercher->text();
}

void GestionFormateur::initializeInputs()
{
    ui->lineEditId->setText("");

    ui->lineEditNom->setText("");
    ui->lineEditEmail->setText("");
    ui->comboBoxModule->setCurrentText("Module");
    ui->comboBoxClasse->setCurrentText("Classe");
}

void GestionFormateur::on_tableView_clicked(const QModelIndex &index)
{
    QSqlRecord record;
    int i = index.row(); // now you know which record was selected
    record = formateurModel->record(i);
    // getting data from selected row of the tableView to inputs
    ui->lineEditId->setText(record.value(0).toString());
    ui->lineEditNom->setText(record.value(1).toString());
    ui->lineEditPrenom->setText(record.value(2).toString());
    ui->lineEditEmail->setText(record.value(3).toString());
    ui->lineEditTelephone->setText(record.value(4).toString());
    ui->comboBoxModule->setCurrentText(record.value(5).toString());
    ui->comboBoxClasse->setCurrentText(record.value(6).toString());
}

void GestionFormateur::notificationError(QString message)
{
    QMessageBox::critical(this, "Error", message, QMessageBox::Ok);
}

void GestionFormateur::notificationInformation(QString message)
{
    QMessageBox::information(this, "Information", message, QMessageBox::Ok);
}

GestionFormateur::~GestionFormateur()
{
    delete ui;
}
