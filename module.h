#ifndef MODULE_H
#define MODULE_H

#include <QString>


class Module
{
private:
    uint identifiant;
    QString nom;
    uint volume_horaire;

public:
    Module();
    Module(uint, QString, uint);
    Module(QString, uint);

    uint getIdentifiant() { return identifiant; }
    QString getNom() { return nom; }
    uint getVolumeHoraire() { return volume_horaire; }

    void setIdentifiant(uint identifiant) { this->identifiant = identifiant; }
    void setNom(QString nom) { this->nom = nom; }
    void setVolumeHoraire(uint volumeHoraire) { this->volume_horaire = volumeHoraire; }
};

#endif // MODULE_H
