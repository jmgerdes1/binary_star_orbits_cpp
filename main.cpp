#include "main.h"
import parse;
import eqp_lines;
int main(){
    std::cout << "Running parser: \n";
    parse_run("config_files/solarsystem.config");
    std::cout << "      Done\n";
//  std::cout << vec_star[0].mass << std::endl;
//  std::cout << a << std::endl;
    std::cout << "Running gravitational potential calculation: \n";
    eqp("data/solarsystem.dat", vec_star, a, x_range, y_range, x_steps, y_steps);
    std::cout << "      Done\n";
}