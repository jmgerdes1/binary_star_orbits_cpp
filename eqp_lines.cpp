module;
#include "main.h"
export module eqp_lines;

export bool eqp(std::string const&file_name, std::vector<Star> vec_star){
    std::ofstream Myfile(file_name);
    if(!Myfile.is_open()){
        std::cout << "Failed to Open File\n";
        return false;
    }
    std::cout << vec_star[0].mass << std::endl;
}