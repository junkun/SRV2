
#include "mnuiwidget.h"
#include "ui_mnuiwidget.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDesktopWidget>
///Agendas' libraries
#include "register.h"
#include "query.h"

MnUiWidget::MnUiWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MnUiWidget)
{
    ui->setupUi(this);
    layout = new QGridLayout(this);

    button = new QPushButton("Registro");
    connect(button, SIGNAL(clicked()), this, SLOT(opcRegister()));
    layout->addWidget(button, 1, 1, 2, 20);

    button = new QPushButton("Consulta");
    connect(button, SIGNAL(clicked()), this, SLOT(opcQuery()));
    layout->addWidget(button, 4, 1, 5, 20);

    button = new QPushButton("Salir");
    connect(button, SIGNAL(clicked()), this, SLOT(opcExit()));
    layout->addWidget(button, 7, 1, 8, 20);


}
void MnUiWidget::createConnection(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL3");

    db.setHostName("localhost");
    db.setDatabaseName("mysql");
    db.setUserName("root");
    db.setPassword("root");

    if(db.open()) {

            //QSqlQuery query_database("CREATE DATABASE Agenda; USE Agenda;");
        QSqlQuery query_database("srv001;");
/*
            QSqlQuery query_tabela("CREATE TABLE  Agenda.Contatos ("
                    "nome varchar(50) primary key NOT NULL,"
                    "dataNasc varchar(10) NOT NULL,"
                    "foneCel varchar(10) NOT NULL,"
                    "foneRes varchar(10) NOT NULL,"
                    "sexo varchar(10) NOT NULL,"
                    "email varchar(20) NOT NULL)");*/
    }
    else {
            QMessageBox msgBox;
    msgBox.setText("Problemas con el conector MySQL.");
    msgBox.exec();
    exit(0);
    }


}


void MnUiWidget::opcRegister(){

    QDesktopWidget *desktop = QApplication::desktop();
    int x, y;
    int WIDTH = 730;
    int HEIGHT = 350;
    int screenWidth;
    int screenHeight;

    screenWidth = desktop->width();
    screenHeight = desktop->height();

    x = (screenWidth - WIDTH) / 2;
    y = (screenHeight - HEIGHT) / 2;

    regAp = new Register;
    regAp->show();
    regAp->move(x,y);
    this->hide();




}
void MnUiWidget::opcQuery(){


    qryAp = new Query;
    qryAp->show();




}
void MnUiWidget::opcExit(){

    QMessageBox::information(this, "SRV-Manager", "Saliendo de SRV-Manager");

    this->close();

}

MnUiWidget::~MnUiWidget()
{
    delete ui;
}
