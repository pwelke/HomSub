#ifndef HOMOMORPHISM_INTRODUCE_PRECOMPUTED_EDGE_LEAST_OLD_H
#define HOMOMORPHISM_INTRODUCE_PRECOMPUTED_EDGE_LEAST_OLD_H

#include "homomorphism/introduce_handler.h"

#include "homomorphism/edge_consistency_precomputation.h"

class IntroducePrecomputedEdgeLeastOld : IntroduceHandler{
public:
    IntroducePrecomputedEdgeLeastOld(std::size_t n, std::size_t k, std::shared_ptr<EdgeConsistencyPrecomputation> precomputed) :
            IntroduceHandler(n, k), precomputed_(std::move(precomputed)) {};
    std::vector<std::size_t>& Introduce(std::vector<std::size_t> &input, std::vector<std::size_t> &output,
                                   std::vector<unsigned char>& bag, std::size_t x, std::size_t idx) override;
private:
    std::shared_ptr<EdgeConsistencyPrecomputation> precomputed_;
};

#endif