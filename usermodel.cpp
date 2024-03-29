#include "usermodel.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlResult>

UserModel::UserModel(DBAccess *dbAccess)
{
    this->dbAccess = dbAccess;
    this->clear();
}

void UserModel::create(User user)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("INSERT INTO t_users (nom, prenom, email, telephone, login, password, type, created_at) "
                    "VALUES (:nom, :prenom, :email, :telephone, :login, :password, :type, datetime('now'))");
    query.bindValue(":nom", user.getNom());
    query.bindValue(":prenom", user.getPrenom());
    query.bindValue(":email", user.getEmail());
    query.bindValue(":telephone", user.getTelephone());
    query.bindValue(":login", user.getLogin());
    query.bindValue(":password", user.getPassword());
    query.bindValue(":type", user.getType());
    query.exec();

    readAll();

    qDebug () << "User" << user.getNom() << "created successfully!";
    dbAccess->close();
}

void UserModel::readAll()
{
    dbAccess->open();

    QSqlDatabase database = dbAccess->database();
    this->setQuery("SELECT * FROM t_users", database);

    this->setHeaderData(0, Qt::Horizontal, tr("IDENTIFIANT"));
    this->setHeaderData(1, Qt::Horizontal, tr("NOM"));
    this->setHeaderData(2, Qt::Horizontal, tr("PRENOM"));
    this->setHeaderData(3, Qt::Horizontal, tr("EMAIL"));
    this->setHeaderData(4, Qt::Horizontal, tr("TELEPHONE"));
    this->setHeaderData(5, Qt::Horizontal, tr("LOGIN"));
    this->setHeaderData(6, Qt::Horizontal, tr("MOT DE PASSE"));
    this->setHeaderData(7, Qt::Horizontal, tr("TYPE"));

    qDebug () << "Users displayed successfully!";
    dbAccess->close();
}

void UserModel::readAllFormateurs()
{
    dbAccess->open();

    QSqlDatabase database = dbAccess->database();
    this->setQuery("SELECT nom FROM t_users WHERE type=1", database);

    qDebug () << "Formateurs displayed successfully!";
    dbAccess->close();
}

void UserModel::update(User user)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("UPDATE t_users SET identifiant=:identifiant, nom=:nom, prenom=:prenom, email=:email, telephone=:telephone, login=:login, "
"password=:password, type=:type WHERE identifiant=:identifiant");
    query.bindValue(":nom", user.getNom());
    query.bindValue(":prenom", user.getPrenom());
    query.bindValue(":email", user.getEmail());
    query.bindValue(":telephone", user.getTelephone());
    query.bindValue(":login", user.getLogin());
    query.bindValue(":password", user.getPassword());
    query.bindValue(":type", user.getType());
    query.bindValue(":identifiant", user.getIdentifiant());
    query.exec();

    readAll();

    qDebug () << "User" << user.getNom() << " updated successfully!" ;
    dbAccess->close();
}

void UserModel::remove(uint identifiant)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("DELETE FROM t_users WHERE identifiant=:identifiant");
    query.bindValue(":identifiant", identifiant);
    query.exec();

    readAll();

    qDebug () << "User with id :" << identifiant << " has been deleted successfully!" ;
    dbAccess->close();
}

bool UserModel::readBy(QString login)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("SELECT identifiant AS IDENTIFIANT, nom AS NOM, prenom AS PRENOM, email AS EMAIL, telephone AS TELEPHONE "
                    "login AS LOGIN, type AS TYPE FROM t_users WHERE login=:login");
    query.bindValue(":login", login);

    query.exec();

    if (false == query.next()) // Aucun enregistrement trouvé
    {
        return false;
    }

    qDebug() << "User with login" << login << "found.";
    dbAccess->close();

    return true;
}

bool UserModel::readBy(QString login, QString password, User *user)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("SELECT identifiant, nom, prenom, email, telephone, login, type FROM t_users WHERE login=:login AND password=:password");
    query.bindValue(":login", login);
    query.bindValue(":password", password);
    query.exec();

    if (false == query.next()) // Aucun enregistrement trouvé
    {
        return false;
    }

    QSqlRecord record = query.record();
    user->setLogin(login);
    user->setPassword(password);
    user->setNom(query.value(record.indexOf("nom")).toString());
    user->setPrenom(query.value(record.indexOf("prenom")).toString());
    user->setEmail(query.value(record.indexOf("email")).toString());
    user->setTelephone(query.value(record.indexOf("telephone")).toString());
    user->setType(query.value(record.indexOf("type")).toString());
    user->setIdentifiant(query.value(record.indexOf("identifiant")).toUInt());

    qDebug() << "User with name" << user->getNom() << user->getPrenom() << "found.";
    dbAccess->close();

    return true;
}

void UserModel::clear()
{
    dbAccess->open();

    QSqlDatabase database = dbAccess->database();
    this->setQuery("SELECT * FROM t_users WHERE identifiant=-1", database);

    this->setHeaderData(0, Qt::Horizontal, tr("IDENTIFIANT"));
    this->setHeaderData(1, Qt::Horizontal, tr("NOM"));
    this->setHeaderData(2, Qt::Horizontal, tr("PRENOM"));
    this->setHeaderData(3, Qt::Horizontal, tr("EMAIL"));
    this->setHeaderData(4, Qt::Horizontal, tr("TELEPHONE"));
    this->setHeaderData(5, Qt::Horizontal, tr("LOGIN"));
    this->setHeaderData(6, Qt::Horizontal, tr("MOT DE PASSE"));
    this->setHeaderData(7, Qt::Horizontal, tr("TYPE"));

    dbAccess->close();
}

UserModel::~UserModel()
{
    qDebug() << "UserModel Object has been deleted!";
}
