#include "flowcontroller.h"
#include <QDebug>
#include <QMessageBox>

FlowController::FlowController() : uiAuthentification(nullptr), uiAdministrateur (nullptr), uiResponsable(nullptr),
        uiModule(nullptr), uiGestionFormateur(nullptr)
{
     service = Service::getInstance();
}

/*
    les fonctions à executer suite au click des boutons respectifs
    de la fenetre d'authentification
*/
void FlowController::onUIAuthentificationLoginClicked()
{
    // 1- Recuperer le login et le mot de passe
    QString login;
    QString password;
    bool statut = uiAuthentification->getInputs(login, password);

    // 2- Demander à la couche Service de valider l'authentification
    // en lui fournissant le login, le password récupérés et le user à renseigner

    if(statut == true)
    {
        User user;
        statut = service->authentifier(login, password, &user);

        if(statut)
        {
            // Fermer la fenetre d'authentification;
            this->uiAuthentification->close();
            // Liberer les ressources
            delete uiAuthentification;
            uiAuthentification = nullptr;

            TypeUser userType = user.getType();
            switch(userType)
            {
                case ADMINISTRATEUR:
                    // Afficher la fenetre d'administration
                    uiAdministrateur = new UIAdministrateur(this);
                    uiAdministrateur->show();
                    break;
                case FORMATEUR:
                    // On affiche la fenêtre du formateur ...
                    this->uiAuthentification->notificationInformation("UIFormateur :: Working on it !");
                    break;
                case ETUDIANT:
                    // On affiche la fenêtre de l'étudiant ...
                    this->uiAuthentification->notificationInformation("UIEtudiant :: Working on it !");
                    break;
                case RESPONSABLE:
                    // On affiche la fenêtre du reponsable ...
                    uiResponsable = new Responsable(this);
                    uiResponsable->show();
                    break;

                default:;
            }
        }
        else
        {
            this->uiAuthentification->notificationError("Echec d'authentification !");
        }
    }
}

void FlowController::onUIAuthentificationSignUpClicked()
{

}

void FlowController::onUIAuthentificationExitClicked()
{

}

/*
    les fonctions à executer suite au click des boutons respectifs
    de la page de l'administrateur
*/
void FlowController::onUIAdministrateurValiderClicked()
{
    int identifiant = -1;
    QString login;
    QString password;
    QString type;
    bool operation;

    bool statut = this->uiAdministrateur->getInputs(&identifiant, login, password, type, &operation);
    if (statut == true)
    {
        if (operation == true)
        {
            // Creation
            User user ("", "", login, password);
            user.setType(type);

            service->createUser(user);
        }
        else
        {
            // Mise à jour ...
        }
    }
}

void FlowController::onUIAdministrateurListerClicked()
{

}

void FlowController::onUIAdministrateurEffacerClicked()
{

}

void FlowController::onUIAdministrateurSupprimerClicked()
{

}

void FlowController::onUIAdministrateurExitClicked()
{

}

void FlowController::onUIAdministrateurRechercherClicked()
{

}

void FlowController::onUIAdministrateurProfilClicked()
{

}


/*
    les fonctions à executer suite au click des boutons respectifs
    de la page du responsable
*/

void FlowController::onUIResponsableModulesClicked()
{
    uiModule = new UIModule(this);
    uiModule->show();
}

void FlowController::onUIResponsableEtudiantsClicked()
{

}

void FlowController::onUIResponsableFormateursClicked()
{
    uiGestionFormateur = new GestionFormateur(this);
    uiGestionFormateur->show();
}

void FlowController::onUIResponsableClassesClicked()
{

}

/*
    les fonctions à executer suite au click des boutons respectifs
    de la page de gestion des modules(uimodule)
*/
void FlowController::onUIModuleCreerClicked()
{

}

void FlowController::onUIModuleModifierClicked()
{

}

void FlowController::onUIModuleSupprimerClicked()
{

}

void FlowController::onUIModuleListerClicked()
{

}

void FlowController::onUIModuleValiderClicked()
{

}

/*
    les fonctions à executer suite au click des boutons respectifs
    de la page de gestion des formateurs(GestionFormateur)
*/
void FlowController::onUIGestionFormateurCreerClicked()
{

}

void FlowController::onUIGestionFormateurModifierClicked()
{

}

void FlowController::onUIGestionFormateurSupprimerClicked()
{

}

void FlowController::onUIGestionFormateurListerClicked()
{

}

void FlowController::onUIGestionFormateurRechercherClicked()
{

}

void FlowController::onUIGestionFormateurValiderClicked()
{

}

void FlowController::exec()
{
    uiAuthentification = new UIauthentication(this);
    uiAuthentification->show();
}

FlowController::~FlowController()
{
    if (uiAuthentification != nullptr)
    {
        delete uiAuthentification;
    }

    if (uiAdministrateur != nullptr)
    {
        delete uiAdministrateur;
    }

    if (service != nullptr)
    {
        Service::release(); // suppression d'un objet de qui a comme disign pattern de type singleton
    }
}
