#include "classmodel.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlResult>

ClassModel::ClassModel(DBAccess *dbAccess)
{
    this->dbAccess = dbAccess;
    this->clear();
}

void ClassModel::create(Classe classe)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("INSERT INTO t_classes (nom, created_at) VALUES (:nom, datetime('now'))");
    query.bindValue(":nom", classe.getNom());
    query.exec();

    readAll();

    qDebug () << "Classe" << classe.getNom() << "created successfully!";
    dbAccess->close();
}

void ClassModel::readAll()
{
    dbAccess->open();

    QSqlDatabase database = dbAccess->database();
    this->setQuery("SELECT * FROM t_classes", database);

    this->setHeaderData(0, Qt::Horizontal, tr("IDENTIFIANT"));
    this->setHeaderData(1, Qt::Horizontal, tr("NOM"));
    this->setHeaderData(2, Qt::Horizontal, tr("DATE DE CREATION"));

    qDebug () << "Classes displayed successfully!";
    dbAccess->close();
}

void ClassModel::update(Classe classe)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("UPDATE t_classes SET nom=:nom WHERE identifiant=:identifiant");
    query.bindValue(":nom", classe.getNom());
    query.bindValue(":identifiant", classe.getIdentifiant());
    query.exec();

    readAll();

    qDebug () << "Classe" << classe.getNom() << " updated successfully!" ;
    dbAccess->close();
}

void ClassModel::remove(uint identifiant)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("DELETE FROM t_classes WHERE identifiant=:identifiant");
    query.bindValue(":identifiant", identifiant);
    query.exec();

    readAll();

    qDebug () << "Classe with id :" << identifiant << " has been deleted successfully!" ;
    dbAccess->close();
}

bool ClassModel::readBy(QString nom)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("SELECT identifiant AS Identifiant, nom AS Nom FROM t_classes WHERE nom=:nom");
    query.bindValue(":nom", nom);
    query.exec();

    if (false == query.next()) // Aucun enregistrement trouvé
    {
        return false;
    }

    qDebug() << "Classe with login" << nom << "found.";
    dbAccess->close();

    return true;
}

bool ClassModel::readBy(QString nom, Classe *classe)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("SELECT identifiant, nom FROM t_classes WHERE nom=:nom");
    query.bindValue(":nom", nom);
    query.exec();

    if (false == query.next()) // Aucun enregistrement trouvé
    {
        return false;
    }

    QSqlRecord record = query.record();
    classe->setNom(nom);
    classe->setIdentifiant(query.value(record.indexOf("identifiant")).toUInt());

    qDebug() << "Classe with name" << classe->getNom() << "found.";
    dbAccess->close();

    return true;
}

void ClassModel::clear()
{
    dbAccess->open();

    QSqlDatabase database = dbAccess->database();
    this->setQuery("SELECT identifiant, nom FROM t_classes WHERE identifiant=-1", database);

    this->setHeaderData(0, Qt::Horizontal, tr("IDENTIFIANT"));
    this->setHeaderData(1, Qt::Horizontal, tr("NOM"));
    this->setHeaderData(2, Qt::Horizontal, tr("DATE DE CREATION"));

    dbAccess->close();
}

ClassModel::~ClassModel()
{
    qDebug() << "ClasseModel Object has been deleted!";
}
