#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(this, SIGNAL(sendDoOcr(QString,QString)),
            &m_worker, SLOT(recvDoWork(QString,QString)));
    connect(&m_worker, SIGNAL(sendResultReady(int)),
            this, SLOT(recvOrcResult(int)));
}

Widget::~Widget()
{
    m_workerThread.quit();
    m_workerThread.wait();
    delete ui;
}

void Widget::on_pushButton_start_clicked()
{
    QString inputPicPath = ui->lineEdit_inputPic->text();
    QString outputTxtPath = ui->lineEdit_OutputTxt->text();
    m_workerThread.start();
    emit sendDoOcr(inputPicPath, outputTxtPath);
}

void Widget::on_pushButton_BroserPic_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("打开图片"), "", tr("Image Files (*.png *.jpg *.bmp)"));
    ui->lineEdit_inputPic->setText(fileName);
    //将后缀换为txt后填充到文本文件路径上
    ui->lineEdit_OutputTxt->setText(fileName.remove(fileName.size() - 4, 4) + ".txt");
}

void Widget::on_pushButton_BroserTxt_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("打开文本文件"), "", tr("Text Files (*.txt)"));
    ui->lineEdit_OutputTxt->setText(fileName);
}

void Widget::recvOrcResult(int ret)
{
    if (ret == OcrWorker::OK)
    {
        QMessageBox::information(this, "通知", "文字识别完成");
    }
    else if (ret == OcrWorker::FILE_NOT_EXIST)
    {
        QMessageBox::warning(this, "错误", "输入文件或输出文件不存在");
    }
    else
    {
        QMessageBox::warning(this, "错误", "未知错误");
    }
}
