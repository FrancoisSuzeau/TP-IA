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

    class Neuron
    {
        private:

            std::string     m_status;

            float           m_weight;
            float           m_out;

            std::vector<Neuron*>    in_neural;

        public:

            Neuron(std::string status);
            ~Neuron();
            std::string getStatus() const;
    };


#endif