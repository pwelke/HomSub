#include "homomorphism/introduce_handler_precomputed.h"

std::vector<std::size_t>& IntroduceHandlerPrecomputed::Introduce(std::vector<std::size_t> &input, std::vector<std::size_t> &output,
        std::vector<unsigned char> &bag, std::size_t x, std::size_t idx) {
    if(idx == 0) {
        return least_.Introduce(input, output, bag, x, idx);
    } else if(bag[0]) {
        return edge_.Introduce(input, output, bag, x, idx);
    } else {
        return nonedge_.Introduce(input, output, bag, x, idx);
    }
}

