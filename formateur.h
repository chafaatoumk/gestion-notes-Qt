#ifndef FORMATEUR_H
#define FORMATEUR_H

#include <QString>
#include <QSqlQueryModel>
#include <user.h>
#include "module.h"
#include "classe.h"


class Formateur: public QSqlQueryModel
{
private:
    uint identifiant;
    User* user;
    Module* module;
    Classe* classe;

public:
    Formateur();
    Formateur(uint);
    Formateur(QString, QString);

    uint getIdentifiant() { return identifiant; }
    // Module getModule() { return module; }
    // Classe getClasse() { return classe; }

    void setIdentifiant(uint identifiant) { this->identifiant = identifiant; }
   // void setModule(Module module) {  this->module = module; }
   // void setClasse(Classe classe) { this->classe = classe; }
};

#endif // FORMATEUR_H
