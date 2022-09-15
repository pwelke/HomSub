#ifndef HOMOMORPHISM_INTRODUCE_HANDLER_COMPUTE_H
#define HOMOMORPHISM_INTRODUCE_HANDLER_COMPUTE_H

#include "homomorphism/introduce_handler_least.h"

class IntroduceHandlerCompute : public IntroduceHandlerLeast {
public:
    std::vector<std::size_t>& introduceLast(std::vector <std::size_t> &input, std::vector <std::size_t> &output,
                                               std::vector <std::size_t>& bag, std::shared_ptr<Graph> h,
                                               std::shared_ptr<Graph> g, std::size_t n, std::size_t x) override;
};

#endif
