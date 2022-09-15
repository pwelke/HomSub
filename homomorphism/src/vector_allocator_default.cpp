#include "homomorphism/vector_allocator_default.h"

std::vector<std::size_t>* VectorAllocatorDefault::Allocate(std::size_t b) {
    return new std::vector<std::size_t>(size_.sizes[b]);
}

void VectorAllocatorDefault::Free(std::vector<std::size_t>* vector, std::size_t bagsize) {
    delete vector;
}
