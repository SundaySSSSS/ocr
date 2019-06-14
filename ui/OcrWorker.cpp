#include "OcrWorker.h"
#include <QProcess>

OcrWorker::OcrWorker(QObject *parent) : QObject(parent)
{

}

void OcrWorker::recvDoWork(QString inputPicPath, QString outputTxtPath)
{
    if (inputPicPath == "" || outputTxtPath == "")
    {
        emit sendResultReady(FILE_NOT_EXIST);
        return;
    }

    QString program = "AipOcr.exe";
    QStringList arguments;
    arguments << inputPicPath << outputTxtPath;

    QProcess p(this);
    p.start(program, arguments);
//    p.waitForStarted();
//    QByteArray output = p.readAllStandardOutput();
    p.waitForFinished();
    emit sendResultReady(OK);
}

