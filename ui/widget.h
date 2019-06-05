#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

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

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H