#ifndef UICLASSE_H
#define UICLASSE_H

#include <QMainWindow>
#include "classmodel.h"
#include "dbaccess.h"
#include <QTableView>
#include <QSqlRecord>
#include <QModelIndex>
#include <QMessageBox>

namespace Ui {
class UIClasse;
}

class UIClasse : public QMainWindow
{
    Q_OBJECT

public:
    explicit UIClasse(QWidget *parent = nullptr);
    UIClasse(QObject* controller = nullptr);

    ~UIClasse();

    bool getInputs(int* identifiant, QString &nom, bool* operation);
    ClassModel* getClassModel();
    QTableView* getTableView();
    void setUpTableView();
    QString getCritere();
    QString getRechercherInput();
    void notificationError(QString message);
    void notificationInformation(QString message);
    void initializeInputs();

private slots:

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::UIClasse *ui;
    ClassModel* classeModel;
};

#endif // UICLASSE_H
