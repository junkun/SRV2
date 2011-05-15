#include "truiwidget.h"
#include "ui_truiwidget.h"
#include <QProgressBar>
#include <QStatusBar>
#include <QProgressDialog>
#include <QTimer>

TrUiWidget::TrUiWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TrUiWidget)
{

        ui->setupUi(this);

       /*
       ui->progressBar->setRange(0,100); //100 must be a mike Variable
       for(int i=0;i<50;i++)//50 is the same variable as 100
          {
        /*Heres the mikes implementation mlp
        ui->progressBar->setValue(i);
        }
        ui->progressBar->setValue(60);//The fukin same variable
    */



//This is the example playing
            for (int i = 0; i < 100; i++) {
                ui->progressBar->setValue(i);
                //progress.setValue(i);
                 }
                ui->progressBar->setMaximum(0);


}



TrUiWidget::~TrUiWidget()
{
    delete ui;
}
