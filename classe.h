#ifndef CLASSE_H
#define CLASSE_H
#include <QString>

class Classe
{
private:
    uint identifiant;
    QString nom;

public:
    Classe();
    Classe(uint, QString);
    Classe(QString);

    uint getIdentifiant() { return identifiant; }
    QString getNom() { return nom; }

    void setIdentifiant(uint identifiant) { this->identifiant = identifiant; }
    void setNom(QString nom) { this->nom = nom; }
};

#endif // CLASSE_H
