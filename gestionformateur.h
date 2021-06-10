#ifndef GESTIONFORMATEUR_H
#define GESTIONFORMATEUR_H

#include <QMainWindow>
#include "formateurmodel.h"
#include "usermodel.h"
#include "classmodel.h"
#include "modulemodel.h"
#include "dbaccess.h"
#include <QTableView>
#include <QSqlRecord>
#include <QModelIndex>
#include <QMessageBox>

namespace Ui {
class GestionFormateur;
}

class GestionFormateur : public QMainWindow
{
    Q_OBJECT

public:
    explicit GestionFormateur(QWidget *parent = nullptr);
    GestionFormateur(QObject* controller = nullptr);
    ~GestionFormateur();

    bool getInputs(int* identifiant, QString &module, QString &classe, bool* operation);
    FormateurModel* getFormateurModel();
    QTableView* getTableView();
    void setUpComboBox();
    QString getCritere();
    QString getRechercherInput();
    void notificationError(QString message);
    void notificationInformation(QString message);
    void initializeInputs();

private slots:

    void on_tableView_clicked(const QModelIndex &index);


private:
    Ui::GestionFormateur *ui;
    FormateurModel* formateurModel;
    UserModel* userModel;
    ClassModel* classeModel;
    ModuleModel* moduleModel;
};

#endif // GESTIONFORMATEUR_H
