#include "homomorphism/forget_handler_any.h"

std::vector<std::size_t>& ForgetHandlerAny::forget(std::vector<std::size_t> &input, std::vector<std::size_t> &output,
        std::size_t b, std::size_t idx) {
    // Since index and exponents are inverted. If this is changed this line should be removed.
    std::size_t pos = idx;
    std::size_t xMax = size_.sizes[pos];
    std::size_t yMax = size_.sizes[b - pos - 1];
    std::size_t zMax = size_.n;

    std::size_t xOff = size_.n;
    std::size_t yOff = size_.sizes[pos + 1];
    std::size_t zOff = size_.sizes[pos];

    for(std::size_t & entry : output) {
        entry = 0;
    }

    for (std::size_t y = 0; y < yMax; ++y) {
        for (std::size_t z = 0; z < zMax; ++z) {
            for (std::size_t x = 0; x < xMax; ++x) {
                output[x + zOff * y] += input[x + yOff * y + zOff * z];
            }
        }
    }

    return output;
}
