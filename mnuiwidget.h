#ifndef MNUIWIDGET_H
#define MNUIWIDGET_H
#include <QWidget>
#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include "register.h"
#include "query.h"

namespace Ui {
    class MnUiWidget;
}

class MnUiWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MnUiWidget(QWidget *parent = 0);
    void createConnection();
    QPushButton *button;
    QGridLayout *layout;
    ~MnUiWidget();
public slots:
    void opcRegister();
    void opcQuery();
    void opcExit();

private:
    Ui::MnUiWidget *ui;

    Register *regAp;
    Query *qryAp;

};

#endif // MNUIWIDGET_H
