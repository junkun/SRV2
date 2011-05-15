#include "queryshower.h"

#include <QSqlQuery>
#include <QMessageBox>

QueryShower::QueryShower(QString nome, QString data, QString celular, QString telefone, QString sexo, QString email) : QDialog()
{
        layout = new QGridLayout(this);

        label = new QLabel(this);
        label->setText("Nombre: ");
        layout->addWidget(label, 1, 1);

        label = new QLabel(this);
        label->setText("Fecha de nacimiento: ");
        layout->addWidget(label, 2, 1);

        label = new QLabel(this);
        label->setText("Sexo: ");
        layout->addWidget(label, 3, 1);

        label = new QLabel(this);
        label->setText("Comentario: ");
        layout->addWidget(label, 4, 1);

        label = new QLabel(this);
        label->setText("Imagen: ");
        layout->addWidget(label, 5, 1);

        label = new QLabel(this);
        label->setText("WAV: ");
        layout->addWidget(label, 6, 1);

        label_nome = new QLabel(this);
        label_nome->setText(nome);
        layout->addWidget(label_nome, 1, 2);

        line[0] = new QLineEdit();
        line[0]->insert(telefone);
        layout->addWidget(line[0], 4, 2);

        line[1] = new QLineEdit();
        line[1]->insert(celular);
        layout->addWidget(line[1], 5, 2);

        line[2] = new QLineEdit();
        line[2]->insert(email);
        layout->addWidget(line[2], 6, 2);

        date = new QDateEdit();
        QStringList lista = data.split(QRegExp("/"));
        QDate intermediario(2000+lista.at(2).toInt(false, 10), lista.at(1).toInt(false, 10), lista.at(0).toInt(false, 10));
        date->setDate(intermediario);
        layout->addWidget(date, 2, 2);

        combo = new QComboBox();
        combo->addItem("Masculino");
        combo->addItem("Femenino");
        if(sexo.compare("Masculino")==0)
                combo->setCurrentIndex(0);
        else
                combo->setCurrentIndex(1);
        layout->addWidget(combo, 3, 2);

        button = new QPushButton("Salir");
        connect(button, SIGNAL(clicked()), this, SLOT(opcExit()));
        layout->addWidget(button, 7, 1);

        button = new QPushButton("Borrar");
        connect(button, SIGNAL(clicked()), this, SLOT(opcDelete()));
        layout->addWidget(button, 7, 2);

        button = new QPushButton("Actualizar");
        connect(button, SIGNAL(clicked()), this, SLOT(opcUpdate()));
        layout->addWidget(button, 7, 3);

}

void QueryShower::opcUpdate()
{
        if(line[0]->text()!="" || line[1]->text()!="" || line[2]->text()!="") {
                QSqlQuery query("UPDATE srv001.persons SET dataNasc='"+date->text()+"'"
                                                ",foneCel='"+line[1]->text()+"'"
                                                ",foneRes='"+line[0]->text()+"'"
                                                ",sexo='"+combo->currentText()+"'"
                                                ",email='"+line[2]->text()+"'"
                                                " WHERE nome LIKE'"+label_nome->text()+"'");
                QMessageBox msgBox;
                msgBox.setText("Datos actualizados con exito!");
                msgBox.setInformativeText("Ok para continuar.");
                msgBox.exec();
        }
        this->close();
}

void QueryShower:: opcDelete()
{
        QMessageBox msgBox, confirma;
        msgBox.setText("Borrar Contacto.");
        msgBox.setInformativeText("Esta seguro?");
        msgBox.setStandardButtons(QMessageBox::No | QMessageBox::Yes);
        msgBox.setDefaultButton(QMessageBox::No);
        switch (msgBox.exec()) {
        case QMessageBox::Yes: {
                                                        QSqlQuery query("DELETE FROM srv001.persons WHERE nome='"+label_nome->text()+"'");
                                                        this->close();
                                                        confirma.setText("Registro eliminado");
                                                                confirma.setInformativeText("Ok para continuar.");
                                                                confirma.exec();
                                                        break;
        }
        case QMessageBox::No:  break;
        }
}

void QueryShower::opcExit()
{
        this->close();
}
