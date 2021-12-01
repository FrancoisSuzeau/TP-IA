/*
    Name file : Neural.hpp

    purpose : declaration rules of the neural class

    Author : Francois Suzeau

    Contributor : Vincent Davin

    Creation date : 01/12/2021

    Update : ------


*/

#ifndef NEURAL_H
#define NEURAL_H

    #include <iostream>

    class Neural
    {
        private:

            std::string m_status;

        public:

            Neural(std::string status);
            ~Neural();
            std::string getStatus() const;
    };


#endif