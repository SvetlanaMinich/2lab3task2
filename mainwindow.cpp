#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(1);
          ui->tableWidget->setColumnCount(5);

          ui->tableWidget_2->setRowCount(2);
             ui->tableWidget_2->setColumnCount(5);


}

MainWindow::~MainWindow()
{
    delete ui;
}


template<class T1,class T2>
struct pair{
    T1 first{};
    T2 second{};
    pair(){};
    pair(T1 const& x,T2 const& y) : first(x), second(y){};
    pair(const pair<T1,T2>& p)
        : first(p.first),second(p.second) {};
    };



void MainWindow::on_showFirst_clicked()
{
    pair< Vector<int>, Vector<pair<int,double>> > a;
        a.first.push_back(15);
        a.first.push_back(22);
        a.first.push_back(34);
        a.first.push_back(47);
        a.first.push_back(51);
            for(int i=0;i<a.first.size();i++){
            QTableWidgetItem *tbl=new QTableWidgetItem(QString::number(a.first[i]));
            ui->tableWidget->setItem(0,i,tbl);
            tbl->setFlags(Qt::ItemIsEditable);
            }

            for(int n : a.first)
              qDebug() << n ;

        a.second.push_back({2,3.09009});
        a.second.push_back({23,33.12345});
        a.second.push_back({42,53.939939});
        a.second.push_back({12,0.001});
        a.second.push_back({54,99.1});

            int s=1;
            for(int i=0;i<a.second.size();i++){
                QTableWidgetItem *tbl1=new QTableWidgetItem(QString::number(a.second[i].first));
                ui->tableWidget_2->setItem(0,i,tbl1);
                s++;
                tbl1->setFlags(Qt::ItemIsEditable);
            }


            for(int i=0;i< a.second.size();i++)
                qDebug() << a.second[i].first ;

            s=1;
            for(int i=0;i<a.second.size();i++){
                QTableWidgetItem *tbl2=new QTableWidgetItem(QString::number(a.second[i].second));
                ui->tableWidget_2->setItem(1,i,tbl2);
                s++;
                tbl2->setFlags(Qt::ItemIsEditable);
            }


            for(int i=0;i< a.second.size();i++)
                qDebug() << a.second[i].second ;
}


void MainWindow::on_clear_clicked()
{
    ui->tableWidget->clear();
    ui->tableWidget_2->clear();
}

