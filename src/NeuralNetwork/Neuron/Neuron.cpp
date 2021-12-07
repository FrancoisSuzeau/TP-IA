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
Neuron::Neuron(float config[3], std::string type) : nb_neuron_to_connect(config[1]), m_ai_value(0.0f), m_out(config[0]), m_type(type), sigma(0.0), m_expected_value(config[2])
{
    m_weight = new float[nb_neuron_to_connect];
    float min = -1.0f;
    float max = 1.0f;

    for (int i = 0; i < nb_neuron_to_connect; i++)
    {
        m_weight[i] = min + ((float) rand() / RAND_MAX * (max - min));
        // std::cout << m_weight[i] << std::endl;
    }
    
}

Neuron::~Neuron()
{
    //? REMIND : No need to delete previous neurons -> already did in Layer class

}

/******************************************************************************************************************************************************/
/************************************************************************ calculateAi *****************************************************************/
/******************************************************************************************************************************************************/
void Neuron::calculateAi(int index)
{
    float ai_Tot(0.0f);
    for(std::vector<Neuron*>::iterator it = in_neurons.begin(); it != in_neurons.end(); ++it)
    {
        if((m_type == "use") || (m_type == "final")) //bias has no ai calculation
        {
            ai_Tot += Calcul::calculateAi(it[0]->getValue(), it[0]->getWeight(index));
        }
    }

    this->setAiValue(ai_Tot);
}

/******************************************************************************************************************************************************/
/***************************************************************** calculateLogActivation *************************************************************/
/******************************************************************************************************************************************************/
void Neuron::calculateLogActivation()
{
    if((m_type == "use") || (m_type == "final"))
    {
        m_out = Calcul::calculY(this->getAi());
    }
    
}

/******************************************************************************************************************************************************/
/********************************************************************** calculateSigma ****************************************************************/
/******************************************************************************************************************************************************/
void Neuron::calculateSigma()
{
    //if i understand it right u -> the expected out value and y -> the out value of the neuron
    if((m_type == "final") || (m_type == "use") || (m_type == "bias"))
    {
        sigma = Calcul::sigma(this->getValue(), m_expected_value);
    }
    
}

/******************************************************************************************************************************************************/
/********************************************************************** calculateDeltasPreviN ****************************************************************/
/******************************************************************************************************************************************************/
void Neuron::calculateDeltasPreviN(float alpha, int index)
{
    for(std::vector<Neuron*>::iterator it = in_neurons.begin(); it != in_neurons.end(); ++it)
    {
        float delta_w = Calcul::calculDeltaW(alpha, sigma, it[0]->getValue());
        it[0]->updateWeighN(delta_w, index);
    }
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
/**************************************************************** calculateErrorNeuron ****************************************************************/
/******************************************************************************************************************************************************/
float Neuron::calculateErrorNeuron()
{
    return Calcul::calculErrorNW(m_expected_value, this->getValue());
}

/******************************************************************************************************************************************************/
/********************************************************************* getters/setters ****************************************************************/
/******************************************************************************************************************************************************/
float Neuron::getWeight(int index) const
{
    return m_weight[index];
}

float Neuron::getValue() const
{
    return m_out;
}

void Neuron::setAiValue(float new_value)
{
    m_ai_value = new_value;
}

float Neuron::getAi() const
{
    return m_ai_value;
}

float Neuron::getSigma() const
{
    return sigma;
}

void Neuron::updateWeighN(float delta_w, int index)
{
    m_weight[index] += delta_w;
}

void Neuron::displayWeightEntrance(int index)
{
    if(m_type != "bias")
    {
        for(std::vector<Neuron*>::iterator it = in_neurons.begin(); it != in_neurons.end(); ++it)
        {
            std::cout << it[0]->getWeight(index) << std::endl;
        }
    }
    
}