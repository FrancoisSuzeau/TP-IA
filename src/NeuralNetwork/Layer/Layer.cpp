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
Layer::Layer(Layer *previous_layer, int nb_neurons, int id)
{
    m_previous_layer = previous_layer;
    float min = 0.1f;
    float max = 0.9f;
    m_id = std::to_string(id);

    for (int i = 0; i < nb_neurons; i++)
    {
        float weight_n = min + ((float) rand() / RAND_MAX * (max - min + 1.0));
        m_neurons.push_back(new Neuron(m_id, weight_n));
    }
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

    //? REMIND : No need to delete previous layer -> already did in NeuralNetwork class
}

/******************************************************************************************************************************************************/
/********************************************************* connectNeuronsWithPrev *********************************************************************/
/******************************************************************************************************************************************************/
void Layer::connectNeuronsWithPrev()
{
    if(m_previous_layer != nullptr)
    {
        for(std::vector<Neuron*>::iterator it = m_neurons.begin(); it != m_neurons.end(); ++it)
        {
            if(*it != nullptr)
            {
                it[0]->setPreviousNeurons(m_previous_layer->m_neurons);
            }
        }
    }
}

/******************************************************************************************************************************************************/
/***************************************************************** displayNeurons *********************************************************************/
/******************************************************************************************************************************************************/
void Layer::displayNeurons()
{

    std::cout << "Layer : " << m_id << std::endl;
    for(std::vector<Neuron*>::iterator it = m_neurons.begin(); it != m_neurons.end(); ++it)
    {
        if(m_previous_layer != nullptr)
        {
            std::cout << "Previous layer : " << m_previous_layer->m_id << std::endl;
        }

        std::cout << "My layer : " << it[0]->getLayer() << std::endl;
        std::cout << "My weight : " << it[0]->getWeight() << std::endl;
        
    }
}