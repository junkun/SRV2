#include "iduiwidget.h"
#include "ui_iduiwidget.h"
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QString>

IdUiWidget::IdUiWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IdUiWidget)
{
    ui->setupUi(this);

    createConnection();
    //QSqlQuery query("SELECT file FROM srv001.images WHERE locationid == 56");

 // ui->personFoto->setPixmap(QPixmap(":/mainIcons/images/music.png"));
    //ui->personFoto->setPixmap(QPixmap(query));

    QSqlQuery query("SELECT file FROM srv001.images WHERE locationid == 56");
       // while (query.next()) {
            QString country = query.value(0).toString();
            ui->personFoto->setPixmap(QPixmap(country));

        //}

}

void IdUiWidget::createConnection(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL3");

    db.setHostName("localhost");
    db.setDatabaseName("mysql");
    db.setUserName("root");
    db.setPassword("root");

    if(db.open()) {

            //QSqlQuery query_database("CREATE DATABASE Agenda; USE Agenda;");
        QSqlQuery query_database("srv001;");


    }
    else {
            QMessageBox msgBox;
    msgBox.setText("Problemas con el conector MySQL.");
    msgBox.exec();
    exit(0);
    }


}

IdUiWidget::~IdUiWidget()
{
    delete ui;
}
