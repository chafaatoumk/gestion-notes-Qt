#ifndef SERVICE_H
#define SERVICE_H

#include "user.h"
#include "usermodel.h"
#include "module.h"
#include "modulemodel.h"
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

    // Formateurs
    void createFormateur(Formateur formateur);

};

#endif // SERVICE_H
