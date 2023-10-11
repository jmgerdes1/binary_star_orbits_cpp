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

export constant conv_AU(pow(149597890.7, 3),1.0);
export constant conv_SM(pow(1.98847,30),1.0);

export constant const_G(pow(6.67430,-11),pow(6.67430,-11)*pow(conv_AU.standard,-2)*pow(conv_SM.standard,2));