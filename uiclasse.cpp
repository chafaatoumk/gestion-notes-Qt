#include "uiclasse.h"
#include "ui_uiclasse.h"

UIClasse::UIClasse(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UIClasse)
{
    ui->setupUi(this);
}

UIClasse::UIClasse(QObject *controller)
    : ui(new Ui::UIClasse)
{
    ui->setupUi(this);
    this->setUpTableView();

    connect(ui->pushButtonValider, SIGNAL(clicked()),
            controller, SLOT(onUIClasseValiderClicked()));
    connect(ui->pushButtonLister, SIGNAL(clicked()),
            controller, SLOT(onUIClasseListerClicked()));
    connect(ui->pushButtonRechercherPar, SIGNAL(clicked()),
            controller, SLOT(onUIClasseRechercherClicked()));
    connect(ui->pushButtonSupprimer, SIGNAL(clicked()),
            controller, SLOT(onUIClasseSupprimerClicked()));
    connect(ui->pushButtonEffacer, SIGNAL(clicked()),
            controller, SLOT(onUIClasseEffacerClicked()));
    connect(ui->pushButtonExit, SIGNAL(clicked()),
            controller, SLOT(onUIClasseExitClicked()));
}

void UIClasse::setUpTableView()
{
    //liaison entre le tableView et la BD
    classeModel = new ClassModel(DBAccess::getInstance());
    ui->tableView->setModel(classeModel);
    classeModel->readAll();
}

bool UIClasse::getInputs(int* identifiant, QString &nom, bool* operation)
{
       *identifiant = ui->lineEditID->text().toInt();
        nom = ui->lineEditNom->text();
        *operation = ui->radioButtonCreer->isChecked(); // true si creation ...

        if(operation)
        {
             return true; // true si creation ...
        }
        else{
            return false;
        }
}

void UIClasse::initializeInputs()
{
    ui->lineEditID->setText("");
    ui->lineEditNom->setText("");
}

ClassModel* UIClasse::getClassModel()
{
    return classeModel;
}

QTableView* UIClasse::getTableView()
{
    return ui->tableView;
}

QString UIClasse::getCritere()
{
    return ui->comboBoxRechercherPar->currentText();
}

QString UIClasse::getRechercherInput()
{
    return ui->lineEditRechercher->text();
}

void UIClasse::on_tableView_clicked(const QModelIndex &index)
{
    QSqlRecord record;
    int i = index.row(); // now you know which record was selected
    record = classeModel->record(i);
    // getting data from selected row of the tableView to inputs
    ui->lineEditID->setText(record.value(0).toString());
    ui->lineEditNom->setText(record.value(1).toString());
}

void UIClasse::notificationError(QString message)
{
    QMessageBox::critical(this, "Error", message, QMessageBox::Ok);
}

void UIClasse::notificationInformation(QString message)
{
    QMessageBox::information(this, "Information", message, QMessageBox::Ok);
}

UIClasse::~UIClasse()
{
    delete ui;
    delete classeModel;
}
