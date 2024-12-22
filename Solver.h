#ifndef SOLVER_H
#define SOLVER_H

#endif // SOLVER_H
#pragma once
#include<vector>
#include<cmath>


class Solver
{
private:
    bool is_inf{ false };
    double a;
    double b;
    double step;
    double control = 0.0000001;
    double pogran_control = 0.0000001;

    double start_v1{ 7.0 };
    double start_v2{ 13.0 };

    double maximum_e1{ 0.0 };
    double maximum_e2{ 0.0 };
    double minimum_e1{ 0.0 };
    double minimum_e2{ 0.0 };
    double max_e1_x{ 0.0 };
    double max_e2_x{ 0.0 };
    double min_e1_x{ 0.0 };
    double min_e2_x{ 0.0 };

    int solve_type{ -1 };

    int step_count{0};
    int steps_before_pg{0};
    int steps_after_pg{0};

    std::vector<std::vector<double>> numerical_results;
    std::vector<std::vector<double>> true_results;
    std::vector<std::vector<double>> exponents;
    std::vector<std::vector<double>> table;

    std::vector<double> func(const std::vector<double>& v);
    std::vector<double> true_solution(const double x);

    void make_RK2_step(double& x, std::vector<double>& v, const double& step);
    bool control_step(double& x, std::vector<double>& v, std::vector<double>& old_v, double& step);


public:
    Solver(const double left_border, const double right_border, const double _step);
    void SolveSystem();
    void FindTrueSolution();
    void FindDistances();

    double get_max_e1() {
        return maximum_e1;
    };
    double get_max_e2() {
        return maximum_e2;
    }
    double get_min_e1() {
        return minimum_e1;
    }
    double get_min_e2() {
        return minimum_e2;
    };
    double get_max_e1_x() {
        return max_e1_x;
    };
    double get_max_e2_x() {
        return max_e2_x;
    }
    double get_min_e1_x() {
        return min_e1_x;
    };
    double get_min_e2_x() {
        return min_e2_x;
    }
    int get_steps_before_pg(){
        return steps_before_pg;
    }
    int get_steps_after_pg(){
        return steps_after_pg;
    }
    int get_step_count(){
        return step_count;
    }

    const std::vector<std::vector<double>>& get_num_results() const{
        return numerical_results;
    }
    const std::vector<std::vector<double>>& get_true_results() const {
        return true_results;
    }
    std::vector<std::vector<double>>& get_table();

    void solve_type_choise(int type);
};

