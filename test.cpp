#include "main.h"
import parse;
int main(){
  parse_run("solarsystem.config");
  std::cout << "Parser Output Star 1: " << vec_star[0].mass << std::endl;
  std::cout << "Parser Output Star 1: " << vec_star[1].mass << std::endl;
  std::cout << "Parser Output Planet 1: " << vec_planet[0].mass << std::endl;
}