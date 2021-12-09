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
#include <chrono>
#include <ctime>


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
            }   
        }
    }

    unsigned int config[4];

    switch (arguments.size())
    {
        case 0:
            std::cout << "Program will run with 4 number of layer and 3 neurons per layer" << std::endl;
            config[0] = 3; // + one with final layer
            config[1] = 2; // + one with bias neuron
            break;
        case 1:
            std::cout << "Program will run with " << arguments[0] + 1 << " number of layer and 3 neurons per layer" << std::endl;
            config[0] = arguments[0];
            config[1] = 2; // + one with bias neuron
            break;
        default:
            std::cout << "Program will run with " << arguments[0] + 1 << " number of layer and " << arguments[1] + 1 << " neurons per layer" << std::endl;
            config[0] = arguments[0];
            config[1] = arguments[1];
            break;
    }

    config[2] = 1.0f;
    config[3] = 1.0f;

    NeuralNetwork nw(config);

    float error_at_start(0.0f);
    float error_at_end(0.0f);

    Calcul::Start();

    int i(0);
    do
    {
        nw.calculateOuput();
        nw.convergencePhase();

        // std::cout << nw.getFinalOutput() << std::endl;
        if(i == 0)
        {
            error_at_start = nw.calculateError();
        }

        i++;

    } while(nw.getFinalOutput() < 0.999);

    Calcul::End();

    error_at_end = nw.calculateError();

    // nw.displayLayer();

    puts(" ");
    puts(" ");

    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Performance <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;

    puts(" ");
    puts(" ");

    std::cout << "Time passed : " << (time_t) Calcul::getTimePassed() << std::endl;
    std::cout << "Iteration count : " << i << std::endl;
    std::cout << "Error at first try : " << error_at_start << std::endl;
    std::cout << "Error at the end : " << error_at_end << std::endl;

    return EXIT_SUCCESS;
}