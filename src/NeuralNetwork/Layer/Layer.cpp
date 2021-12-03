/*
    Name file : Layer.hpp

    purpose : declaration rules of the layer class

    Author : Francois Suzeau

    Contributor : Vincent Davin

    Creation date : 03/12/2021

    Update : ------


*/

#include "Layer.hpp"

/******************************************************************************************************************************************************/
/********************************************************* Constructors and destructor ****************************************************************/
/******************************************************************************************************************************************************/
Layer::Layer(Layer *previous_layer)
{
    m_previous_layer = previous_layer;
}

Layer::~Layer()
{
    for(std::vector<Neuron*>::iterator it = m_neurons.begin(); it != m_neurons.end(); ++it)
    {
        if(*it != nullptr)
        {
            delete *it;
        }
    }

    //? Don't know if i keep that yet
    // if(m_previous_layer != nullptr)
    // {
    //     delete m_previous_layer;
    // }
}