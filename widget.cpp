#include "ui_widget.h"
#include "widget.h"
//#include "agenda.h"
#include "iduiwidget.h"
#include <QMessageBox>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QtSql/QSqlError>

#include <QtSql/QtSql>
#include <QMessageBox>
#include <QtSql/qsqldatabase.h>

#include <QSqlTableModel>
#include <QTableView>
#include <QTreeView>
#include <QDirModel>
#include<QGridLayout>
#include <QtGui>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}


void identitiesModel()
{
  QSqlQueryModel *model = new QSqlQueryModel();

  model->setQuery( "SELECT id, nome,dataNasc, sexo FROM persons;" );
  //Just testing columns headers
model->setHeaderData( 0, Qt::Horizontal, QObject::tr("Id") );
model->setHeaderData( 1, Qt::Horizontal, QObject::tr("Nombre") );
model->setHeaderData( 2, Qt::Horizontal, QObject::tr("Fecha de Nacimiento") );
model->setHeaderData( 3, Qt::Horizontal, QObject::tr("sexo") );

  QTableView *view = new QTableView();
  view->setModel( model );
  view->show();
}
void corpusModel()
{
  QSqlQueryModel *model = new QSqlQueryModel();

  model->setQuery( "SELECT * FROM params;" );
  //Just testing columns headers
model->setHeaderData( 0, Qt::Horizontal, QObject::tr("Id") );
model->setHeaderData( 1, Qt::Horizontal, QObject::tr("Nombre") );


  QTableView *view = new QTableView();
  view->setModel( model );
  view->show();
}


bool Widget::openCorpus(){

    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL3");


         /*Database Connector*/
          db.setHostName("localhost");
          db.setDatabaseName("srv001");
          db.setUserName("root");
          db.setPassword("root");

      if(!db.open()){
              QMessageBox::critical(0,"Database Error",db.lastError().text());
              return false;
              }

      QSqlQuery qry;
      qry.prepare("SELECT id, nombre,fechaNac, sexo FROM persons;");
      qry.exec();

     corpusModel();
     return true;
    }
bool Widget::openIdentities(){

      QSqlDatabase db2=QSqlDatabase::addDatabase("QMYSQL3");

           /*Database Connector*/
            db2.setHostName("localhost");
            db2.setDatabaseName("srv001");
            db2.setUserName("root");
            db2.setPassword("root");

        if(!db2.open()){
                QMessageBox::critical(0,"Database Error",db2.lastError().text());
                return false;
                }

         identitiesModel();
         return true;
}


void Widget::openIdentifier(){
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
    idruiw = new IdUiWidget;
    idruiw->show();
    idruiw->move(x,y);
}
void Widget::openTrainner(){
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
    truiw = new TrUiWidget;
     truiw->show();
     truiw->move(x,y);
    }

void Widget::openManager(){
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

    mnuiw = new MnUiWidget;
    mnuiw->createConnection();

    mnuiw->show();
    mnuiw->move(x,y);
    }
void Widget::openReporter(){
    }
/*void Widget::openAgenda(){
    Agenda dlg;

    dlg.criarConexao();
    dlg.show();


}*/

Widget::~Widget()
{
    delete ui;
}
