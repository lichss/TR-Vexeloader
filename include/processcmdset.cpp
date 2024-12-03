#include "processcmdset.h"
#include <QDir>
PROCESSL::ProcessCmdset::ProcessCmdset()
{
}

PROCESSL::ProcessCmdset::~ProcessCmdset()
{
}

int PROCESSL::ProcessCmdset::readJson(const QString fileName,QString& rfilepath,QStringList& rlist,int index)
{


	QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qInfo() << "Cannot open file:" << fileName;
        return -1;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    if (jsonDoc.isNull()) {
        qInfo() << "Invalid JSON document";
        return -2;
    }

    if (!jsonDoc.isObject()) {
        qInfo() << "JSON document is not an object";
        return -3;
    }
      
    QJsonObject jsonObject = jsonDoc.object();
    QJsonArray collections = jsonObject.value("collections").toArray();

    rfilepath.clear();
    rlist.clear();

    QJsonObject selectedCollection = collections[index].toObject();
    rfilepath = selectedCollection.value("filepath").toString();
    QJsonArray argArray = selectedCollection.value("argument").toArray();

    for (const QJsonValue& arg : argArray) {
        rlist.append(arg.toString());
    }

    /*
    for (const QJsonValue &value : collections) {
        if (value.isObject()) {
            QJsonObject collection = value.toObject();
            QString filepath= collection.value("filepath").toString();
            QJsonArray items = collection.value("items").toArray();

            qInfo() << "FilePath:" << filepath;
            qInfo() << "Items:";
            for (const QJsonValue &item : items) {
                qInfo() << "  -" << item.toString();
            }
        }
    }
    */

    qInfo() << "open file well.\n";

	return 0;
}

int PROCESSL::ProcessCmdset:: record(int index,QString& rfilepath,QStringList& rlist) {

    if (index > 3 || index < 0)
        return -1;

    rfilepath.clear();
    rlist.clear();

    switch (index)
    {
        case 0:
            rfilepath = "D:\\MSCSoftware\\Adams\\2018\\common\\mdi.bat";
            rlist.append("aview");
            rlist.append("ru-st");
            rlist.append("i");
            break;
        
        case 1: 
            rfilepath = "D:\\Program Files\\UGS\\NX 6.0\\UGII\\ugraf.exe";
            break;

        case 3: 
            rfilepath = "D:\\Program Files\\ANSYS Inc\\v182\\Framework\\bin\\Win64\\runwb2.exe";
            break;

        default:
            break;
    }



    return 0;
}

int PROCESSL::ProcessCmdset:: record(int index) {

    if (index > 3 || index < 0)
        return -1;

    this->executebleFilePath.clear();
    this->argList.clear();

    QString rfilepath;
    QStringList rlist;
    switch (index)
    {
        case 1:
            rfilepath = "D:\\MSCSoftware\\Adams\\2018\\common\\mdi.bat";
            rlist.append("aview");
            rlist.append("ru-st");
            rlist.append("i");
            break;
        
        case 2: 
            rfilepath = "D:\\Program Files\\UGS\\NX 6.0\\UGII\\ugraf.exe";
            break;

        case 3: 
            rfilepath = "D:\\Program Files\\ANSYS Inc\\v182\\Framework\\bin\\Win64\\runwb2.exe";
            break;

        default:
            break;
    }

    this->executebleFilePath = rfilepath;
    this->argList = rlist;
        
    return 0;
}


int PROCESSL::ProcessCmdset::startProcess(QString filePath, QStringList argList) {

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


int PROCESSL::ProcessCmdset::startProcess() {

	QProcess process;


    process.start(this->executebleFilePath ,this->argList);
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

QString searchEnvir(QString envirKey) {
	QString value;
	QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
	if (!env.contains(envirKey)) {
		//   qInfo() << "妹找到啊，你根本就不在沈阳，你在哪呢？\n not find.w";
		return "";
	}

	//qInfo() << "有环境变量:\nfind env.as:\n" << env.value("UGS_ROUTER_PATH");
	return env.value(envirKey);


	return 0;
}

int PROCESSL::ProcessCmdset::parseIniFile() {
    QString configFilePath = "config.ini"; 

    // 使用QSettings加载INI文件
    QSettings settings(configFilePath, QSettings::IniFormat);

    // 读取Application部分的信息
    QString appName = settings.value("Application/Name").toString();
    QString appPath = settings.value("Application/Path").toString();
    QString appArgStr = settings.value("Application/Arguments").toString();

    QStringList appArgs = appArgStr.split(" ", Qt::SkipEmptyParts);
    //appPath = QDir::toNativeSeparators(appPath);

    // 输出读取到的信息
    qDebug() << "Application Name:" << appName;
    qDebug() << "Application Path:" << appPath ;
    qDebug() << "Application Arguments:" << appArgs;

    executebleFilePath = appPath;
    argList = appArgs;

    return 0;
}

bool fileExists(const QString &fileName)
{
    QDir currentDir = QDir::current();

    QFileInfo fileInfo(currentDir, fileName);

    // 返回文件是否存在
    return fileInfo.exists() && fileInfo.isFile();
}
