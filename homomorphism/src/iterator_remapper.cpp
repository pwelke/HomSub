#include "homomorphism/iterator_remapper.h"

#include <iostream>

#include "homomorphism/remapping_iterator.h"

void IteratorRemapper::Extract(std::vector <std::size_t>& in, std::vector <std::size_t>& out, std::size_t pos) {
    RemappingIterator it = RemappingIterator::ExtractIterator(n_, b_, pos);

    for(auto& e : in) {
        out[it.next()] = e;
    }
}

void IteratorRemapper::Insert(std::vector <std::size_t>& in, std::vector <std::size_t>& out, std::size_t pos) {
    RemappingIterator it = RemappingIterator::InsertIterator(n_, b_, pos);

    for(auto& e : in) {
        out[it.next()] = e;
    }
}

void IteratorRemapper::SetSizes(std::size_t n, std::size_t b) {
    n_ = n;
    b_ = b;
}
