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
    


    int gui=0;
    QString gui_mode(argv[1]);
    if (gui_mode == QString("-gui")) {

        QMessageBox::warning(nullptr, "Alert", "GUI mode.");
        
    }
        //return 0;
   
    //qInfo()<<"argv 1" << argv[1];
    //qInfo()<<"argv 2" << argv[2];

    //QStringList qss = {
    //    argv[0],
    //    argv[1],
    //    argv[2],
    //
    //};

    
    if (gui_mode == QString("-gui")) {
        w.show();

        
        w.starProcess(filepath, arglist);
        return a.exec();
    }
    else {
        QString envirKey = 
        searchEnvir("ababa");
        
        if (envirKey.isEmpty()) {
            QMessageBox::warning(nullptr, "Alert", "No environment vairable fond.");
            
        }
        if (fileExists("config.ini")) {
            QMessageBox::warning(nullptr, "Alert", "No NO init file  fond.");

        }
        PROCESSL::ProcessCmdset p;

        p.parseIniFile();
        //p.record(1);
        //p.startProcess();
        return 0;
    }
}


