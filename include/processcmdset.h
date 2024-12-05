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
#include <QMessagebox>

#define ADAMS_ENVIR_KEY	"ADAMS_LAUNCH_PATH"
#define UGS_ENVIR_KEY	"UGS_LAUNCH_PATH"
#define ANSYS_ENVIR_KEY "ANSYS_LAUNCH_PATH"

#define ADAMS_PROCESS_MODE	"Adams"
#define UGS_PROCESS_MODE	"UGS"
#define ANSYS_PROCESS_MODE	"Ansys"


namespace PROCESSL {

	class ProcessCmdset {
	public:
		QString processMode = "Adams";
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
		QString searchEnvir();

	};





};
bool fileExists(const QString& fileName);
bool showWarnningBox();

