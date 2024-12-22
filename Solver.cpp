#include "Solver.h"
#include<iostream>

bool is_infin(const std::vector<double>& V) {
    bool flag{false};
    if (std::isinf(V[0]) || std::isnan(V[0])) flag = true;
    if (std::isinf(V[1]) || std::isnan(V[1])) flag = true;
    return flag;
}

std::vector<double> Solver::func(const std::vector<double>& v)
{
	double du1_dx = -500.005 * v[0] + 499.995 * v[1];
	double du2_dx = 499.995 * v[0] - 500.005 * v[1];

	std::vector<double> function{ du1_dx,du2_dx };
	return function;
}

std::vector<double> Solver::true_solution(const double x)
{
	std::vector<double> u(2);
	u[0] = 10 * std::exp(-0.01 * x) - 3 * std::exp(-1000 * x);
	u[1] = 10 * std::exp(-0.01 * x) + 3 * std::exp(-1000 * x);
	return u;
}

void Solver::make_RK2_step(double& x, std::vector<double>& v, const double& step)
{
	std::vector<double> f0 = func(v);
	std::vector<double> f = func({ v[0] + (step/2.0) * f0[0], v[1] + (step/2.0) * f0[1] });

	v[0] += step * f[0];
	v[1] += step * f[1];

	x += step;
}

bool Solver::control_step(double& x, std::vector<double>& v,  std::vector<double>& old_v, double& step)
{
	if (exp(-1000 * x) < pogran_control) {
		double old_x = x - step;

		double half_x = old_x;
		std::vector<double> half_v = old_v;
		double half_step = step / 2.0;

		make_RK2_step(half_x, half_v, half_step);
		make_RK2_step(half_x, half_v, half_step);

		double s_1 = abs((half_v[0] - v[0])) / (pow(2.0, 2.0) - 1.0);
		double s_2 = abs((half_v[1] - v[1])) / (pow(2.0, 2.0) - 1.0);
		double s = sqrt(s_1 * s_1 + s_2 * s_2);

		//2^p+1 = 2^(2+1) = 2^3 = 8
		if (control / 8.0 <= s && s <= control) {
			return false;
		}
		else if (s < control / 8.0) {
			step *= 2.0;
			return false;
		}
		else if (s > control) {
			x = old_x;
			v = old_v;
			step /= 2.0;
			return true;
		}
	}
    return false;
}



Solver::Solver(const double left_border, const double right_border, const double _step)
{
	a = left_border;
	b = right_border;
	step = _step;
}


void Solver::SolveSystem()
{
	double x = a;
	std::vector<double> v = { start_v1, start_v2 };
	double h = step;
	numerical_results.push_back({ x,v[0],v[1], step });


	std::vector<double> u{ start_v1,start_v2 };
	true_results.push_back({ x,u[0],u[1] });

	exponents.push_back({ 1.0,1.0 });
    int inf_count{0};
    int step_reduce{0};

    while (x < b-0.000000001) {

		if (solve_type == 1) {

            if( exp(-1000 * x) < pogran_control){
                ++step_reduce;

                bool step_is_good{true};

                if(step_reduce==50){
                    h *=10.0;
                }
                else if(step_reduce==200){
                    h *=10.0;
                }
                else if(step_reduce==300){
                    h *=10.0;
                }

                if(h>=0.00199){
                    step_is_good = false;
                }

                if(step_reduce>300 || step_is_good==false){
                    h = 0.00199;
                }

                make_RK2_step(x, v, h);
                ++steps_after_pg;
            }
            else{
                //std::vector<double> old_v(v);
                //bool step_is_not_ok{ true };

               // while(step_is_not_ok){
                    make_RK2_step(x, v, h);
                   // step_is_not_ok = control_step(x, v, old_v, h);
               // }
                ++steps_before_pg;
            }

		}
		else if(solve_type == 0){
			make_RK2_step(x, v, h);
		}
		u = true_solution(x);

		true_results.push_back({ x,u[0],u[1] });
		exponents.push_back({ std::exp(-0.01 * x), std::exp(-1000 * x) });
		numerical_results.push_back({ x,v[0],v[1],h });

        ++step_count;
        if(is_infin(v)){
            ++inf_count;
            if(inf_count>3)
                break;
        }
	}

}

//void Solver::SolveSystem()
//{
//	double x = a;
//	std::vector<double> v = { start_v1, start_v2 };
//	double h = step;
//	numerical_results.push_back({ x,v[0],v[1] });
//
//	while (x <= b) {
//		std::vector<double> old_v(v);
//
//		bool step_is_not_ok{true};
//		while (step_is_not_ok) {
//			make_RK2_step(x, v, h);
//			step_is_not_ok = control_step(x,v, old_v, h);
//		}
//		numerical_results.push_back({ x,v[0],v[1] });
//	}
//
//}

void Solver::FindTrueSolution()
{
	double x = a;
	double h = step;
	std::vector<double> u{ start_v1,start_v2 };

	true_results.push_back({ x,u[0],u[1] });
	exponents.push_back({ 1.0,1.0 });

    while (x < b) {
		x += h;
		u = true_solution(x);

		true_results.push_back({ x,u[0],u[1] });
		exponents.push_back({ std::exp(-0.01 * x), std::exp(-1000 * x) });
	}

	
}

void Solver::FindDistances()
{
	int size = numerical_results.size();
	double max_e1{ -1.0 };
	double max_e2{ -1.0 };
	double min_e1{ 10000000.0 };
	double min_e2{ 10000000.0 };

	if (true_results.size() != size ) {
		std::cout << "bad sizes";
		table.push_back({ {-1.0} });
	}
	else {
		for (size_t i = 1; i < size; ++i) {

			if (fabs(numerical_results[i][1] - true_results[i][1]) > max_e1) {
				max_e1 = fabs(numerical_results[i][1] - true_results[i][1]);
				max_e1_x = numerical_results[i][0];
			}

			if (fabs(numerical_results[i][2] - true_results[i][2]) > max_e2) {
				max_e2 = fabs(numerical_results[i][2] - true_results[i][2]);
				max_e2_x = numerical_results[i][0];
			}

			if (fabs(numerical_results[i][1] - true_results[i][1]) < min_e1) {
				min_e1 = fabs(numerical_results[i][1] - true_results[i][1]);
				min_e1_x = numerical_results[i][0];
			}

			if (fabs(numerical_results[i][2] - true_results[i][2]) < min_e2) {
				min_e2 = fabs(numerical_results[i][2] - true_results[i][2]);
				min_e2_x = numerical_results[i][0];
			}
		}
	}

	maximum_e1 = max_e1;
	maximum_e2 = max_e2;
	minimum_e1 = min_e1;
	minimum_e2 = min_e2;
}

std::vector<std::vector<double>>& Solver::get_table()
{
	int size = numerical_results.size();
	if (true_results.size() != size || exponents.size() != size) {
		std::cout << "bad sizes";
		table.push_back({{-1.0}});
	}
	else {
		for (size_t i = 0; i < size; ++i) {
			std::vector<double> line(10);
			line[0] = numerical_results[i][0];
			line[1] = numerical_results[i][1];
			line[2] = numerical_results[i][2];
			line[3] = true_results[i][1];
			line[4] = true_results[i][2];
            line[5] = fabs(numerical_results[i][1] - true_results[i][1]);
            line[6] = fabs(numerical_results[i][2] - true_results[i][2]);
			line[7] = exponents[i][0];
			line[8] = exponents[i][1];
            if(i==0){
                line[9] = 0.0;
            }
            else{
                line[9] = numerical_results[i][3];
            }
			table.push_back(line);
		}
	}
	return table;
}

void Solver::solve_type_choise(int type)
{
	if (type == 1 || type == 0) {
		solve_type = type;
	}
	else {
		std::cout<<"wrong solve type";
	}
}


