#ifndef CLASSMODEL_H
#define CLASSMODEL_H

#include "dbaccess.h"
#include <QSqlQueryModel>
#include "classe.h"


class ClassModel : public QSqlQueryModel
{
private:
    DBAccess *dbAccess;

public:
    ClassModel(DBAccess *dbAccess);
    ~ClassModel();

    void clear();

    // CRUD methods
    void create(Classe classe);
    void update(Classe classe);
    void remove(uint identifiant);
    bool readBy(QString nom);
    bool readBy(QString nom, Classe *classe);
    void readAll();
    void readAllClasses();
};

#endif // CLASSMODEL_H
