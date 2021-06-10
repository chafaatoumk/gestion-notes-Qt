#include "formateurmodel.h"

#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlResult>

FormateurModel::FormateurModel(DBAccess *dbAccess)
{
   this->dbAccess = dbAccess;
   this->clear();
}

void FormateurModel::create(Formateur formateur)
{
   dbAccess->open();

   QSqlQuery query(dbAccess->database());
   query.prepare("INSERT INTO t_formateurs (nom, prenom, email, telephone, module, classe, created_at) "
                   "VALUES (:nom, :prenom, :email, :telephone, :module, :classe, datetime('now'))");
/*   query.bindValue(":nom", formateur.getNom());
   query.bindValue(":prenom", formateur.getPrenom());
   query.bindValue(":email", formateur.getEmail());
   query.bindValue(":telephone", formateur.getTelephone());
*/
   query.exec();

   readAll();

   qDebug () << "Formateur" << formateur.getIdentifiant() << "created successfully!";
   dbAccess->close();
}

void FormateurModel::readAll()
{
   dbAccess->open();

   QSqlDatabase database = dbAccess->database();
   this->setQuery("SELECT identifiant, nom, prenom, email, telephone, m.nom, c.nom FROM t_formateurs join t_modules m join t_classes c "
                "WHERE identifiant=t.identifiant and  ", database);

   this->setHeaderData(0, Qt::Horizontal, tr("IDENTIFIANT"));
   this->setHeaderData(1, Qt::Horizontal, tr("NOM"));
   this->setHeaderData(2, Qt::Horizontal, tr("PRENOM"));
   this->setHeaderData(3, Qt::Horizontal, tr("EMAIL"));
   this->setHeaderData(4, Qt::Horizontal, tr("TELEPHONE"));
   this->setHeaderData(5, Qt::Horizontal, tr("MODULE"));
   this->setHeaderData(6, Qt::Horizontal, tr("CLASSE"));

   qDebug () << "Formateurs displayed successfully!";
   dbAccess->close();
}

void FormateurModel::update(Formateur formateur)
{
   dbAccess->open();

   QSqlQuery query(dbAccess->database());
   query.prepare("UPDATE t_formateurs SET identifiant=:identifiant, nom=:nom, prenom=:prenom, email=:email, telephone=:telephone "
                    "module=:module, classe=:classe WHERE identifiant=:identifiant");
/*   query.bindValue(":nom", formateur.getNom());
   query.bindValue(":prenom", formateur.getPrenom());
   query.bindValue(":email", formateur.getEmail());
   query.bindValue(":telephone", formateur.getTelephone());
*/
   query.exec();

   readAll();

   qDebug () << "Formateur" << formateur.getIdentifiant() << " updated successfully!" ;
   dbAccess->close();
}

void FormateurModel::remove(uint identifiant)
{
   dbAccess->open();

   QSqlQuery query(dbAccess->database());
   query.prepare("DELETE FROM t_formateurs WHERE identifiant=:identifiant");
   query.bindValue(":identifiant", identifiant);
   query.exec();

   readAll();

   qDebug () << "User with id :" << identifiant << " has been deleted successfully!" ;
   dbAccess->close();
}

bool FormateurModel::readBy(QString nom)
{
   dbAccess->open();

   QSqlQuery query(dbAccess->database());
   query.prepare("SELECT identifiant AS IDENTIFIANT, nom AS NOM, prenom AS PRENOM,  email AS EMAIL, classe AS Classe, module AS MODULE "
                            "FROM t_formateurs WHERE nom=:nom");
   query.bindValue(":nom", nom);

   query.exec();

   if (false == query.next()) // Aucun enregistrement trouvé
   {
       return false;
   }

   qDebug() << "Formateur(s) with " << nom << "found.";
   dbAccess->close();

   return true;
}

void FormateurModel::clear()
{
   dbAccess->open();

   QSqlDatabase database = dbAccess->database();
   this->setQuery("SELECT * FROM t_formateurs WHERE identifiant=-1", database);

   this->setHeaderData(0, Qt::Horizontal, tr("IDENTIFIANT"));
   this->setHeaderData(1, Qt::Horizontal, tr("NOM"));
   this->setHeaderData(2, Qt::Horizontal, tr("PRENOM"));
   this->setHeaderData(3, Qt::Horizontal, tr("EMAIL"));
   this->setHeaderData(4, Qt::Horizontal, tr("TELEPHONE"));
   this->setHeaderData(5, Qt::Horizontal, tr("MODULE"));
   this->setHeaderData(6, Qt::Horizontal, tr("CLASSE"));

   dbAccess->close();
}

FormateurModel::~FormateurModel()
{
   qDebug() << "FormateurModel Object has been deleted!";
}

