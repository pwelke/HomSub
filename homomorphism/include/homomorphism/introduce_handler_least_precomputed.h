#ifndef HOMOMORPHISM_INTRODUCE_HANDLER_LAST_PRECOMPUTED_H
#define HOMOMORPHISM_INTRODUCE_HANDLER_LAST_PRECOMPUTED_H

#include <utility>

#include "homomorphism/introduce_handler_least.h"

#include "homomorphism/edge_consistency_precomputation.h"

class IntroduceHandlerLeastPrecomputed : public IntroduceHandlerLeast {
public:
    IntroduceHandlerLeastPrecomputed(std::shared_ptr<EdgeConsistencyPrecomputation> precomputed):
                                    precomputed_(std::move(precomputed)) {};
    std::vector<std::size_t>& introduceLast(std::vector <std::size_t> &input, std::vector <std::size_t> &output,
                                       std::vector <std::size_t>& bag, std::shared_ptr<Graph> h,
                                       std::shared_ptr<Graph> g, std::size_t n, std::size_t x) override;
private:
    std::shared_ptr<EdgeConsistencyPrecomputation> precomputed_;
};

#endif
