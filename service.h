#ifndef SERVICE_H
#define SERVICE_H

#include "user.h"
#include "module.h"
#include "usermodel.h"
#include "modulemodel.h"
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

    bool authentifier(QString login, QString password, User* user);
    void createUser(User user);
    void readAllUsers();

    void createModule(Module module);
};

#endif // SERVICE_H
