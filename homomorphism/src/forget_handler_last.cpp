#include "homomorphism/forget_handler_last.h"

#include <iostream>

std::vector<std::size_t>& ForgetHandlerLast::forget(std::vector<std::size_t>& input, std::vector<std::size_t>& output,
                                               std::size_t b, std::size_t idx) {
    if(idx != 0) {
        std::cerr << "ERROR: ForgetHandlerLast called with index " << idx << " and bag size " << b << std::endl;
        throw;
    }

    std::size_t offset = 0;

    for(std::size_t & i : output) {
        std::size_t result = 0;

        for(std::size_t j = 0; j < size_.n; j++) {
            result += input[offset + j];
        }

        i = result;
        offset += size_.n;
    }

    return output;
}

