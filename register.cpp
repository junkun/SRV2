#include "register.h"
#include <QSqlQuery>
#include <QMessageBox>

Register::Register() : QDialog()
{
        layout = new QGridLayout(this);

        label = new QLabel(this);
        label->setText("Nombre: ");
        layout->addWidget(label, 1, 1);

        label = new QLabel(this);
        label->setText("Fecha de Nacimiento: ");
        layout->addWidget(label, 2, 1);

        label = new QLabel(this);
        label->setText("Sexo: ");
        layout->addWidget(label, 3, 1);

        label = new QLabel(this);
        label->setText("Info1:WAV ");
        layout->addWidget(label, 4, 1);

        label = new QLabel(this);
        label->setText("Info2:IMG ");
        layout->addWidget(label, 5, 1);

        label = new QLabel(this);
        label->setText("Comment: ");
        layout->addWidget(label, 6, 1);
    //Nombre
        line[0] = new QLineEdit();
        layout->addWidget(line[0], 1, 2);

        line[1] = new QLineEdit();
        layout->addWidget(line[1], 4, 2);

        line[2] = new QLineEdit();
        layout->addWidget(line[2], 5, 2);

        line[3] = new QLineEdit();
        layout->addWidget(line[3], 6, 2);

        date = new QDateEdit();
        layout->addWidget(date, 2, 2);

        combo = new QComboBox();
        combo->addItem("Masculino");
        combo->addItem("Femenino");
        layout->addWidget(combo, 3, 2);

        button = new QPushButton("Registrar");
        connect(button, SIGNAL(clicked()), this, SLOT(opcRegister()));
        layout->addWidget(button, 7, 2);

        button = new QPushButton("Salir");
        connect(button, SIGNAL(clicked()), this, SLOT(opcExit()));
        layout->addWidget(button, 7, 1);
}

void Register::opcRegister()
{
        if(line[0]->isModified()  && (line[1]->isModified() || line[2]->isModified() || line[3]->isModified())) {

        /*       QSqlQuery query("INSERT INTO Agenda.Contatos (nome,dataNasc,foneCel,foneRes,sexo,email) "
                                                "VALUES ('"+line[0]->text()+"','"
                                                                        +date->text()+"','"
                                                                        +line[1]->text()+"','"
                                                                        +line[2]->text()+"','"
                                                                        +combo->currentText()+"','"
                                                                        +line[3]->text()+"')");*/
            QSqlQuery query("INSERT INTO srv001.persons (nome,dataNasc,foneCel,foneRes,sexo,email) "
                                                            "VALUES ('"+line[0]->text()+"','"
                                                                                    +date->text()+"','"
                                                                                    +line[1]->text()+"','"
                                                                                    +line[2]->text()+"','"
                                                                                    +combo->currentText()+"','"
                                                                                    +line[3]->text()+"')");

                QMessageBox msgBox;
            msgBox.setText("Datos guardados con exito!");
            msgBox.setInformativeText("Ok para continuar.");
            msgBox.exec();
            limpar();
        }
}

void Register::limpar() {
        line[0]->clear();
        line[1]->clear();
        line[2]->clear();
        line[3]->clear();
}

void Register::opcExit()
{
        this->close();
}
