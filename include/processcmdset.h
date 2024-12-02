#pragma once
#include <QStringlist>
#include <QString>

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QDebug>
#include <QProcess>
#include <QSettings>
#include <QProcessEnvironment>

namespace PROCESSL {

	class ProcessCmdset {
	public:
		QString executebleFilePath;
		QStringList argList;
		
	public:


		ProcessCmdset();
		~ProcessCmdset();

		int readJson(const QString fileName,QString& rfilepath,QStringList& rlist,int index);
		int record(int index, QString& rfilepath, QStringList& rlist);
		int record(int index);

		int startProcess(QString filePath, QStringList argList);
		int startProcess();
	};





};
QString searchEnvir(QString envirKey);

