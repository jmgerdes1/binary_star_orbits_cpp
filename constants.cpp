module;
#include "main.h"
export module constants;

class constant {                            //constants and conversion factors
    public:
        double standard;                    //Base SI units
        double astro;                       //Converted to astronomical units
        constant(double a, double b){
            standard = a;
            astro = b;
        }
};

export constant conv_AU(149597890.7e3,1.0);
export constant conv_SM(1.98847e30,1.0);

export constant const_G(6.67430e-11,6.67430e-11*pow(conv_AU.standard,-2)*pow(conv_SM.standard,2));