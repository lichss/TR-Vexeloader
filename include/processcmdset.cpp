#include "processcmdset.h"

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

/*
 用json指定 可执行文件的路径 启动参数
 如果需要保存，也直接保存在json文件中
 设想是为七个需要启动的文件各自创建一个此类  ProcessCmdset类 
 各自记录


*/
