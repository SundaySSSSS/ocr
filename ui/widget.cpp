#include "widget.h"
#include "ui_widget.h"
#include <QProcess>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_start_clicked()
{
    QString inputPicPath = ui->lineEdit_inputPic->text();
    QString outputTxtPath = ui->lineEdit_OutputTxt->text();

    if (inputPicPath == "" || outputTxtPath == "")
    {
        QMessageBox::warning(this, "错误", "输入文件或输出文件不存在");
        return;
    }

    //QString program = "C:/Users/root/Desktop/AipOcr/dist/AipOcr.exe";
    QString program = "AipOcr.exe";
    QStringList arguments;
    arguments << inputPicPath << outputTxtPath;

    QProcess p(this);
    p.start(program, arguments);
//    p.waitForStarted();
//    QByteArray output = p.readAllStandardOutput();
    p.waitForFinished();
    QMessageBox::information(this, "通知", "文字识别完成");
//    qDebug() << output;
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
