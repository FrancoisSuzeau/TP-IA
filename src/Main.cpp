/*
    Name file : Main.cpp

    purpose : Main function of the project

    Author : Francois Suzeau

    Contributor : Vincent Davin

    Creation date : 01/12/2021

    Update : ------


*/

#include "Neuron/Neuron.hpp"


int main(int args, char *argv[])
{
    (void) args;
    (void) argv;

    Neuron ne("Inactive");

    std::cout << ">>> Neural network -- status : " << ne.getStatus() << std::endl;

    return EXIT_SUCCESS;
}