module;
#include "main.h"
export module parse;

int N;
int num_star_prop=1;                                                                            //Number of properties for each star in config file
int num_planet_prop=1;                                                                          //Number of properties for each planet in config file
Star object_star;
Planet object_planet;

export bool parse_run(std::string const&file_name);
bool parser(std::string file_name);
void tokenize(std::string const &str, const char delim, std::vector<std::string> &out);

export std::vector<Star> vec_star;
export std::vector<Planet> vec_planet;
export double a;                                                                                //Distance between the stars
export double x_range[2];                                                                       //range of space in x direction for gravitational potential calculation
export int x_steps;                                                                          //distance per step in the x direction for gravitational potential calculation
export double y_range[2];                                                                       //range of space in y direction for gravitational potential calculation
export int y_steps;                                                                          //distance per step in the y direction for gravitational potential calculation

export bool parse_run(std::string const &file_name){
    if(!parser(file_name)){
        return false;
    }
    return true;
}

bool parser(std::string file_name){
    std::ifstream in;
    in.open(file_name);
    if(!in.is_open()){
        std::cout << "Failed to Load System File\n";
        return false;
    }

    std::string line;
    const char delim = ' ';
    std::vector<std::string> list;

    while(!in.eof()){
        getline(in,line);
        tokenize(line,delim,list);
    }

    for(int i=0; i < list.size(); i++){
        if(list[i]=="STAR"){
            for(int j=1; j <= num_star_prop; j=j+2){
                if(list[i+j]=="MASS"){
                    object_star.mass = std::stod(list[i+j+1]);
                }
            }
            i = i + 2 * num_star_prop;
            vec_star.push_back(object_star);
        } else if(list[i]=="PLANET"){
            for(int j=1; j <= num_planet_prop; j=j+2){
                if(list[i+j]=="MASS"){
                    object_planet.mass = std::stod(list[i+j+1]);
                }
            }
            i = i + 2 * num_planet_prop;
            vec_planet.push_back(object_planet);
        } else if(list[i]=="STELLAR_DISTANCE:"){
            a = std::stod(list[i+1]);
            i++;
        } else if(list[i]=="X_RANGE:"){
            x_range[0] = std::stod(list[i+1]);
            x_range[1] = std::stod(list[i+2]);
            i = i + 2;
        } else if(list[i]=="X_STEPS:"){
            x_steps = std::stoi(list[i+1]);
            i++;
        } else if(list[i]=="Y_RANGE:"){
            y_range[0] = std::stod(list[i+1]);
            y_range[1] = std::stod(list[i+2]);
            i = i + 2;
        } else if(list[i]=="Y_STEPS:"){
            y_steps = std::stoi(list[i+1]);
            i++;
        }
    }
    return true;
}

void tokenize(std::string const &str, const char delim, std::vector<std::string> &out){
    std::stringstream ss(str);
    std::string s;
    while(std::getline(ss,s,delim)){
        out.push_back(s);
    }
}