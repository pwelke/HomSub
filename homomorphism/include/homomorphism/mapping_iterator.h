#ifndef HOMOMORPHISM_MAPPING_ITERATOR_H
#define HOMOMORPHISM_MAPPING_ITERATOR_H

#include <vector>

class MappingIterator
{
public:
    MappingIterator(int n, int k) : mapping(std::vector<std::size_t>(k, 0)), n_(n) {}

    std::vector<std::size_t> mapping;
    std::size_t idx = 0;

    void Increment();
private:
    std::size_t n_;
};


#endif
