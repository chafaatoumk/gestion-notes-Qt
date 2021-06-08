#ifndef FORMATEURMODEL_H
#define FORMATEURMODEL_H

#include <QSqlQueryModel>

#include "dbaccess.h"
#include "formateur.h"


class FormateurModel : public QSqlQueryModel
{
private:
    DBAccess *dbAccess;

public:
    FormateurModel(DBAccess *dbAccess);
    ~FormateurModel();

    void clear();

    // CRUD methods
    void create(Formateur formateur);
    void update(Formateur formateur);
    void remove(uint identifiant);
    bool readBy(QString nom);
    void readAll();
};

#endif // FORMATEURMODEL_H
