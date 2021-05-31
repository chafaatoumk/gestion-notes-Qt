#include "module.h"

Module::Module()
{}

Module::Module(uint _identifiant, QString _nom, uint _volumeHoraire):
    identifiant(_identifiant), nom(_nom), volume_horaire(_volumeHoraire)
{}

Module::Module(QString _nom, uint _volumeHoraire):
    nom(_nom), volume_horaire(_volumeHoraire)
{}
