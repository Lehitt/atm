#include "login.h"
#include "ui_login.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QIntValidator>

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    //
    manager = new QNetworkAccessManager(this);
    ui->Pin->setValidator(new QIntValidator(0,9999,this));
    ui->cardNumber->setValidator(new QIntValidator(0,9999,this));
}

Login::~Login()
{
    delete ui;
}

void Login::on_BtnLogin_clicked()
{
    QString site_url="http://86.50.21.128:3000/login";
    QNetworkRequest request(site_url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        // muuttaa cardNumberin ja PIN json muotoon
    QJsonObject json;
        json["cardNumber"] = ui->cardNumber->text();
        json["pin"] = ui->Pin->text();
        // lähettää tiedot post:illa ja saadaan takaisin tokeni
        reply = manager->post(request, QJsonDocument(json).toJson());

        connect(reply, &QNetworkReply::finished, this, &Login::loginSlot);
}
void Login::loginSlot()
{
            // Tarkistetaan verkkovirheet ja se että PIN ja Kortti ovat oikeita
    if (reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt()==401){
                ui->TextP->setText("Kirjautuminen epäonnistui!\nVäärä PIN tai kortin numero!");
                qDebug()<<"Kirjautuminen epäonnistui! Väärä PIN tai kortin numero";
    }else if((reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt()==500)){
            ui->TextP->setText("Verkkovirhe!");
            qWarning() << "Network error:" << reply->errorString();
            qDebug()<<"Network error:";
            reply->deleteLater();
            return;
    }else {

            QByteArray response_data=reply->readAll();
                // Muunnetaan vastaus QByteArray-tyyppisestä JSON-dokumentiksi
            QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
            // Muunnetaan JSON-dokumentti JSON-arrayksi
            QJsonObject json_obj = json_doc.object();
            // Käsitellään JSON-Objectia

            QString token = json_obj["token"].toString();

                // tarkistaa saatiinko token vai onko se tyhjä
                if (!token.isEmpty()){
                    QByteArray myToken="Bearer "+token.toUtf8();
                    qDebug()<<"Kirjautuminen onnistui!";
                    ui->TextP->setText("Kirjautuminen onnistui!");

                    //tähän ehkä tulee se koodipätkä joka aukaisee uuden ikkunan eli sen "päävalikon"

                } else {
                    qDebug()<<"VIRHE! Täytä PIN ja kortin numero!";
                    ui->TextP->setText("VIRHE! Täytä PIN ja kortin numero!");
                }

            reply->deleteLater();
    }
};






