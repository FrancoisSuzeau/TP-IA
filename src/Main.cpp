/*
    Name file : Main.cpp

    purpose : Main function of the project

    Author : Francois Suzeau

    Contributor : Vincent Davin

    Creation date : 01/12/2021

    Update : ------


*/

#include "NeuralNetwork/NeuralNetwork.hpp"
#include <string>
#include <iostream>
#include <vector>


int main(int args, char *argv[])
{
    std::vector<int> arguments;

    for(int i(1); i < args; i++)
    {
        try {
            arguments.push_back(std::stoi(argv[i]));
        }
        catch(std::exception &e) {
            if(e.what())
            {
                std::cout << "INVALIDE ARGUMENT at program start : must be two integers superior to 0" << std::endl;
                return EXIT_FAILURE;
            }   
        }
    }

    unsigned int config[2];

    switch (arguments.size())
    {
        case 0:
            std::cout << "Program will run with 4 number of layer and 3 neurons per layer" << std::endl;
            config[0] = 3; // + one with final layer
            config[1] = 2; // + one with bias neuron
            break;
        case 1:
            std::cout << "Program will run with " << arguments[0] + 1 << "number of layer and 3 neurons per layer" << std::endl;
            config[0] = arguments[0];
            config[1] = 2; // + one with bias neuron
            break;
        default:
            break;
    }
    
    NeuralNetwork nw(config);

    nw.aiPhase();
    nw.displayLayer();

    return EXIT_SUCCESS;
}