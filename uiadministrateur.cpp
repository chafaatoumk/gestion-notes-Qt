#include "uiadministrateur.h"
#include "ui_uiadministrateur.h"

UIAdministrateur::UIAdministrateur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UIAdministrateur)
{
    ui->setupUi(this);
    //liaison entre le tableView et la BD
    //userModel = new UserModel(DBAccess::getInstance());
    //ui->tableView->setModel(userModel);
}

UIAdministrateur::UIAdministrateur(QObject *controller)
    : ui(new Ui::UIAdministrateur)
{
    ui->setupUi(this);
    this->setUpTableView();

    connect(ui->pushButtonValider, SIGNAL(clicked()),
            controller, SLOT(onUIAdministrateurValiderClicked()));
    connect(ui->pushButtonLister, SIGNAL(clicked()),
            controller, SLOT(onUIAdministrateurListerClicked()));
    connect(ui->pushButtonRechercher, SIGNAL(clicked()),
            controller, SLOT(onUIAdministrateurRechercherClicked()));
    connect(ui->pushButtonSupprimer, SIGNAL(clicked()),
            controller, SLOT(onUIAdministrateurSupprimerClicked()));
    connect(ui->pushButtonRechercher, SIGNAL(clicked()),
            controller, SLOT(onUIAdministrateurRechercherClicked()));
    connect(ui->pushButtonEffacer, SIGNAL(clicked()),
            controller, SLOT(onUIAdministrateurEffacerClicked()));
    connect(ui->pushButtonExit, SIGNAL(clicked()),
            controller, SLOT(onUIAdministrateurExitClicked()));
}

void UIAdministrateur::setUpTableView()
{
    //liaison entre le tableView et la BD
    userModel = new UserModel(DBAccess::getInstance());
    ui->tableView->setModel(userModel);
    userModel->readAll();
}


UIAdministrateur::~UIAdministrateur()
{
    delete ui;
    delete userModel;
}

bool UIAdministrateur::getInputs(int* identifiant, QString &nom, QString &prenom, QString &email, QString &telephone, QString &login,
                                 QString &password, QString &type, bool* operation)
{
    *identifiant = ui->lineEditId->text().toInt();
    nom = ui->lineEditNom->text();
    prenom = ui->lineEditPrenom->text();
    email = ui->lineEditEmail->text();
    telephone = ui->lineEditTelephone->text();
    login = ui->lineEditUsername->text();
    password = ui->lineEditPassword->text();
    type = ui->comboBoxRole->currentText();
    *operation = ui->radioButtonCreer->isChecked();

    if(operation)
    {
         return true; // true si creation ...
    }
    else{
        return false;
    }
}

QLineEdit* UIAdministrateur::getLabelUtilisateurConnecte()
{
    return ui->lineEditUtilisateurConnecte;
}

UserModel* UIAdministrateur::getUserModel()
{
    return userModel;
}

QTableView* UIAdministrateur::getTableView()
{
    return ui->tableView;
}

QString UIAdministrateur::getCritere()
{
    return ui->comboBoxRechercherPar->itemText(0);
}

QString UIAdministrateur::getRechercherInput()
{
    return ui->lineEditRechercher->text();
}

void UIAdministrateur::initializeInputs()
{
    ui->lineEditId->setText("");

    ui->lineEditNom->setText("");
    ui->lineEditPrenom->setText("");
    ui->lineEditEmail->setText("");
    ui->lineEditTelephone->setText("");
    ui->lineEditUsername->setText("");
    ui->lineEditPassword->setText("");
    ui->lineEditConfirmPassword->setText("");
    ui->comboBoxRole->setCurrentText("Role");
}

void UIAdministrateur::on_tableView_clicked(const QModelIndex &index)
{
    QSqlRecord record;
    int i = index.row(); // now you know which record was selected
    record = userModel->record(i);
    // getting data from selected row of the tableView to inputs
    ui->lineEditId->setText(record.value(0).toString());
    ui->lineEditNom->setText(record.value(1).toString());
    ui->lineEditPrenom->setText(record.value(2).toString());
    ui->lineEditEmail->setText(record.value(3).toString());
    ui->lineEditTelephone->setText(record.value(4).toString());
    ui->lineEditUsername->setText(record.value(5).toString());
    ui->lineEditPassword->setText(record.value(6).toString());
    ui->lineEditConfirmPassword->setText(record.value(6).toString());
    ui->comboBoxRole->setCurrentText(record.value(7).toString());
}

void UIAdministrateur::notificationError(QString message)
{
    QMessageBox::critical(this, "Error", message, QMessageBox::Ok);
}

void UIAdministrateur::notificationInformation(QString message)
{
    QMessageBox::information(this, "Information", message, QMessageBox::Ok);
}
