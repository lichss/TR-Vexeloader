#include "QtVisualLoader1.h"
#include <QtWidgets/QApplication>


//#include <String>


#include "processcmdset.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtVisualLoader1 w;

    PROCESSL::ProcessCmdset pcmd;
    QString filepath;
    QStringList arglist;
    //pcmd.readJson("./cmdset.json",filepath,arglist,2);

    //qInfo() << filepath;
    //qInfo() << arglist[0] << arglist[1];

    
    qInfo() << argv[1];
    qInfo() << argv[2];
    qInfo() << argv[3];

    QStringList qss = {
        argv[0],
        argv[1],
        argv[2],
        argv[3],
    
    };

    w.receivArgvector(argv[1], argv[2], argv[3]); 
    w.receivArgvector(qss);
    w.show();

    QString agrs1 = argv[1];
    QString agrs2 = argv[2];
    QString agrs3 = argv[2];

    //w.receivArgvector(argv[1], argv[2], argv[3]);

    w.starProcess(filepath,arglist);
    return a.exec();
}
