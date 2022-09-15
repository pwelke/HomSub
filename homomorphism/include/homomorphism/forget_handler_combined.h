#ifndef HOMOMORPHISM_FORGET_HANDLER_COMBINED_H
#define HOMOMORPHISM_FORGET_HANDLER_COMBINED_H

#include "homomorphism/forget_handler_any.h"
#include "homomorphism/forget_handler_first.h"
#include "homomorphism/forget_handler_last.h"

class ForgetHandlerCombined : public ForgetHandler {
public:
    ForgetHandlerCombined(std::size_t n, std::size_t k) : ForgetHandler(n, k), any_(ForgetHandlerAny(n, k)),
                    last_(ForgetHandlerFirst(n, k)), first_(ForgetHandlerLast(n, k)) {}
    std::vector<std::size_t>& forget(std::vector<std::size_t>& input, std::vector<std::size_t>& output, std::size_t b, std::size_t idx) override;
private:
    ForgetHandlerAny any_;
    ForgetHandlerLast first_;
    ForgetHandlerFirst last_;
};

#endif
