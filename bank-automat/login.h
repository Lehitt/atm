#ifndef LOGIN_H
#define LOGIN_H
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>


#include <QWidget>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_BtnLogin_clicked();
    void loginSlot();

private:
    Ui::Login *ui;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QByteArray webToken;
};

#endif // LOGIN_H
