#ifndef UIMODULE_H
#define UIMODULE_H

#include <QMainWindow>
#include "modulemodel.h"
#include "dbaccess.h"
#include <QTableView>
#include <QSqlRecord>
#include <QModelIndex>
#include <QMessageBox>

namespace Ui {
class UIModule;
}

class UIModule : public QMainWindow
{
    Q_OBJECT

public:
    explicit UIModule(QWidget *parent = nullptr);
    UIModule(QObject* controller = nullptr);
    ~UIModule();

    bool getInputs(int* identifiant, QString &nom, uint &volumeHoraire, bool* operation);
    void initializeInputs();
    ModuleModel* getModuleModel();
    QTableView* getTableView();
    void setUpTableView();
    QString getCritere();
    QString getRechercherInput();
    void notificationError(QString message);
    void notificationInformation(QString message);

private slots:

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::UIModule *ui;
    ModuleModel* moduleModel;
};

#endif // UIMODULE_H
