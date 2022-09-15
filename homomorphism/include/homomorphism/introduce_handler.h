#ifndef HOMOMORPHISM_INTRODUCE_HANDLER_H
#define HOMOMORPHISM_INTRODUCE_HANDLER_H

#include <vector>

#include "homomorphism/graph.h"
#include "homomorphism/bag_sizes.h"

class IntroduceHandler {
public:
    IntroduceHandler(std::size_t n, std::size_t k) : size_(BagSizes(n, k)) { }
    virtual std::vector<std::size_t>& Introduce(std::vector<std::size_t> &input, std::vector<std::size_t> &output,
                                                   std::vector<unsigned char>& bag, std::size_t x, std::size_t idx) = 0;
protected:
    BagSizes size_;
};

#endif
