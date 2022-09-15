#ifndef HOMOMORPHISM_INTRODUCE_HANDLER_LEAST_H
#define HOMOMORPHISM_INTRODUCE_HANDLER_LEAST_H

#include <vector>

#include "homomorphism/graph.h"
#include "homomorphism/bag_sizes.h"

class IntroduceHandlerLeast {
public:
    //IntroduceHandlerLeast(std::size_t n, std::size_t k) : size_(BagSizes(n, k)) { }
    // TODO: Could store variables to simplify function
    virtual std::vector<std::size_t>& introduceLast(std::vector <std::size_t> &input, std::vector <std::size_t> &output,
                                               std::vector <std::size_t>& bag, std::shared_ptr<Graph> h,
                                               std::shared_ptr<Graph> g, std::size_t n, std::size_t x) = 0;
//protected:
//    BagSizes size_;
};

#endif
