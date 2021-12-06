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
    #include "../Calcul.hpp"

    class Neuron
    {
        private:

            std::string     m_type;
            float           *m_weight; // a tab because all neurons have a different weight for the number of neuron of the next layer
            int             nb_neuron_to_connect;
            float           m_ai_value; // equal to the value the neuron compute with the linear function
            float           m_out; // equal to the value the neuron compute with the logical activation function and sending to the next neuron with the weight
            float           sigma;
            float           m_expected_value;

            std::vector<Neuron*>    in_neurons;


            //TEMPORAIRE
            
            

        public:

            Neuron(float config[3], std::string type);
            ~Neuron();
            float       getWeight(int index) const;
            float       getValue() const;
            float       getAi() const;
            float       getSigma() const;
            void        updateWeighN(float delta_w, int index);


            void setPreviousNeurons(std::vector<Neuron*> previous_neurons);
            void calculateAi(int index);
            void calculateLogActivation();
            void calculateSigma();
            void calculateDeltasPreviN(float alpha, int index);
            

            void setAiValue(float new_value); //here new_value equal what the linear function calculate (WHHEN we will have the static class function)
    };


#endif