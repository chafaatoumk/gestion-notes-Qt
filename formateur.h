#ifndef FORMATEUR_H
#define FORMATEUR_H

#include <QString>
#include <QSqlQueryModel>
#include "module.h"
#include "classe.h"


class Formateur: public QSqlQueryModel
{
private:
    uint identifiant;
    QString nom;
    QString email;
    Module module;
    Classe classe;

public:
    Formateur();
    Formateur(uint, QString, QString, Module, Classe);
    Formateur(QString, QString, Module, Classe);

    uint getIdentifiant() { return identifiant; }
    QString getNom() { return nom; }
    QString getEmail() { return email; }
    Module getModule() { return module; }
    Classe getClasse() { return classe; }

    void setIdentifiant(uint identifiant) { this->identifiant = identifiant; }
    void setNom(QString nom) { this->nom = nom; }
    void setEmail(QString email) { this->email= email; }
    void setModule(Module module) {  this->module = module; }
    void setClasse(Classe classe) { this->classe = classe; }
};

#endif // FORMATEUR_H
