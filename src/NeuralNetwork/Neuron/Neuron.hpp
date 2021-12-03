/*
    Name file : Neuron.hpp

    purpose : declaration rules of the neural class

    Author : Francois Suzeau

    Contributor : Vincent Davin

    Creation date : 01/12/2021

    Update : ------


*/

#ifndef NEURON_H
#define NEURON_H

    #include <iostream>
    #include <vector>
    #include <math.h>

    class Neuron
    {
        private:

            std::string     m_status;

            float           m_weight;
            float           m_ai_value; // equal to the value the neuron compute with the linear function
            float           m_out; // equal to the value the neuron compute with the logical activation function and sending to the next neuron with the weight

            std::vector<Neuron*>    in_neurons;


            //TEMPORAIRE
            void calculateAi();
            void calculateLogActivation();

        public:

            Neuron(std::string status);
            Neuron(); //Constructor for bias neuron
            ~Neuron();
            std::string getStatus() const;
            float       getWeight() const;
            float       getValue() const;

            void setAiValue(float new_value); //here new_value equal what the linear function calculate (WHHEN we will have the static class function)
    };


#endif