/*
    Name file : Calcul.cpp

    purpose : declaration rules of the calcul abstract class

    Author : Vincent Davin

    Contributor : Francois Suzeau

    Creation date : 01/12/2021

    Update : ------


*/

#include "Calcul.hpp"

Calcul::Calcul()
{

}

Calcul::~Calcul()
{

}

float Calcul::delta(float y, float u)
{
    return (u - y) * y * (1.0 - y); 
}

float Calcul::calculY(float sigma)
{
    return 1.0 / (1.0 + exp((-1)*sigma));
}

float Calcul::calculateAi(float in_prev_n, float weigh_prev_n)
{
    return in_prev_n * weigh_prev_n;
}