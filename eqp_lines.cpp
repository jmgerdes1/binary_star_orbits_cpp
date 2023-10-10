module;
#include "main.h"
export module eqp_lines;

export bool eqp(std::string const&file_name, std::vector<Star> vec_star, double a);
export std::vector<double> center_of_mass(std::vector<Star> vec_star, double a);

export bool eqp(std::string const&file_name, std::vector<Star> vec_star, double a){
    std::ofstream Myfile(file_name);
    std::vector<double> p;
    p = center_of_mass(vec_star, a);
    std::cout << p[0] << std::endl;
    std::cout << p[1] << std::endl;
    if(!Myfile.is_open()){
        std::cout << "Failed to Open File\n";
        return false;
    }
}

export std::vector<double> center_of_mass(std::vector<Star> vec_star, double a){
    std::vector<double> position;
    position.push_back(pow((1-vec_star[0].mass/vec_star[1].mass),-1.0)*a);
    position.push_back(a - position[0]);
    return position;
}