#include "mainwindow.h"
#include <QApplication>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#ifdef Q_OS_MAC
    QDir::setCurrent(QCoreApplication::applicationDirPath() + "/../../../");
#else
    QDir::setCurrent(QCoreApplication::applicationDirPath());
#endif

    MainWindow w;
    w.show();

    return a.exec();
}
