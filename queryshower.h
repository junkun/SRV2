#ifndef QUERYSHOWER_H
#define QUERYSHOWER_H
#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>
#include <QComboBox>

class QueryShower : public QDialog
{
        Q_OBJECT

public:
        QueryShower(QString nome, QString data, QString celular, QString telefone, QString sexo, QString email);

public slots:
        void opcUpdate();
        void opcDelete();
        void opcExit();

private:
        QPushButton *button;
        QGridLayout *layout;
        QLabel *label, *label_nome;
        QLineEdit *line[3];
        QDateEdit *date;
        QComboBox *combo;

};


#endif // QUERYSHOWER_H
