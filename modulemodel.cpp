#include "modulemodel.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlResult>

ModuleModel::ModuleModel(DBAccess *dbAccess)
{
    this->dbAccess = dbAccess;
    clear();
}

void ModuleModel::create(Module module)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("INSERT INTO t_modules (nom, volume_horaire, created_at) "
                    "VALUES (:nom, :volume_horaire, datetime('now'))");
    query.bindValue(":nom", module.getNom());
    query.bindValue(":volume_horaire", module.getVolumeHoraire());
    query.exec();

    readAll();

    qDebug () << "Module" << module.getNom() << "created successfully!";
    dbAccess->close();
}

void ModuleModel::readAll()
{
    dbAccess->open();

    QSqlDatabase database = dbAccess->database();
    this->setQuery("SELECT * FROM t_modules", database);

    this->setHeaderData(0, Qt::Horizontal, tr("IDENTIFIANT"));
    this->setHeaderData(1, Qt::Horizontal, tr("NOM"));
    this->setHeaderData(2, Qt::Horizontal, tr("VOLUME HORAIRE"));
    this->setHeaderData(3, Qt::Horizontal, tr("DATE DE CREATION"));

    qDebug () << "Modules displayed successfully!";
    dbAccess->close();
}

void ModuleModel::update(Module module)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("UPDATE t_modules SET nom=:nom, volume_horaire=:volume_horaire "
                    "WHERE identifiant=:identifiant");
    query.bindValue(":nom", module.getNom());
    query.bindValue(":volume_horaire", module.getVolumeHoraire());
    query.bindValue(":identifiant", module.getIdentifiant());
    query.exec();

    readAll();

    qDebug () << "Module" << module.getNom() << " updated successfully!" ;
    dbAccess->close();
}

void ModuleModel::remove(uint identifiant)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("DELETE FROM t_modules WHERE identifiant=:identifiant");
    query.bindValue(":identifiant", identifiant);
    query.exec();

    readAll();

    qDebug () << "Module with id :" << identifiant << " has been deleted successfully!" ;
    dbAccess->close();
}

bool ModuleModel::readBy(QString nom)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("SELECT identifiant AS Identifiant, nom AS Nom, volume_horaire AS VolumeHoraire FROM t_modules WHERE nom=:nom");
    query.bindValue(":name", nom);
    query.exec();

    if (false == query.next()) // Aucun enregistrement trouvé
    {
        return false;
    }

    qDebug() << "Module with name" << nom << "found.";
    dbAccess->close();

    return true;
}

bool ModuleModel::readBy(QString nom, Module *module)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("SELECT * FROM t_modules WHERE nom=:nom");
    query.bindValue(":nom", nom);
    query.exec();

    if (false == query.next()) // Aucun enregistrement trouvé
    {
        return false;
    }

    QSqlRecord record = query.record();
    module->setNom(nom);
    module->setVolumeHoraire(query.value(record.indexOf("volume_horaire")).toUInt());
    module->setIdentifiant(query.value(record.indexOf("identifiant")).toUInt());

    qDebug() << "Module with name" << module->getNom() << "found.";
    dbAccess->close();

    return true;
}

void ModuleModel::clear()
{
    dbAccess->open();

    QSqlDatabase database = dbAccess->database();
    this->setQuery("SELECT * FROM t_modules WHERE identifiant=-1", database);

    this->setHeaderData(0, Qt::Horizontal, tr("IDENTIFIANT"));
    this->setHeaderData(1, Qt::Horizontal, tr("NOM"));
    this->setHeaderData(2, Qt::Horizontal, tr("VOLUME HORAIRE"));
    this->setHeaderData(3, Qt::Horizontal, tr("DATE DE CREATION"));

    dbAccess->close();
}

ModuleModel::~ModuleModel()
{
    qDebug() << "ModuleModel Object has been deleted!";
}
