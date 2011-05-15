#ifndef WIDGET_H
#define WIDGET_H
#include <QMainWindow>
#include <QWidget>
//Recorder
#include <tvruiwidget.h>
#include <iduiwidget.h>
//Identifier
#include <truiwidget.h>
//Resporter
#include <rpuiwidget.h>
//Manager
#include <mnuiwidget.h>


namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:

bool openCorpus();
bool openIdentities();
void openIdentifier();
void openManager();
void openReporter();
void openTrainner();
//void openAgenda();

private:
    Ui::Widget *ui;
    IdUiWidget *idruiw; /*SRV Identifier */
    MnUiWidget *mnuiw;  /*SRV Manager*/
    RpUiWidget *rpuiw;  /*SRV Reporter*/
    TrUiWidget *truiw;  /*SRV Trainner */

//    Ui::tvrWindow *tvruiw;

private slots:
  //  void openRecord();

};

#endif // WIDGET_H
