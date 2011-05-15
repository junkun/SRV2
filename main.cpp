//#include <QtGui/QApplication>
#include <QApplication>
#include "widget.h"
#include <QtGui/QApplication>
#include "widget.h"
 #include <QSplashScreen>
 #include <QString>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pixmap("../srv-build-desktop/images/ScreenSplash_TT_1_best.jpg");
    QSplashScreen splash(pixmap);
    splash.show();
    a.processEvents();
    sleep(.5);

    a.setApplicationName("Sistema de Reconocimiento de Voz");
    a.setQuitOnLastWindowClosed(true);

      int screenWidth;
      int screenHeight;
      int x, y;
      int WIDTH = 730;
      int HEIGHT = 350;

      Widget w;

        QDesktopWidget *desktop = QApplication::desktop();

        screenWidth = desktop->width();
        screenHeight = desktop->height();

        x = (screenWidth - WIDTH) / 2;
        y = (screenHeight - HEIGHT) / 2;

        w.resize(WIDTH, HEIGHT);
        w.move( x, y );
        w.show();

    //Inicialize first gst parameters
//        gst_init(&argc, &argv);
//        TvrUiWidget tvr;
//        tvr.show();


    splash.finish(&w);
    return a.exec();
}
