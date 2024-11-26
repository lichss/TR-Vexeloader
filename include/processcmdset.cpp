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
 ��jsonָ�� ��ִ���ļ���·�� ��������
 �����Ҫ���棬Ҳֱ�ӱ�����json�ļ���
 ������Ϊ�߸���Ҫ�������ļ����Դ���һ������  ProcessCmdset�� 
 ���Լ�¼


*/
