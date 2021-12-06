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
NeuralNetwork::NeuralNetwork(unsigned int config[2]): nb_layers(config[0])
{
   for (unsigned int i = 0; i < nb_layers; i++)
   {
       if(i == 0)
       {
           m_layers.push_back(new Layer(nullptr, config[1], i));
       }
       else
       {
           m_layers.push_back(new Layer(m_layers[i - 1], config[1], i));
       }
   }

   m_layers.push_back(new Layer(m_layers[nb_layers - 1], 1, nb_layers)); //final layer with one neuron

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
/************************************************************************ aiPhase *********************************************************************/
/******************************************************************************************************************************************************/
void NeuralNetwork::aiPhase()
{
    for(std::vector<Layer*>::iterator it = m_layers.begin(); it != m_layers.end(); ++it)
    {
        if(*it != nullptr)
        {
            it[0]->calculateAiFunction();
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