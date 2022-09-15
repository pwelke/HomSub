#ifndef HOMOMORPHISM_REMAPPER_H
#define HOMOMORPHISM_REMAPPER_H

#include <vector>

// Used to modify the state of the DP
// A desired vertex is either moving from or to the last position
// Both vectors should have at least size n^b
// n is the number of vertices of G and b is the size of the bag
class Remapper {
public:
    virtual void SetSizes(std::size_t n, std::size_t b) = 0;
    // Moves the vertex from pos to the last position
    virtual void Extract(std::vector<std::size_t>& in, std::vector<std::size_t>& out, std::size_t pos) = 0;
    // Moves the vertex from the last position to pos
    virtual void Insert(std::vector<std::size_t>& in, std::vector<std::size_t>& out, std::size_t pos) = 0;
};

#endif
