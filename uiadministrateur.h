#ifndef UIADMINISTRATEUR_H
#define UIADMINISTRATEUR_H

#include <QMainWindow>
#include "usermodel.h"
#include "dbaccess.h"
#include <QTableView>
#include <QSqlRecord>
#include <QModelIndex>
#include <QMessageBox>
#include <QLineEdit>

namespace Ui {
class UIAdministrateur;
}

class UIAdministrateur : public QMainWindow
{
    Q_OBJECT

public:
    UIAdministrateur(QWidget *parent = nullptr);
    UIAdministrateur(QObject* controller = nullptr);
    ~UIAdministrateur();

    bool getInputs(int* identifiant, QString &nom, QString &prenom, QString &login, QString &email, QString &telephone,
                   QString &password, QString &type, bool* operation);
    UserModel* getUserModel();
    QTableView* getTableView();
    void setUpTableView();
    QString getCritere();
    QString getRechercherInput();
    QLineEdit* getLabelUtilisateurConnecte();
    void notificationError(QString message);
    void notificationInformation(QString message);
    void initializeInputs();

private slots:

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::UIAdministrateur *ui;
    UserModel* userModel;
};

#endif // UIADMINISTRATEUR_H
