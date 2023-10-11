module;
#include "main.h"
import constants;
export module eqp_lines;

export bool eqp(std::string const&file_name, std::vector<Star> vec_star, double a, double x_range[2], double y_range[2], int x_steps, int y_steps);
std::vector<double> center_of_mass(std::vector<Star> vec_star, double a);
std::vector<double> func_S(double x, double y, std::vector<double> r);

export bool eqp(std::string const&file_name, std::vector<Star> vec_star, double a, double x_range[2], double y_range[2], int x_steps, int y_steps){
    std::ofstream Myfile(file_name);
    std::vector<double> p;
    std::vector<double> S;
    double x_pos;
    double y_pos;

    double dx = std::abs(x_range[0]-x_range[1])/x_steps;
    double dy = std::abs(y_range[0]-y_range[1])/y_steps;
    double A = -1.0/2.0 * (const_G.astro * (vec_star[0].mass + vec_star[1].mass))/pow(a,3.0);

    p = center_of_mass(vec_star, a);

    if(!Myfile.is_open()){
        std::cout << "Failed to Open File\n";
        return false;
    }

    std::cout << const_G.astro << std::endl;

    for(int i = 0; i <= x_steps; i++){
        x_pos = x_range[0] + i*dx;
        for(int j = 0; j <= y_steps; j++){
            y_pos = y_range[0] + j*dy;
            S = func_S(x_pos, y_pos, p);
            Myfile << x_pos <<  " " << y_pos << " " << -const_G.astro*(vec_star[0].mass) << std::endl;
        }
    }

    return true;
}

std::vector<double> center_of_mass(std::vector<Star> vec_star, double a){
    std::vector<double> position;
    position.push_back(pow((1-vec_star[0].mass/vec_star[1].mass),-1.0)*a);
    position.push_back(a - position[0]);
    return position;
}

std::vector<double> func_S(double x, double y, std::vector<double> r){
    std::vector<double> S;
    double h = sqrt(pow(x,2.0)+pow(y,2.0));
    S.push_back(pow(r[0],2.0)+pow(h,2)+2*r[0]*x);
    S.push_back(pow(r[1],2.0)+pow(h,2)-2*r[1]*x);
    return S;
}