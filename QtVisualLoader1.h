#pragma once

#include <QtWidgets/QWidget>
#include <QDebug>
#include <QString>
#include <QProcess>
#include <QDebug>
#include <QPushbutton>
#include <QSettings>
#include <QFiledialog>
#include <QVector>
#include <QList>
#include <QProcessEnvironment>
#include <QMessageBox>
#include "ui_QtVisualLoader1.h"
#include <qstringlist.h>

class QtVisualLoader1 : public QWidget
{
    Q_OBJECT

public:
    QtVisualLoader1(QWidget *parent = nullptr);
    ~QtVisualLoader1();

    QString filePath;
    

    QString argv1;
    QString argv2;
    QString argv3;
    QString argv4;
    QStringList argList;

    int adamsRadioButton();

    int UG6RadioButton();

    int ansysRadioButton();

    int receivArgvector(QString argv1, QString argv2, QString argv3);
    int receivArgvector(QStringList argv);

    int starProcess(QString filePath, QStringList argList);

private slots:
    int button0Pressed();

 

private:

    Ui::QtVisualLoader1Class ui;
};
