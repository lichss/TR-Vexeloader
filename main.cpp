#include "QtVisualLoader1.h"
#include <QtWidgets/QApplication>


#include <String>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtVisualLoader1 w;

    qInfo() << argv[1];
    qInfo() << argv[2];
    qInfo() << argv[3];

    w.receivArgvector(argv[1], argv[2], argv[3]); 
    w.show();

    QString agrs1 = argv[1];
    QString agrs2 = argv[2];
    QString agrs3 = argv[2];

    //w.receivArgvector(argv[1], argv[2], argv[3]);


    return a.exec();
}
