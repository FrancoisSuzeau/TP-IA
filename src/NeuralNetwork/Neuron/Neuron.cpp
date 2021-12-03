/*
    Name file : Neuron.cpp

    purpose : definition rules of the neural class

    Author : Francois Suzeau

    Contributor : Vincent Davin

    Creation date : 01/12/2021

    Update : ------


*/
#include "Neuron.hpp"


/******************************************************************************************************************************************************/
/********************************************************* Constructors and destructor ****************************************************************/
/******************************************************************************************************************************************************/
Neuron::Neuron(std::string layerID, float weight) : m_layerID(layerID), m_weight(weight), m_ai_value(0.0f), m_out(0.0f)
{

}

Neuron::Neuron() : m_layerID("bias"), m_weight(1.0f), m_ai_value(0.0f), m_out(1.0f) //here no need to set an ai value
{

}

Neuron::~Neuron()
{
    //? REMIND : No need to delete previous neurons -> already did in Layer class

}


void Neuron::calculateAi()
{

}

void Neuron::calculateLogActivation()
{
    
}

/******************************************************************************************************************************************************/
/****************************************************************** setPreviousNeurons ****************************************************************/
/******************************************************************************************************************************************************/
void Neuron::setPreviousNeurons(std::vector<Neuron*> previous_neurons)
{
    for(std::vector<Neuron*>::iterator it = previous_neurons.begin(); it != previous_neurons.end(); ++it)
    {
        in_neurons.push_back(*it);
    }
}

/******************************************************************************************************************************************************/
/********************************************************************* getters/setters ****************************************************************/
/******************************************************************************************************************************************************/
std::string Neuron::getLayer() const
{
    return m_layerID;
}

float Neuron::getWeight() const
{
    return m_weight;
}

float Neuron::getValue() const
{
    return m_out;
}

void Neuron::setAiValue(float new_value)
{
    m_ai_value = new_value;
}