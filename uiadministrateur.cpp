#include "uiadministrateur.h"
#include "ui_uiadministrateur.h"

UIAdministrateur::UIAdministrateur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UIAdministrateur)
{
    ui->setupUi(this);
}

UIAdministrateur::UIAdministrateur(QObject *controller)
    : ui(new Ui::UIAdministrateur)
{
    ui->setupUi(this);

    connect(ui->pushButtonValider, SIGNAL(clicked()),
            controller, SLOT(onUIAdministrateurValiderClicked()));
}


UIAdministrateur::~UIAdministrateur()
{
    delete ui;
}

bool UIAdministrateur::getInputs(int* identifiant, QString &login, QString &password, QString &type, bool* operation)
{
    if (ui->lineEditId->text().compare("") != 0)
    //{
       *identifiant = ui->lineEditId->text().toInt();

        login = ui->lineEditUsername->text();
        password = ui->lineEditPassword->text();
        type = ui->comboBoxRole->itemText(0);
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
