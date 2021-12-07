/*
    Name file : NeuralNetwork.hpp

    purpose : declaration rules of the neural network class

    Author : Francois Suzeau

    Contributor : Vincent Davin

    Creation date : 03/12/2021

    Update : ------


*/

#include "NeuralNetwork.hpp"

/******************************************************************************************************************************************************/
/********************************************************* Constructors and destructor ****************************************************************/
/******************************************************************************************************************************************************/
NeuralNetwork::NeuralNetwork(unsigned int config[4]): nb_layers(config[0]), alpha(config[3])
{
   for (unsigned int i = 0; i < nb_layers; i++)
   {
       if(i == 0)
       {
           m_layers.push_back(new Layer(nullptr, config[1], i, config[2], false));
       }
       else
       {
           m_layers.push_back(new Layer(m_layers[i - 1], config[1], i, config[2], false));
       }
   }

   m_layers.push_back(new Layer(m_layers[nb_layers - 1], 1, nb_layers, config[2], true)); //final layer with one neuron

   for(std::vector<Layer*>::iterator it = m_layers.begin(); it != m_layers.end(); ++it)
   {
       if(*it != nullptr)
       {
           it[0]->connectNeuronsWithPrev();
       }
   }
}

NeuralNetwork::~NeuralNetwork()
{
    for(std::vector<Layer*>::iterator it = m_layers.begin(); it != m_layers.end(); ++it)
    {
        if(*it != nullptr)
        {
            delete *it;
        }
    }
}

/******************************************************************************************************************************************************/
/***************************************************************** calculateOuput *********************************************************************/
/******************************************************************************************************************************************************/
void NeuralNetwork::calculateOuput()
{
    for(std::vector<Layer*>::iterator it = m_layers.begin(); it != m_layers.end(); ++it)
    {
        if(*it != nullptr)
        {
            it[0]->calculateAiFunction();
            it[0]->calculateLogFunction();
        }
    }
}

/******************************************************************************************************************************************************/
/******************************************************************* convergencePhase *****************************************************************/
/******************************************************************************************************************************************************/
void NeuralNetwork::convergencePhase()
{
    for(std::vector<Layer*>::iterator it = m_layers.end() - 1; it != m_layers.begin() - 1; --it)
    {
        it[0]->calculateSigmaNeurons();
    }

    for(std::vector<Layer*>::iterator it = m_layers.end() - 1; it != m_layers.begin() - 1; --it)
    {
        it[0]->propagateGradient(alpha);
    }
}

/******************************************************************************************************************************************************/
/******************************************************************* displayLayer *********************************************************************/
/******************************************************************************************************************************************************/
void NeuralNetwork::displayLayer()
{
    for(std::vector<Layer*>::iterator it = m_layers.begin(); it != m_layers.end(); ++it)
    {
        if(*it != nullptr)
        {
            it[0]->displayNeurons();
        }
    }
}

/******************************************************************************************************************************************************/
/***************************************************************** getFinalOutput *********************************************************************/
/******************************************************************************************************************************************************/
float NeuralNetwork::getFinalOutput() const
{
    return m_layers[nb_layers]->getOutPut();
}

/******************************************************************************************************************************************************/
/***************************************************************** calculateError *********************************************************************/
/******************************************************************************************************************************************************/
void NeuralNetwork::calculateError()
{
    error = m_layers[nb_layers]->calculateErrorFinalNeuron();

    std::cout << error << std::endl;
}