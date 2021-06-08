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
    QString prenom;
    QString email;
    QString telephone;
    QString created_at;
    Module module;
    Classe classe;

public:
    Formateur();
    Formateur(uint, QString, QString, QString,  QString, QString);
    Formateur(QString, QString, QString,  QString);

    uint getIdentifiant() { return identifiant; }
    QString getNom() { return nom; }
    QString getPrenom() { return prenom; }
    QString getEmail() { return email; }
    QString getTelephone() { return telephone; }
    QString getCreated_at() { return created_at; }
    Module getModule() { return module; }
    Classe getClasse() { return classe; }

    void setIdentifiant(uint identifiant) { this->identifiant = identifiant; }
    void setNom(QString nom) { this->nom = nom; }
    void setPrenom(QString prenom) { this->prenom = prenom; }
    void setEmail(QString email) { this->email= email; }
    void setTelephone(QString telephone) { this->telephone = telephone; }
    void setModule(Module module) {  this->module = module; }
    void setClasse(Classe classe) { this->classe = classe; }
};

#endif // FORMATEUR_H
