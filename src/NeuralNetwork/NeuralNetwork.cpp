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
NeuralNetwork::NeuralNetwork(unsigned int config[2])
{
   for (unsigned int i = 0; i < config[0]; i++)
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