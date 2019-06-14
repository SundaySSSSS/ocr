#ifndef OCRWORKER_H
#define OCRWORKER_H

#include <QObject>

class OcrWorker : public QObject
{
    Q_OBJECT
public:
    typedef enum _Result
    {
        OK = 0,
        FILE_NOT_EXIST, //输入或输出文件不存在
    }
    Result;

    explicit OcrWorker(QObject *parent = 0);

signals:
    //工作完成
    void sendResultReady(int ret);

public slots:
    //工作槽函数
    void recvDoWork(QString inputPicPath, QString outputTxtPath);
};

#endif // OCRWORKER_H
