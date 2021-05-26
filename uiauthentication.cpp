#include "uiauthentication.h"
#include "ui_uiauthentication.h"
#include <QMessageBox>

UIauthentication::UIauthentication(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UIauthentication)
{
    ui->setupUi(this);
}

UIauthentication::UIauthentication(QObject *controller)
    : ui(new Ui::UIauthentication)
{
    ui->setupUi(this);

    connect(ui->pushButton_login, SIGNAL(clicked()), controller, SLOT(onUIAuthentificationLoginClicked()));
}

bool UIauthentication::getInputs(QString &login, QString &password)
{
    login = ui->lineEdit_username->text();
    password = ui->lineEdit_password->text();

    if(login.compare("") == 0 || password.compare("") == 0)
    {
        QMessageBox::critical(this, "Missing informations", "Veuillez remplir tous les champs s'il vous plait !",
                                QMessageBox::Ok);
        return false;
    }

    return true;
}

void UIauthentication::notificationError(QString message)
{
    QMessageBox::critical(this, "Error", message, QMessageBox::Ok);
}

void UIauthentication::notificationInformation(QString message)
{
    QMessageBox::critical(this, "Information", message, QMessageBox::Ok);
}

UIauthentication::~UIauthentication()
{
    delete ui;
}

