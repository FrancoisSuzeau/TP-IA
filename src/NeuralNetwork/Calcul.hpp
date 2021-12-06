/*
    Name file : Calcul.hpp

    purpose : declaration rules of the calcul abstract class

    Author : Vincent Davin

    Contributor : Francois Suzeau

    Creation date : 04/12/2021

    Update : ------

*/

#ifndef CALCUL_H
#define CALCUL_H

#include <iostream>
#include <vector>
#include <math.h>

    

    class Calcul
    {
        private:
            /* data */
        public:

            Calcul(/* args */);
            ~Calcul();

            static float sigma(float y, float u);
            static float calculY(float ai);
            static float calculateAi(float in_prev_n, float weigh_prev_n);
    };


#endif