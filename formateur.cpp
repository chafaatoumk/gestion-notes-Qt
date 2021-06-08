#include "formateur.h"

Formateur::Formateur()
{}

Formateur::Formateur(uint _identifiant, QString _nom, QString _prenom, QString _email, QString _telephone):
    identifiant(_identifiant), nom(_nom), prenom(_prenom), email(_email), telephone(_telephone)
{

}

Formateur::Formateur(QString _nom, QString _prenom, QString _email, QString _telephone):
                nom(_nom), prenom(_prenom), email(_email), telephone(_telephone)
{}

