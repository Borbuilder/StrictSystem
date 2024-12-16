#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "errorgraph.h"
#include "Solver.h"
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void fill_table();

    void plot(const std::vector<std::vector<double>>& true_sol,const std::vector<std::vector<double>>& num_sol);
    void plot_num(const std::vector<std::vector<double>>& points);
    void plot_true(const std::vector<std::vector<double>>& points);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    double a;
    double b;
    double step;
    int solve_type{-1};
    ErrorGraph error_graph;
    std::vector<std::vector<double>> table;

    bool on_pushButton_is_clicked{false};
    bool good_step{true};
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
