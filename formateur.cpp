#include "formateur.h"

Formateur::Formateur()
{}

Formateur::Formateur(uint _identifiant, QString _nom, QString _prenom, QString _email, QString _telephone, QString _created_at):
    identifiant(_identifiant), nom(_nom), prenom(_prenom), email(_email), telephone(_telephone), created_at(_created_at)
{}

Formateur::Formateur(QString _nom, QString _prenom, QString _email, QString _telephone):
                nom(_nom), prenom(_prenom), email(_email), telephone(_telephone)
{}

