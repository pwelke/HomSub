#ifndef HOMOMORPHISM_GRAPH6HELPER_H_
#define HOMOMORPHISM_GRAPH6HELPER_H_

#include <string>

class Graph6helper
{
public:
    static char R(std::size_t x); 
    static std::string N(std::size_t x);
    static std::size_t readN(std::stringstream& in);
};

#endif