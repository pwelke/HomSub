#include "homomorphism/vector_allocator_pooling.h"

std::vector<std::size_t> * VectorAllocatorPooling::Allocate(std::size_t b) {
    if(!pool_[b].empty()) {
        auto back = pool_[b].back();
        pool_[b].pop_back();
        return back;
    } else {
        return new std::vector<std::size_t>(size_.sizes[b]);
    }
}

void VectorAllocatorPooling::Free(std::vector<std::size_t> *vector, std::size_t bagSize) {
    pool_[bagSize].push_back(vector);
}

