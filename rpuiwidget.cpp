#include "rpuiwidget.h"
#include "ui_rpuiwidget.h"

RpUiWidget::RpUiWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RpUiWidget)
{
    ui->setupUi(this);
}

RpUiWidget::~RpUiWidget()
{
    delete ui;
}
