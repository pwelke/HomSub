#include "homomorphism/introduce_precomputed_least.h"

#include "homomorphism/introduce_mapping_iterator.h"

std::vector<std::size_t>& IntroducePrecomputedLeast::Introduce(std::vector<std::size_t> &input, std::vector<std::size_t> &output,
        std::vector<unsigned char> &bag, std::size_t x, std::size_t idx) {
    if(input.size() == 1) {
        for(unsigned long & i : output) {
            i = input[0];
        }
        return output;
    }

    std::size_t edges = 0;
    for(auto & edge : bag) {
        if(edge) {
            edges++;
        }
    }

    IntroduceMappingIterator mapping = IntroduceMappingIterator::InitializeLeast(size_.n, bag.size(), bag);
    auto precomputedStart = precomputed_->GetIterator(edges);

    for(std::size_t idx = 0; idx < input.size(); idx++) {
        std::size_t count = input[idx];

        std::size_t newidx = idx * size_.n;

        auto it = precomputedStart + mapping.CurrentOffset();

        // Add all valid assignments of vertex x
        for (std::size_t i = 0; i < size_.n; i++)
        {
            output[newidx + i] = *(it++) * count;
        }

        mapping.NextChanged();
    }

    return output;
}