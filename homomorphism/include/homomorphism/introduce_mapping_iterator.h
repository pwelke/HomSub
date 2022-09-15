#ifndef HOMOMORPHISM_INTRODUCE_MAPPING_ITERATOR_H
#define HOMOMORPHISM_INTRODUCE_MAPPING_ITERATOR_H

#include <vector>

class IntroduceMappingIterator {
public:
    IntroduceMappingIterator(std::size_t n, std::size_t k, std::vector<std::size_t> offsets):
    n_(n), k_(k), offsets_(std::move(offsets)), current_(0), mapping_(std::vector<std::size_t> (k, 0)) {}

    static IntroduceMappingIterator InitializeLeast(std::size_t n, std::size_t k, std::vector<unsigned char> edges);
    static IntroduceMappingIterator InitializeSecond(std::size_t n, std::size_t k, std::vector<unsigned char> edges);
    static IntroduceMappingIterator InitializeInputIterator(std::size_t n, std::size_t k, std::size_t pos);
    static IntroduceMappingIterator InitializePrecomputedSecond(std::size_t n, std::vector<unsigned char> edges, std::size_t pos);
    static IntroduceMappingIterator InitializePrecomputedNonedge(std::size_t n, std::vector<unsigned char> edges, std::size_t pos);

    bool NextChanged();
    std::size_t CurrentOffset();
    std::vector<std::size_t> mapping_;
private:
    std::size_t n_, k_, current_;
    std::vector<std::size_t> offsets_;
};

#endif
