#include "homomorphism/forget_handler_first.h"

#include <iostream>

std::vector<std::size_t>& ForgetHandlerFirst::forget(std::vector<std::size_t>& input, std::vector<std::size_t>& output,
                                                    std::size_t b, std::size_t idx) {
    if(idx !=  b - 1) {
        std::cerr << "ERROR: ForgetHandlerFirst called with index " << idx << std::endl;
        throw;
    }

    for(std::size_t i = 0; i < output.size(); i++) {
        output[i] = input[i];
    }

    std::size_t offset = output.size();

    for(int i = 1; i < size_.n; i++) {
        for (std::size_t idx = 0; idx < output.size(); idx++) {
            output[idx] += input[offset + idx];
        }
        offset += output.size();
    }

    return output;
}

