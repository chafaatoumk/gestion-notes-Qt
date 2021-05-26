#ifndef UIAUTHENTICATION_H
#define UIAUTHENTICATION_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class UIauthentication; }
QT_END_NAMESPACE

class UIauthentication : public QMainWindow
{
    Q_OBJECT

public:
    UIauthentication(QWidget *parent = nullptr);
    UIauthentication(QObject *controller = nullptr);
    ~UIauthentication();

    bool getInputs(QString &login, QString &password);
    void notificationError(QString message);
    void notificationInformation(QString message);

private:
    Ui::UIauthentication *ui;
};
#endif // UIAUTHENTICATION_H
