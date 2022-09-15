#ifndef HOMOMORPHISM_BAG_SIZES_H
#define HOMOMORPHISM_BAG_SIZES_H

#include <vector>

class BagSizes {
public:
    BagSizes(std::size_t n, std::size_t k) : n(n), k(k), sizes(std::vector<std::size_t>(k + 2)) {
        sizes[0] = 1;
        for (std::size_t i = 1; i < sizes.size(); ++i) {
            sizes[i] = sizes[i - 1] * n;
        }
    }
    std::size_t n, k;
    std::vector<std::size_t> sizes;
};

#endif
