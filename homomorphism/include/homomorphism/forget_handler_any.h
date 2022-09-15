#ifndef HOMOMORPHISM_FORGET_HANDLER_ANY_H
#define HOMOMORPHISM_FORGET_HANDLER_ANY_H

#include "homomorphism/forget_handler.h"

class ForgetHandlerAny : public ForgetHandler {
public:
    ForgetHandlerAny(std::size_t n, std::size_t k) : ForgetHandler(n, k) {}
    std::vector<std::size_t>& forget(std::vector<std::size_t>& input, std::vector<std::size_t>& output, std::size_t b, std::size_t idx) override;
};


#endif
