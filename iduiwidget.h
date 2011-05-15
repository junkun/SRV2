#ifndef IDUIWIDGET_H
#define IDUIWIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include "ui_iduiwidget.h"

namespace Ui {
    class IdUiWidget;
}

class IdUiWidget : public QWidget
{
    Q_OBJECT

public:
    explicit IdUiWidget(QWidget *parent = 0);
       void createConnection();

    ~IdUiWidget();

private:
    Ui::IdUiWidget *ui;
    QGraphicsScene *scene;
    QLabel *iconLabel;
    QLabel *imageLabel;
};

#endif // IDUIWIDGET_H
/*

 #include <QDialog>
 #include <QTcpServer>
 #include <QTcpSocket>

 class QDialogButtonBox;
 class QLabel;
 class QProgressBar;
 class QPushButton;
 class QTcpServer;
 class QTcpSocket;

 class Dialog : public QDialog
 {
     Q_OBJECT

 public:
     Dialog(QWidget *parent = 0);

 public slots:
     void start();
     void acceptConnection();
     void startTransfer();
     void updateServerProgress();
     void updateClientProgress(qint64 numBytes);
     void displayError(QAbstractSocket::SocketError socketError);

 private:
     QProgressBar *clientProgressBar;
     QProgressBar *serverProgressBar;
     QLabel *clientStatusLabel;
     QLabel *serverStatusLabel;
     QPushButton *startButton;
     QPushButton *quitButton;
     QDialogButtonBox *buttonBox;

     QTcpServer tcpServer;
     QTcpSocket tcpClient;
     QTcpSocket *tcpServerConnection;
     int bytesToWrite;
     int bytesWritten;
     int bytesReceived;
 };






*/
