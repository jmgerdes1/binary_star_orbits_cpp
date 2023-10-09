#include "main.h"
import parse;
import eqp_lines;
int main(){
    parse_run("config_files/solarsystem.config");
    std::cout << vec_star[0].mass << std::endl;
    eqp("data/solarsystem.dat", vec_star);
}