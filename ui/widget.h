#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThread>
#include "OcrWorker.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_start_clicked();

    void on_pushButton_BroserPic_clicked();

    void on_pushButton_BroserTxt_clicked();

    //识别完毕槽函数
    void recvOrcResult(int ret);

signals:
    void sendDoOcr(QString inputPicPath, QString outputTxtPath);

private:
    Ui::Widget *ui;
    QThread m_workerThread;
    OcrWorker m_worker;
};

#endif // WIDGET_H
