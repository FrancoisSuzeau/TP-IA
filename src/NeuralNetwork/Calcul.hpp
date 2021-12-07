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
#include <chrono>
#include <ctime>

    

    class Calcul
    {
        private:
            
            static time_t start_progr;
            static time_t end_progr;

        public:

            Calcul(/* args */);
            ~Calcul();

            static float sigma(float y, float u);
            static float calculDeltaW(float alpha, float sigma, float out);
            static float calculY(float ai);
            static float calculateAi(float in_prev_n, float weigh_prev_n);
            static float calculErrorNW(float expected_value, float real_output);

            static void Start();
            static void End();
            static time_t getTimePassed();
    };


#endif