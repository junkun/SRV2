#ifndef REGISTER_H
#define REGISTER_H
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>
#include <QComboBox>
#include <QGridLayout>

class Register : public QDialog
{
  Q_OBJECT

public:
        Register();
        void clean();
        void limpar();

public slots:
  void opcRegister();
  void opcExit();

private:
        QPushButton *button;
        QLabel *label;
        QLineEdit *line[4];
        QDateEdit *date;
        QComboBox *combo;
        QGridLayout *layout;
};



#endif // REGISTER_H
