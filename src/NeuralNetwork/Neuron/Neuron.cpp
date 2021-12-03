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
Neuron::Neuron(std::string status) : m_status(status), m_weight(0.0f), m_ai_value(0.0f), m_out(0.0f)
{

}

Neuron::Neuron() : m_status("bias"), m_weight(1.0f), m_ai_value(0.0f), m_out(1.0f) //here no need to set an ai value
{

}

Neuron::~Neuron()
{
    for(std::vector<Neuron*>::iterator it = in_neurons.begin(); it != in_neurons.end(); ++it)
    {
        if(*it != nullptr)
        {
            delete *it;
        }
    }
}


void Neuron::calculateAi()
{

}

void Neuron::calculateLogActivation()
{
    
}

/******************************************************************************************************************************************************/
/********************************************************************* getters/setters ****************************************************************/
/******************************************************************************************************************************************************/
std::string Neuron::getStatus() const
{
    return m_status;
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