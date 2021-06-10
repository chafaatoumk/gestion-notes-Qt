#include "user.h"

User::User()
{}

User::User(uint _identifiant, QString _nom, QString _prenom, QString _email, QString _telephone, QString _login, QString _password):
    identifiant(_identifiant), nom(_nom), prenom(_prenom), email(_email), telephone(_telephone), login(_login), password(_password)
{}

User::User(QString _nom, QString _prenom, QString _email, QString _telephone, QString _login, QString _password):
    nom(_nom), prenom(_prenom), email(_email), telephone(_telephone), login(_login), password(_password)
{}

TypeUser User::getType()
{
    if(type.compare("ADMINISTRATEUR") == 0)
        return TypeUser::ADMINISTRATEUR;
    else if(type.compare("FORMATEUR") == 0)
        return TypeUser::FORMATEUR;
    else if(type.compare("ETUDIANT") == 0)
        return TypeUser::ETUDIANT;
    else
        return TypeUser::RESPONSABLE;
}
