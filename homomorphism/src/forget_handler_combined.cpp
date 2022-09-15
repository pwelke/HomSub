#include "homomorphism/forget_handler_combined.h"

std::vector<std::size_t>& ForgetHandlerCombined::forget(std::vector<std::size_t> &input, std::vector<std::size_t> &output,
                                                        std::size_t b, std::size_t idx) {
    if (idx == 0) {
        return first_.forget(input, output, b, idx);
    } else if (idx == b - 1) {
        return last_.forget(input, output, b, idx);
    } else {
        return any_.forget(input, output, b, idx);
    }
}
