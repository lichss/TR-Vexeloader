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
       
    PROCESSL::ProcessCmdset p;
    
    if (gui_mode == QString("-gui")) {
        w.show();

        
        w.starProcess(filepath, arglist);
        return a.exec();
    }
    else {
        
        if (fileExists("config.ini")) {
            //能找到ini文件
            p.parseIniFile();

            //QMessageBox::warning(nullptr, "Alert", "No No init file  fond.");
        }
        else
           QMessageBox::warning(nullptr, "Alert", "No ini file  fond.");
        
		QString envirKey = p.searchEnvir();
		
       
        p.startProcess();

		//QMessageBox::warning(nullptr, "Alert", "No-----------.");
        return 0;
    }
}


