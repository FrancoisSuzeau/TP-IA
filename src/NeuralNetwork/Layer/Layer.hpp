/*
    Name file : Layer.hpp

    purpose : declaration rules of the layer class

    Author : Francois Suzeau

    Contributor : Vincent Davin

    Creation date : 01/12/2021

    Update : ------


*/

#ifndef LAYER_H
#define LAYER_H

    #include <iostream>
    #include <vector>
    #include <math.h>
    #include <string>
    
    #include "../Neuron/Neuron.hpp"

    class Layer
    {
        private:

            //TEMPORAIRE
            std::string             m_id;
            
            std::vector<Neuron*>    m_neurons;

            Layer                   *m_previous_layer;

            
        public:

            Layer(Layer *previous_layer, int nb_neurons, int id);
            ~Layer();

            void connectNeuronsWithPrev();
            void displayNeurons() ;
    };


#endif