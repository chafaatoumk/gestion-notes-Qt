#ifndef MODULEMODEL_H
#define MODULEMODEL_H

#include <QSqlQueryModel>

#include "dbaccess.h"
#include "module.h"


class ModuleModel: public QSqlQueryModel
{
private:
    DBAccess *dbAccess;

public:
    ModuleModel(DBAccess *dbAccess);
    ~ModuleModel();

    void clear();

    // CRUD methods
    void create(Module module);
    void update(Module module);
    void remove(uint identifiant);
    bool readBy(QString nom);
    bool readBy(QString nom, Module *module);
    void readAll();
    void readAllModules();

};

#endif // MODULEMODEL_H
