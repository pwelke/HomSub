#include "homomorphism/introduce_precomputed_nonedge_least_old.h"

#include <iostream>

#include "homomorphism/introduce_mapping_iterator.h"

std::vector<std::size_t>& IntroducePrecomputedNonedgeLeastOld::Introduce(std::vector<std::size_t> &input, std::vector<std::size_t> &output,
                                                                 std::vector<unsigned char> &bag, std::size_t x, std::size_t ii) {
    if(input.size() == 1) {
        for(unsigned long & i : output) {
            i = input[0];
        }
        return output;
    }

    if(bag[0]) {
        std::cerr << "ERROR: IntroducePrecomputedNonedgeLeast called with edge to least significant" << std::endl;
        throw;
    }

    if(ii == 0) {
        std::cerr << "ERROR: IntroducePrecomputedNonedgeLeast called with index zero" << std::endl;
        throw;
    }

    std::size_t edges = 0;
    for(auto & edge : bag) {
        if(edge) {
            edges++;
        }
    }

    IntroduceMappingIterator mapping = IntroduceMappingIterator::InitializeLeast(size_.n, bag.size(), bag);
    auto precomputedStart = precomputed_->GetIterator(edges);

    std::cerr << "ERROR: There is a bug in the old introducehandler nonedge. Output might be incorrect!!!" << std::endl;

    for(std::size_t idx = 0; idx < input.size(); idx += size_.n) {

        //TODO: Include in iterator
        std::size_t newidx = 0;
        for(int i = 0; i < ii; i++) {
            newidx += mapping.mapping_[i] * size_.sizes[i];
        }
        for(int i = ii + 1; i < bag.size(); i++) {
            newidx += mapping.mapping_[i] * size_.sizes[i + 1];
        }

        auto it = precomputedStart + mapping.CurrentOffset();

        // Add all valid assignments of vertex x
        for (std::size_t i = 0; i < size_.n; i++)
        {
            std::size_t rangestart = newidx + i * size_.sizes[ii];
            if(*(it++)) {
                std::copy(input.begin() + idx, input.begin() + idx + size_.n, output.begin() + rangestart);
            } else {
                std::fill(output.begin() + rangestart, output.begin() + rangestart + size_.n, 0);
            }
        }

        //TODO: Fix to single operator
        for(int i = 0; i < size_.n; i++) {
            mapping.NextChanged();
        }
    }

    return output;
}