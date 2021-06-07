#ifndef FRONTCONTROLLER_H
#define FRONTCONTROLLER_H

#include "uiauthentication.h"
#include "uiadministrateur.h"
#include "uimodule.h"
#include "responsable.h"
#include "gestionformateur.h"
#include "service.h"

class FlowController : public QObject
{
    Q_OBJECT

private:
    // les interfaces graphiques UIComponent
    UIauthentication* uiAuthentification;
    UIAdministrateur* uiAdministrateur;
    Responsable* uiResponsable;
    UIModule* uiModule;
    GestionFormateur* uiGestionFormateur;


    // couche service
    Service* service;

private slots:
    /*
        les fonctions à executer suite au click des boutons respectifs
        de la fenetre d'authentification
    */
    void onUIAuthentificationLoginClicked();

    /*
        les fonctions à executer suite au click des boutons respectifs
        de la page de l'administrateur
    */
    void onUIAdministrateurValiderClicked();
    void onUIAdministrateurListerClicked();
    void onUIAdministrateurEffacerClicked();
    void onUIAdministrateurSupprimerClicked();
    void onUIAdministrateurExitClicked();
    void onUIAdministrateurRechercherClicked();
    void onUIAdministrateurProfilClicked();


    /*
        les fonctions à executer suite au click des boutons respectifs
        de la page du responsable
    */
    void onUIResponsableModulesClicked();
    void onUIResponsableEtudiantsClicked();
    void onUIResponsableFormateursClicked();
    void onUIResponsableClassesClicked();

    /*
        les fonctions à executer suite au click des boutons respectifs
        de la page de gestion des modules(uimodule)
    */
    void onUIModuleCreerClicked();
    void onUIModuleModifierClicked();
    void onUIModuleSupprimerClicked();
    void onUIModuleListerClicked();
    void onUIModuleValiderClicked();

    /*
        les fonctions à executer suite au click des boutons respectifs
        de la page de gestion des formateurs(GestionFormateur)
    */
    void onUIGestionFormateurValiderClicked();
    void onUIGestionFormateurCreerClicked();
    void onUIGestionFormateurModifierClicked();
    void onUIGestionFormateurSupprimerClicked();
    void onUIGestionFormateurListerClicked();
    void onUIGestionFormateurRechercherClicked();

public:
    void exec();    

    FlowController();
    ~FlowController();
};

#endif // FLOWTCONTROLLER_H
