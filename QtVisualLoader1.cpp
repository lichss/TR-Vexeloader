#include "QtVisualLoader1.h"

QtVisualLoader1::QtVisualLoader1(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    connect(ui.pushButton, &QPushButton::pressed, this, &QtVisualLoader1::button0Pressed);
}

QtVisualLoader1::~QtVisualLoader1()
{}


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

    return 0;
}

int QtVisualLoader1::button0Pressed() {

    ui.label->setText(argv1);
    ui.label_2->setText(argv2);
    ui.label_3->setText(argv3);

    return 0;
}
