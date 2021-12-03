/*
    Name file : NeuralNetwork.hpp

    purpose : declaration rules of the layer class

    Author : Francois Suzeau

    Contributor : Vincent Davin

    Creation date : 03/12/2021

    Update : ------


*/

#ifndef NEURALNET_H
#define NEURALNET_H

    #include <iostream>
    #include <vector>
    #include <math.h>
    
    #include "Layer/Layer.hpp"

    class NeuralNetwork
    {
        private:

            std::vector<Layer*>     m_layers;

            
        public:

            NeuralNetwork(unsigned int config[2]);
            ~NeuralNetwork();

            void displayLayer();
    };


#endif