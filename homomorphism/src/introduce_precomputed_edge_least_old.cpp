#include "homomorphism/introduce_precomputed_edge_least_old.h"

#include <iostream>

#include "homomorphism/introduce_mapping_iterator.h"

std::vector<std::size_t>& IntroducePrecomputedEdgeLeastOld::Introduce(std::vector<std::size_t> &input, std::vector<std::size_t> &output,
                                                                 std::vector<unsigned char> &bag, std::size_t x, std::size_t ii) {
    if(input.size() == 1) {
        for(unsigned long & i : output) {
            i = input[0];
        }
        return output;
    }

    if(!bag[0]) {
        std::cerr << "ERROR: IntroducePrecomputedEdgeLeast called with no edge to least significant" << std::endl;
        throw;
    }

    if(ii == 0) {
        std::cerr << "ERROR: IntroducePrecomputedEdgeLeast called with index zero" << std::endl;
        throw;
    }

    std::size_t edges = 0;
    for(auto & edge : bag) {
        if(edge) {
            edges++;
        }
    }

    IntroduceMappingIterator mapping = IntroduceMappingIterator::InitializeSecond(size_.n, bag.size(), bag);
    auto precomputedStart = precomputed_->GetIterator(edges);

    for(std::size_t idx = 0; idx < input.size(); idx += size_.n) {

        //TODO: Include in iterator
        std::size_t newidx = 0;
        for(int i = 0; i < ii; i++) {
            newidx += mapping.mapping_[i] * size_.sizes[i];
        }
        for(int i = ii; i < bag.size(); i++) {
            newidx += mapping.mapping_[i] * size_.sizes[i + 1];
        }

        // Add all valid assignments of vertex x
        for (std::size_t i = 0; i < size_.n; i++)
        {
            auto it = precomputedStart + mapping.CurrentOffset() + i * size_.n;
            std::size_t rangestart = newidx + i * size_.sizes[ii];
            // Add range of value for least significant
            for (std::size_t j = 0; j < size_.n; j++)
            {
                output[rangestart + j] = *(it++) * input[idx + j];
            }
        }

        //TODO: Fix to single operator
        for(int i = 0; i < size_.n; i++) {
            mapping.NextChanged();
        }
    }

    return output;
}