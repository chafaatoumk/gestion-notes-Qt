#include "uiclasse.h"
#include "ui_uiclasse.h"

UIClasse::UIClasse(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UIClasse)
{
    ui->setupUi(this);
}

UIClasse::~UIClasse()
{
    delete ui;
}
