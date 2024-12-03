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

#define N_PROCESS_ADAMS 1
#define N_PROCESS_UGII 2
#define N_PROCESS_ANSYS 3
#define N_PROCESS_ADAMS 0


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
		int parseIniFile();

	};





};
QString searchEnvir(QString envirKey);
bool fileExists(const QString& fileName);

