#ifndef SERVICE_H
#define SERVICE_H

#include "user.h"
#include "usermodel.h"
#include "module.h"
#include "modulemodel.h"
#include "classe.h"
#include "classmodel.h"
#include "formateur.h"
#include "formateurmodel.h"

#include <QDebug>
#include <QMessageBox>

class Service
{
private:
    static Service* instance; // The single instance
    QString connection;

    Service();
    ~Service();

public:    
    // How to get the single instance of Service
    static Service* getInstance();

    // How to release the single instance of DBAccess
    static void release();

    // Users
    bool authentifier(QString login, QString password, User* user);
    void createUser(User user);
    void updateUser(User user, UserModel* userModel);
    void deleteUser(uint identifiant, UserModel* userModel);
    void readUserBy(QString login, UserModel* userModel);
    void readAllUsers(UserModel* userModel);
    void cleanTable(UserModel* userModel);

    // Modules
    void createModule(Module module);
    void updateModule(Module module, ModuleModel* moduleModel);
    void deleteModule(uint identifiant, ModuleModel* moduleModel);
    void readAllModules(ModuleModel* moduleModel);
    void cleanModuleTable(ModuleModel* moduleModel);

    // Classes
    void createClasse(Classe classe);
    void updateClasse(Classe classe, ClassModel* classeModel);
    void deleteClasse(uint identifiant, ClassModel* classeModel);
    void readAllClasses(ClassModel* classeModel);
    void cleanClasseTable(ClassModel* classeModel);

    // Formateurs
    void createFormateur(Formateur formateur);
    void readAllFormateurs(UserModel* userModel);

};

#endif // SERVICE_H
