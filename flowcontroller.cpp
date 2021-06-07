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

/*
    les fonctions à executer suite au click des boutons respectifs
    de la page de l'administrateur
*/
void FlowController::onUIAdministrateurValiderClicked()
{
    int identifiant = -1;
    QString login;
    QString password;
    QString nom;
    QString prenom;
    QString type;
    bool operation;

    bool statut = this->uiAdministrateur->getInputs(&identifiant, nom, prenom, login, password, type, &operation);
    if (statut == true)
    {
        // Creation d'un objet User
        User user (identifiant, nom, prenom, login, password);
        user.setType(type);

        if (operation == true)
        {
            service->createUser(user);
            uiAdministrateur->initializeInputs();
            QString message = "Utilisateur "+user.getNom()+" créé avec succès !";
            this->uiAdministrateur->notificationInformation(message);
        }
        else
        {
            service->updateUser(user, uiAdministrateur->getUserModel());
            uiAdministrateur->initializeInputs();
            QString message = "Utilisateur "+user.getNom()+" mis à jour avec succès !";
            this->uiAdministrateur->notificationInformation(message);
        }
    }
    service->readAllUsers(uiAdministrateur->getUserModel());
}

void FlowController::onUIAdministrateurListerClicked()
{
    service->readAllUsers(uiAdministrateur->getUserModel());
}

void FlowController::onUIAdministrateurEffacerClicked()
{
    service->cleanTable(uiAdministrateur->getUserModel());
}

void FlowController::onUIAdministrateurSupprimerClicked()
{
    int identifiant = -1;
    QString login;
    QString password;
    QString nom;
    QString prenom;
    QString type;
    bool operation;

    bool statut = this->uiAdministrateur->getInputs(&identifiant, nom, prenom, login, password, type, &operation);
    if (statut == true)
    {
        // Creation d'un objet User
        User user (identifiant, nom, prenom, login, password);
        user.setType(type);
        UserModel *userModel = uiAdministrateur->getUserModel();
        QString message = "Utilisateur "+user.getNom()+" suprimé avec succès !";

        service->deleteUser(user.getIdentifiant(), userModel);
        uiAdministrateur->initializeInputs();

        this->uiAdministrateur->notificationInformation(message);
        service->readAllUsers(uiAdministrateur->getUserModel());
    }
}

void FlowController::onUIAdministrateurExitClicked()
{
    uiAdministrateur->close();
}

void FlowController::onUIAdministrateurRechercherClicked()
{
    QString input = uiAdministrateur->getRechercherInput();
    QString critere = uiAdministrateur->getCritere();

    if(critere.compare("Username") == 0)
        service->readUserBy(input, uiAdministrateur->getUserModel());
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
    uiResponsable->close();
    uiModule = new UIModule(this);
    uiModule->show();
}

void FlowController::onUIResponsableEtudiantsClicked()
{

}

void FlowController::onUIResponsableFormateursClicked()
{
    uiResponsable->close();
    uiGestionFormateur = new GestionFormateur(this);
    uiGestionFormateur->show();
}

void FlowController::onUIResponsableClassesClicked()
{
    uiResponsable->close();
}

/*
    les fonctions à executer suite au click des boutons respectifs
    de la page de gestion des modules(uimodule)
*/
void FlowController::onUIModuleCreerClicked()
{
    /*uint identifiant = -1;
    QString nom;
    uint volumeHoraire;
    bool operation;

    bool statut = this->uiModule->getInputs(&identifiant, &nom, &volumeHoraire, &operation);
    if (statut == true)
    {
        if (operation == true)
        {
            // Creation
            Module module (nom, volumeHoraire);

            service->createModule(module);
            uiModule->initializeInputs();
        }
        else
        {
            // Mise à jour ...
        }
    } */
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
    int identifiant = -1;
    QString nom;
    uint volume_horaire;
    bool operation;

    bool statut = this->uiModule->getInputs(&identifiant, nom, volume_horaire, &operation);
    if (statut == true)
    {
        if (operation == true)
        {
            // Creation
            Module module (nom, volume_horaire);

            service->createModule(module);
            uiModule->initializeInputs();
        }
        else
        {
            // Mise à jour ...
        }
    }
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

    if (uiResponsable != nullptr)
    {
        delete uiResponsable;
    }

    if (uiGestionFormateur != nullptr)
    {
        delete uiGestionFormateur;
    }

    if (uiModule != nullptr)
    {
        delete uiModule;
    }

    if (service != nullptr)
    {
        Service::release(); // suppression d'un objet de qui a comme disign pattern de type singleton
    }
}
