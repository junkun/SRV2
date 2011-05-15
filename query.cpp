#include "query.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>

#include "query.h"
#include "queryshower.h"

Query::Query(): QDialog()
{

    layout = new QGridLayout(this);

    label = new QLabel(this);
    label->setText("Buscar por: ");
    layout->addWidget(label, 1, 1);

    tableWidget = new QTableWidget(this);
    tableWidget->setRowCount(5);
    tableWidget->setColumnCount(1);
    itemWidget = new QTableWidgetItem();
    itemWidget->setText("Nombre: ");
    tableWidget->setHorizontalHeaderItem(0, itemWidget);
    tableWidget->setColumnWidth(0,230);
    connect(tableWidget, SIGNAL(itemClicked(QTableWidgetItem *)), this, SLOT(filler()));
    layout->addWidget(tableWidget, 4, 1, 4, 2);

    text = new QTextEdit();
    text->setFixedHeight(30);
    connect(text, SIGNAL(textChanged()), this, SLOT(opcSearch()));
    layout->addWidget(text, 2, 1, 2, 2);

    combo = new QComboBox();
    combo->addItem("Nombre");
    combo->addItem("Comentario/Otro");
    layout->addWidget(combo, 1, 2);

    button = new QPushButton("Consultar");
    connect(button, SIGNAL(clicked()), this, SLOT(opcQuery()));
    layout->addWidget(button, 9, 2);

    button = new QPushButton("Salir");
    connect(button, SIGNAL(clicked()), this, SLOT(opcExit()));
    layout->addWidget(button, 9, 1);
    layout->setSizeConstraint(QLayout::SetFixedSize);

}

void Query::opcQuery(){
    if(text->toPlainText()!="" && cont!=0) {
            this->hide();


            QueryShower *opcao = new QueryShower(nome, data, celular, telefone, sexo, email);
            opcao->show();
            opcao->exec();

            this->show();
    }
    else {
            QMessageBox msgBox;
            msgBox.setText("Valor invalido!");
            msgBox.exec();
    }


}
void Query::opcSearch(){
    if(!combo->currentIndex()) {
            QSqlQuery query("SELECT* FROM srv001.persons WHERE nome LIKE '"+text->toPlainText()+"%'");
            QSqlRecord rec = query.record();

            tableWidget->clearContents();
            cont = 0;
            int indexNome = rec.indexOf("nome");
            int indexData = rec.indexOf("dataNasc");
            int indexCel = rec.indexOf("foneCel");
            int indexRes = rec.indexOf("foneRes");
            int indexSexo = rec.indexOf("sexo");
            int indexEmail = rec.indexOf("email");

            while(query.next()) {
                    itemWidget = new QTableWidgetItem();
                    itemWidget->setText(query.value(indexNome).toString());
                    tableWidget->setItem(cont, 0, itemWidget);
                    cont = cont + 1;
            }

            query.last();
            nome = query.value(indexNome).toString();
            data = query.value(indexData).toString();
            celular = query.value(indexCel).toString();
            telefone = query.value(indexRes).toString();
            sexo = query.value(indexSexo).toString();
            email = query.value(indexEmail).toString();
    }
    else {
            QSqlQuery query("SELECT* FROM srv001.persons WHERE foneCel LIKE '"+text->toPlainText()+"%'"
                            " OR foneRes LIKE '"+text->toPlainText()+"%'"
                            " OR nome LIKE '"+text->toPlainText()+"%'");
            QSqlRecord rec = query.record();

            tableWidget->clearContents();
            cont = 0;
            int indexNome = rec.indexOf("nome");
            int indexData = rec.indexOf("dataNasc");
            int indexCel = rec.indexOf("foneCel");
            int indexRes = rec.indexOf("foneRes");
            int indexSexo = rec.indexOf("sexo");
            int indexEmail = rec.indexOf("email");

            while(query.next()) {
                    itemWidget = new QTableWidgetItem();
                    itemWidget->setText(query.value(indexNome).toString());
                    tableWidget->setItem(cont, 0, itemWidget);
                    cont = cont + 1;
            }

            query.last();
            nome = query.value(indexNome).toString();
            data = query.value(indexData).toString();
            celular = query.value(indexCel).toString();
            telefone = query.value(indexRes).toString();
            sexo = query.value(indexSexo).toString();
            email = query.value(indexEmail).toString();
    }


}
void Query::opcExit(){
        this->close();
}
void Query::filler(){
text->setText(tableWidget->currentItem()->text());
}




