/*
    Name file : Main.cpp

    purpose : Main function of the project

    Author : Francois Suzeau

    Contributor : Vincent Davin

    Creation date : 01/12/2021

    Update : ------


*/

#include "NeuralNetwork/NeuralNetwork.hpp"


int main(int args, char *argv[])
{
    (void) args;
    (void) argv;

    unsigned int config[] = {2, 2};
    NeuralNetwork nw(config);

    nw.aiPhase();
    nw.displayLayer();

    return EXIT_SUCCESS;
}