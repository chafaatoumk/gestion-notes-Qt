#include "responsable.h"
#include "ui_responsable.h"

Responsable::Responsable(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Responsable)
{
    ui->setupUi(this);
}

Responsable::Responsable(QObject *controller)
    : ui(new Ui::Responsable)
{
    ui->setupUi(this);

    connect(ui->pushButtonModules, SIGNAL(clicked()),
            controller, SLOT(onUIResponsableModulesClicked()));
    connect(ui->pushButtonFormateurs, SIGNAL(clicked()),
            controller, SLOT(onUIResponsableFormateursClicked()));
    connect(ui->pushButtonEtudiants, SIGNAL(clicked()),
            controller, SLOT(onUIResponsableEtudiantsClicked()));
    connect(ui->pushButtonClasses, SIGNAL(clicked()),
            controller, SLOT(onUIResponsableClassesClicked()));
}

Responsable::~Responsable()
{
    delete ui;
}
