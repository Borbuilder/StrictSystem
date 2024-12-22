#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLineEdit>
#include <QMessageBox>
#include <QTableWidget>
#include <QStringList>
#include <QVector>
#include <QCheckBox>



#include "Solver.h"
#include "qcustomplot.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(10);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<< "x" << "v1" << "v2" << "u1" << "u2"<< "E1" << "E2" << "e^(-0.01*x)" << "e^(-1000*x)"<< "Шаг");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fill_table(){
    ui->tableWidget->setRowCount(table.size());

    for(size_t raw = 0;raw < ui->tableWidget->rowCount();++raw){
        for(size_t col = 0;col < ui->tableWidget->columnCount();++col){
            QTableWidgetItem *tbl = new QTableWidgetItem(QString::number(table[raw][col]));
            ui->tableWidget->setItem(raw,col,tbl);
        }
    }
}

void MainWindow::plot_num(const std::vector<std::vector<double>>& points){
    QVector<double> x(points.size());
    QVector<double> f1(points.size());
    QVector<double> f2(points.size());

    for(size_t i = 0; i<points.size(); ++i){
        x[i] = points[i][0];
        f1[i] = points[i][1];
        f2[i] = points[i][2];
    }

    ui->widget->clearGraphs();

    ui->widget->xAxis->setRange(*x.begin(), *(--x.end()));
    ui->widget->yAxis->setRange(6.5,14.5);

    ui->widget->addGraph();
    ui->widget->addGraph();
    ui->widget->graph(0)->setPen(QPen(Qt::red));
    ui->widget->graph(0)->addData(x,f1);
    ui->widget->graph(1)->addData(x,f2);
    ui->widget->replot();

    ui->widget->setInteraction(QCP::iRangeZoom,true);
    ui->widget->setInteraction(QCP::iRangeDrag,true);
}

void MainWindow::plot_true(const std::vector<std::vector<double>>& points){

    QVector<double> x(points.size());
    QVector<double> f1(points.size());
    QVector<double> f2(points.size());

    for(size_t i = 0; i<points.size(); ++i){
        x[i] = points[i][0];
        f1[i] = points[i][1];
        f2[i] = points[i][2];
    }

    ui->widget_2->clearGraphs();

    ui->widget_2->xAxis->setRange(*x.begin(), *(--x.end()));
    ui->widget_2->yAxis->setRange(6.5,14.5);

    ui->widget_2->addGraph();
    ui->widget_2->addGraph();
    ui->widget_2->graph(0)->setPen(QPen(Qt::red));
    ui->widget_2->graph(0)->addData(x,f1);
    ui->widget_2->graph(1)->addData(x,f2);
    ui->widget_2->replot();

    ui->widget_2->setInteraction(QCP::iRangeZoom,true);
    ui->widget_2->setInteraction(QCP::iRangeDrag,true);
}


void MainWindow::on_pushButton_clicked()
{
    QString text1 = ui->lineEdit->text();
    a = text1.toDouble();
    QString text2 = ui->lineEdit_2->text();
    b = text2.toDouble();
    QString text3 = ui->lineEdit_3->text();
    step = text3.toDouble();


    if(ui->checkBox->isChecked()){
        solve_type = 1;
    }
    if(ui->checkBox_2->isChecked()){
        solve_type = 0;
    }

    if(step>0.000001){
       QMessageBox::critical(this,"Предупреждение","При таком шаге погрешность > 10^-7 \n Чтобы получить погрешность <= 10^-7 уменьшите шаг минимум до 0.000001");
    }

    on_pushButton_is_clicked = true;

    if(step<=0){
        good_step = false;
    }
    else{
        good_step = true;
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    if(on_pushButton_is_clicked){
        if(solve_type==-1){
            QMessageBox::critical(this,"Предупреждение","Выбирите вариант решения");
        }
        else if(solve_type==-1 && step>=0.002){
            QMessageBox::critical(this,"Предупреждение","При решении с контролем шаг должен быть < 0.002");
        }
        else if(good_step == false){
            QMessageBox::critical(this,"Предупреждение","Введите шаг > 0");
        }
        else{
            Solver solution(a,b,step);
            solution.solve_type_choise(solve_type);
            //solution.FindTrueSolution();
            solution.SolveSystem();

            auto true_solution = solution.get_true_results();
            auto num_solution = solution.get_num_results();
            if(!table.empty()){
                table.clear();
            }
            table = solution.get_table();

            fill_table();
            plot_true(true_solution);
            plot_num(num_solution);

            solution.FindDistances();
            ui->lineEdit_4->setText(QString::number(table[0][1]));
            ui->lineEdit_5->setText(QString::number(table[0][2]));
            ui->lineEdit_6->setText(QString::number(table[table.size()-1][1]));
            ui->lineEdit_7->setText(QString::number(table[table.size()-1][2]));
            ui->lineEdit_8->setText(QString::number(solution.get_max_e1()));
            ui->lineEdit_9->setText(QString::number(solution.get_max_e2()));
            ui->lineEdit_10->setText(QString::number(solution.get_min_e1()));
            ui->lineEdit_11->setText(QString::number(solution.get_min_e2()));
            ui->lineEdit_12->setText(QString::number(solution.get_step_count()+1));
            ui->lineEdit_13->setText(QString::number(solution.get_max_e1_x()));
            ui->lineEdit_14->setText(QString::number(solution.get_max_e2_x()));
            ui->lineEdit_15->setText(QString::number(solution.get_min_e1_x()));
            ui->lineEdit_16->setText(QString::number(solution.get_min_e2_x()));
            ui->lineEdit_17->setText(QString::number(solution.get_steps_before_pg()));
            ui->lineEdit_18->setText(QString::number(solution.get_steps_after_pg()+1));
        }
    }
    else{
        QMessageBox::critical(this,"Предупреждение","Введите значения");
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    QVector<double> x(table.size());
    QVector<double> e1(table.size());
    QVector<double> e2(table.size());

    for(size_t i = 0; i<table.size(); ++i){
        x[i] = table[i][0];
        e1[i] = -table[i][5];
        e2[i] = table[i][6];
    }

    error_graph.plot_error(x,e1,e2);
    error_graph.show();
}

