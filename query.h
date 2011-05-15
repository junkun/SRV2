#ifndef QUERY_H
#define QUERY_H

#include <QDialog>
#include <QLabel>
#include <QGridLayout>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QComboBox>
#include <QPushButton>
#include <QTextEdit>

class Query:public QDialog
{
    Q_OBJECT
public:
    Query();
    QLabel *label;
    QGridLayout *layout;
    QTableWidget *tableWidget;
    QTableWidgetItem *itemWidget;
    QComboBox *combo;
    QPushButton *button;
    QTextEdit *text;
    QString nome, data, sexo, telefone, celular, email;
    int cont;

public slots:
        void opcQuery();
        void opcSearch();
        void filler();
        void opcExit();
};

#endif // QUERY_H
