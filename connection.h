 #ifndef CONNECTION_H
 #define CONNECTION_H

 #include <QMessageBox>
 #include <QSqlDatabase>
 #include <QSqlError>
 #include <QSqlQuery>


 static bool createConnection()
 {
     QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
     db.setDatabaseName(":memory:");
     if (!db.open()) {
         QMessageBox::critical(0, qApp->tr("Cannot open database"),
             qApp->tr("Unable to establish a database connection.\n"
                      "This example needs SQLite support. Please read "
                      "the Qt SQL driver documentation for information how "
                      "to build it.\n\n"
                      "Click Cancel to exit."), QMessageBox::Cancel);
         return false;
     }

     QSqlQuery query;
     query.exec("create table images (locationid int, file varchar(20))");
     query.exec("insert into images values(0, 'images/oslo.png')");
     query.exec("insert into images values(1, 'images/brisbane.png')");
     query.exec("insert into images values(2, 'images/redwood.png')");
     query.exec("insert into images values(3, 'images/berlin.png')");
     query.exec("insert into images values(4, 'images/munich.png')");
     query.exec("insert into images values(5, 'images/beijing.png')");
     return true;
 }

 #endif
