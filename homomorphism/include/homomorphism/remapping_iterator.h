#ifndef HOMOMORPHISM_REMAPPING_ITERATOR_H_
#define HOMOMORPHISM_REMAPPING_ITERATOR_H_

#include <memory>
#include <utility>
#include <vector>

class RemappingIterator
{
public:
    RemappingIterator(std::size_t n, std::size_t k, std::vector<std::size_t> offsets):
            n_(n), k_(k), offsets_(std::move(offsets)), current_(0), mapping_(std::vector<std::size_t> (k, 0)) {}

    static RemappingIterator ExtractIterator(std::size_t n, std::size_t k, std::size_t pos);
    static RemappingIterator InsertIterator(std::size_t n, std::size_t k, std::size_t pos);
    static RemappingIterator CustomIterator(std::size_t n, std::size_t k, std::vector<std::size_t> offsets);

    std::size_t next();
private:
    std::size_t n_, k_, current_;
    std::vector<std::size_t> offsets_, mapping_;
};

#endif
