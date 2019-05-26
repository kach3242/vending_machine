#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QString>



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

void Widget::ChangMoney(int diff){
    money += diff;
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbCola->setEnabled(false);
    if(money>=100){
        ui->pbCoffee->setEnabled(true);
        if(money>=150){
            ui->pbTea->setEnabled(true);
            if(money>=200){
                ui->pbCola->setEnabled(true);
            }
        }
    }
    ui->lcdNumber->display(money);
}

void Widget::on_pb10_clicked()
{
    ChangMoney(10);
}

void Widget::on_pb50_clicked()
{
    ChangMoney(50);
}

void Widget::on_pb100_clicked()
{
    ChangMoney(100);
}

void Widget::on_pb500_clicked()
{
    ChangMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    ChangMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    ChangMoney(-150);
}

void Widget::on_pbCola_clicked()
{
    ChangMoney(-200);
}

void Widget::on_pbChange_clicked()
{
    int c_500 = money/500;
    int c_100 = (money - c_500*500)/100;
    int c_50 = (money - c_500*500 - c_100*100)/50;
    int c_10 = (money - c_500*500 - c_100*100 - c_50*50)/10;
    ChangMoney(-money);
    QMessageBox::warning(this,"title",QString("Change Money\n500  :  %1\n100  :  %2\n50    :  %3\n10    :  %4").arg(c_500).arg(c_100).arg(c_50).arg(c_10));
}
