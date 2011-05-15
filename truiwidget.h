#ifndef TRUIWIDGET_H
#define TRUIWIDGET_H

#include <QWidget>
#include <QProgressBar>
#include <QBoxLayout>
#include <QSpinBox>

namespace Ui {
    class TrUiWidget;
}

class TrUiWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TrUiWidget(QWidget *parent = 0);
    ~TrUiWidget();

public slots:


private:
    Ui::TrUiWidget *ui;
            QWidget* win;
            QVBoxLayout* layout;
            QProgressBar* bar;
            QSpinBox* spin;
};

#endif // TRUIWIDGET_H
