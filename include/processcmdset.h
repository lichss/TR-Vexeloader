#pragma once
#include <QStringlist>
#include <QString>

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QDebug>

namespace PROCESSL {

	class ProcessCmdset {
	public:
		QString executebleFilePath;
		QStringList argList;
		
	public:


		ProcessCmdset();
		~ProcessCmdset();

		int readJson(const QString fileName,QString& rfilepath,QStringList& rlist,int index);
	};



};
