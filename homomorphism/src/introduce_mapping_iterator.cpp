#include "homomorphism/introduce_mapping_iterator.h"

IntroduceMappingIterator IntroduceMappingIterator::InitializeLeast(std::size_t n, std::size_t k, std::vector<unsigned char> edges) {
    std::vector<std::size_t> offsets(k, 0);

    std::size_t offset = 1;

    for (int i = 0; i < k; ++i) {
        if(edges[i]) {
            offset *= n;
            offsets[i] = offset;
        }
    }

    return IntroduceMappingIterator(n, k, offsets);
}

IntroduceMappingIterator IntroduceMappingIterator::InitializeSecond(std::size_t n, std::size_t k, std::vector<unsigned char> edges) {
    std::vector<std::size_t> offsets(k, 0);

    std::size_t offset = 1;

    for (int i = 0; i < k; ++i) {
        if(edges[i]) {
            offsets[i] = offset;
            offset *= n;
            if(offset == n) {
                offset *= n;
            }
        }
    }

    return IntroduceMappingIterator(n, k, offsets);
}

IntroduceMappingIterator IntroduceMappingIterator::InitializeInputIterator(std::size_t n, std::size_t k, std::size_t pos) {
    std::vector<std::size_t> offsets(k, 0);

    std::size_t offset = n;

    for (int i = 0; i < k; ++i) {
        if(i != pos) {
            offsets[i] = offset;
            offset *= n;
        }
    }

    return IntroduceMappingIterator(n, k, offsets);
}

IntroduceMappingIterator IntroduceMappingIterator::InitializePrecomputedSecond(std::size_t n, std::vector<unsigned char> edges, std::size_t pos) {
    std::vector<std::size_t> offsets(edges.size(), 0);

    std::size_t offset = n * n;
    auto edge = edges.begin() + 1;

    for (int i = 0; i < edges.size(); ++i) {
        if(i == pos) {
            offsets[i] = n;
        } else if (*edge++) {
            offsets[i] = offset;
            offset *= n;
        }
    }

    return IntroduceMappingIterator(n, edges.size(), offsets);
}

IntroduceMappingIterator IntroduceMappingIterator::InitializePrecomputedNonedge(std::size_t n, std::vector<unsigned char> edges, std::size_t pos) {
    std::vector<std::size_t> offsets(edges.size(), 0);

    std::size_t offset = n;
    auto edge = edges.begin() + 1;

    for (int i = 0; i < edges.size(); ++i) {
        if(i == pos) {
            offsets[i] = 1;
        } else if (*edge++) {
            offsets[i] = offset;
            offset *= n;
        }
    }

    return IntroduceMappingIterator(n, edges.size(), offsets);
}

std::size_t IntroduceMappingIterator::CurrentOffset() {
    return current_;
}

bool IntroduceMappingIterator::NextChanged() {
    std::size_t prev = current_;

    for (int i = 0; i < mapping_.size(); ++i)
    {
        if (mapping_[i] < n_ - 1)
        {
            mapping_[i]++;
            current_ += offsets_[i];
            break;
        } else {
            mapping_[i] = 0;
            current_ -= offsets_[i] * (n_ - 1);
        }
    }

    return prev != current_;
}
