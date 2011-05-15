#include "agenda.h"
//#include "Cadastro.h"
#include "register.h"
#include "query.h"
//#include "Consulta.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

Agenda::Agenda() : QDialog(0)
{
  layout = new QGridLayout(this);

  button = new QPushButton("Cadastro");
  connect(button, SIGNAL(clicked()), this, SLOT(opcaoCadastro()));
  layout->addWidget(button, 1, 1, 2, 20);

  button = new QPushButton("Consulta");
  connect(button, SIGNAL(clicked()), this, SLOT(opcaoConsulta()));
  layout->addWidget(button, 4, 1, 5, 20);

  button = new QPushButton("Ajuda");
  connect(button, SIGNAL(clicked()), this, SLOT(opcaoAjuda()));
  layout->addWidget(button, 7, 1, 8, 20);

  button = new QPushButton("Sair");
  connect(button, SIGNAL(clicked()), this, SLOT(opcaoSair()));
  layout->addWidget(button, 10, 1, 11, 20);

}

void Agenda::criarConexao()
{
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL3");

        db.setHostName("localhost");
        db.setDatabaseName("mysql");
        db.setUserName("root");
        db.setPassword("root");

        if(db.open()) {

                QSqlQuery query_database("CREATE DATABASE Agenda; USE Agenda;");

                QSqlQuery query_tabela("CREATE TABLE  Agenda.Contatos ("
                        "nome varchar(50) primary key NOT NULL,"
                        "dataNasc varchar(10) NOT NULL,"
                        "foneCel varchar(10) NOT NULL,"
                        "foneRes varchar(10) NOT NULL,"
                        "sexo varchar(10) NOT NULL,"
                        "email varchar(20) NOT NULL)");
        }
        else {
                QMessageBox msgBox;
        msgBox.setText("Gerenciador MySQL inoperante.");
        msgBox.exec();
        exit(0);
        }
}

void Agenda::opcaoCadastro()
{
    Register opcao;
    //Cadastro opcao;
  opcao.show();
  this->hide();
  opcao.exec();
  this->show();
}

void Agenda::opcaoConsulta()
{
        Query opcao;
        //Consulta opcao;
        opcao.show();
        this->hide();
        opcao.exec();
        this->show();
}

void Agenda::opcaoAjuda()
{
  QMessageBox::information(this, "Agenda QT", "Essa opcao ira ser implementada algum dia.");
}

void Agenda::opcaoSair()
{
  QMessageBox::information(this, "Agenda QT", "Saindo do Aplicativo");
  this->close();
}
