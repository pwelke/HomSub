#include "homomorphism/introduce_handler_least_precomputed.h"

#include "homomorphism/introduce_mapping_iterator.h"

std::vector<std::size_t>& IntroduceHandlerLeastPrecomputed::introduceLast(std::vector<std::size_t> &input, std::vector<std::size_t> &output,
                                                                     std::vector<std::size_t> &bag, std::shared_ptr<Graph> h, std::shared_ptr<Graph> g, std::size_t n, std::size_t x) {
    if(input.size() == 1) {
        for(unsigned long & i : output) {
            i = input[0];
        }
        return output;
    }

    // Figure out which vertices in H are connected to the introduced vertex
    std::vector<unsigned char> connected(bag.size(), false);
    std::size_t edges = 0;
    for (int i = 0; i < bag.size(); i++)
    {
        if(h->edgeExist(x, bag[i])) {
            connected[i] = true;
            edges++;
        }
    }

    IntroduceMappingIterator mapping = IntroduceMappingIterator::InitializeLeast(n, bag.size(), connected);
    auto precomputedStart = precomputed_->GetIterator(edges);

    for(std::size_t idx = 0; idx < input.size(); idx++) {
        std::size_t count = input[idx];

        std::size_t newidx = idx * n;

        auto it = precomputedStart + mapping.CurrentOffset();

        // Add all valid assignments of vertex x
        for (std::size_t i = 0; i < n; i++)
        {
            output[newidx + i] = *(it++) * count;
        }

        mapping.NextChanged();
    }

    return output;
}

