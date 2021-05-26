#ifndef FRONTCONTROLLER_H
#define FRONTCONTROLLER_H

#include "uiauthentication.h"
#include "uiadministrateur.h"
#include "service.h"

class FlowController : public QObject
{
    Q_OBJECT

private:
    // les interfaces graphiques UIComponent
    UIauthentication* uiAuthentification;
    UIAdministrateur* uiAdministrateur;

    // couche service
    Service* service;

private slots:
    /*
        les fonctions à executer suite au click des boutons respectifs
        de la fenetre d'authentification
    */
    void onUIAuthentificationLoginClicked();
    void onUIAuthentificationSignUpClicked();
    void onUIAuthentificationExitClicked();

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

public:
    void exec();    

    FlowController();
    ~FlowController();
};

#endif // FLOWTCONTROLLER_H
