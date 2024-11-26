#include "QtVisualLoader1.h"
#include "processcmdset.h"

QtVisualLoader1::QtVisualLoader1(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    connect(ui.pushButton, &QPushButton::pressed, this, &QtVisualLoader1::button0Pressed);
    connect(ui.adams_radioButton,&QRadioButton::clicked,this,&QtVisualLoader1::adamsRadioButton);
    connect(ui.ug_radioButton,&QRadioButton::clicked,this,&QtVisualLoader1::UG6RadioButton);
    connect(ui.ansys_radioButton,&QRadioButton::clicked,this,&QtVisualLoader1::ansysRadioButton);



}

QtVisualLoader1::~QtVisualLoader1()
{}


int QtVisualLoader1::adamsRadioButton() {

    qInfo() << "adams radio button.";
    PROCESSL::ProcessCmdset pcmd;
    pcmd.readJson("cmdset.json",this->filePath,this->argList,0);

    qInfo() <<"now file path:" << this->filePath;
    /*index 0 = adams*/
    return 0;

}

int QtVisualLoader1::UG6RadioButton() {

    qInfo() << "Ug radio button.";

    PROCESSL::ProcessCmdset pcmd;
    pcmd.readJson("cmdset.json",this->filePath,this->argList,1);

    qInfo() <<"now file path:" << this->filePath;

    /*index 1 = UG*/

    return 0;

}

int QtVisualLoader1::ansysRadioButton() {

    qInfo() << "ansys radio button.";
    PROCESSL::ProcessCmdset pcmd;
    pcmd.readJson("cmdset.json",this->filePath,this->argList,2);

    qInfo() <<"now file path:" << this->filePath;

    /*index 2 = ansys*/
    return 0;

}



int QtVisualLoader1::receivArgvector(QString iargv1,QString iargv2,QString iargv3) {
    int recN=0;
//    qInfo() << "\n***************\nenter recev f\n";

    if (!iargv1.isEmpty()) {
        this->argv1 = iargv1;
        recN++;
    }
    if (!iargv2.isEmpty()) {
        this->argv2 = iargv2;
        recN++;
    }
    if (!iargv3.isEmpty()) {
        this->argv3 = iargv3;
        recN++;
    }

    return recN;
}

int QtVisualLoader1::receivArgvector(QStringList argv)
{
    this->argList = argv;
    return 0;
}

int QtVisualLoader1::button0Pressed() {

    /*
    ui.label->setText(argv1);
    ui.label_2->setText(argv2);
    ui.label_3->setText(argv3);
    */

    ui.label->setText(this->filePath);
    ui.label_2->setText(argList[0]);
    ui.label_3->setText(argList[1]);
    ui.label_4->setText(argList[2]);
    
    starProcess(this->filePath,this->argList);
    return 0;
}

int QtVisualLoader1::starProcess(QString filePath, QStringList argList) {

	QProcess process;


    process.start(filePath ,argList);
    	// 等待程序启动
    if (!process.waitForStarted()) {
		qInfo() << "Failed to start the process.";

        return -1;
    }

    // 如果需要等待程序结束，可以使用 waitForFinished()
    if (!process.waitForFinished()) {
        qInfo() << "Process failed to finish.";
        return -1;
    }



    return 0;
}

/*

D:\MSCSoftware\Adams\2018\common\mdi.bat aview ru-st i
*/
