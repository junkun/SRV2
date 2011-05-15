#ifndef RPUIWIDGET_H
#define RPUIWIDGET_H

#include <QWidget>

namespace Ui {
    class RpUiWidget;
}

class RpUiWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RpUiWidget(QWidget *parent = 0);
    ~RpUiWidget();

private:
    Ui::RpUiWidget *ui;
};

#endif // RPUIWIDGET_H
