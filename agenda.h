#ifndef AGENDA_H_
#define AGENDA_H_

#include <QDialog>
#include <QPushButton>
#include <QGridLayout>

class Agenda : public QDialog
{
    Q_OBJECT

public:
    Agenda();
    void criarConexao();
    QPushButton *button;
    QGridLayout *layout;

public slots:
        void opcaoCadastro();
    void opcaoConsulta();
    void opcaoAjuda();
    void opcaoSair();

};

#endif /*AGENDA_H_*/
