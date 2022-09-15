#ifndef HOMOMORPHISM_FORGET_HANDLER_H
#define HOMOMORPHISM_FORGET_HANDLER_H

#include <vector>

#include "homomorphism/bag_sizes.h"

class ForgetHandler {
public:
    ForgetHandler(std::size_t n, std::size_t k) : size_(BagSizes(n, k)) { }
    virtual std::vector<std::size_t>& forget(std::vector<std::size_t>& input, std::vector<std::size_t>& output, std::size_t b, std::size_t idx) = 0;

    void SetSizes(std::size_t n, std::size_t k) {
        size_ = BagSizes(n, k);
    }
protected:
    BagSizes size_;
};

#endif
