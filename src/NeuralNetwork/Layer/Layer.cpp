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
    m_id = std::to_string(id);

    for (int i = 0; i < nb_neurons; i++)
    {
        if(m_previous_layer == nullptr) // first layer
        {
            float config[] = {1.0f, nb_neurons};
            m_neurons.push_back(new Neuron(config, "use"));
        }
        else
        {
            float config[] = {0.0f, nb_neurons};
            m_neurons.push_back(new Neuron(config, "use"));
        }
    }

    if(nb_neurons != 1)
    {
        float config[] = {1.0f, (int)nb_neurons};
        m_neurons.push_back(new Neuron(config, "bias")); //added a bias neuron
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
/************************************************************ calculateAiFunction *********************************************************************/
/******************************************************************************************************************************************************/
void Layer::calculateAiFunction()
{
    if(m_previous_layer != nullptr)
    {
        int i(0);
        for(std::vector<Neuron*>::iterator it = m_neurons.begin(); it != m_neurons.end(); ++it)
        {
            if(*it != nullptr)
            {
                it[0]->calculateAi(i);
                it[0]->calculateLogActivation();
                i++;
            }
        }
    }
}

/******************************************************************************************************************************************************/
/***************************************************************** calculateSigmaNeurons *********************************************************************/
/******************************************************************************************************************************************************/
void Layer::calculateSigmaNeurons()
{
    for(std::vector<Neuron*>::iterator it = m_neurons.begin(); it != m_neurons.end(); ++it)
    {
        if(*it != nullptr)
        {
            it[0]->calculateSigma();
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
        std::cout << "My out : " << it[0]->getValue() << std::endl;
        std::cout << "My sigma : " << it[0]->getSigma() << std::endl;
        
    }
}