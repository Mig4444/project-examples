#include <QApplication>
#include <QDebug>
#include "view.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QString fileName;

    if (argc >= 2)
    {
        qDebug()<<"argc >= 2";
        fileName = argv[1];
    }
    else
    {
        qDebug()<<"argc <= 2";
        fileName = ".";
    }

    TabDialog tabdialog;
    tabdialog.show();


    return app.exec();
}
