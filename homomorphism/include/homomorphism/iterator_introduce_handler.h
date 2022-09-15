#ifndef HOMOMORPHISM_ITERATOR_INTRODUCE_HANDLER_H
#define HOMOMORPHISM_ITERATOR_INTRODUCE_HANDLER_H

#include "homomorphism/introduce_handler_least.h"

class IteratorIntroduceHandler : public IntroduceHandlerLeast {
public:
    std::vector<std::size_t>& introduceLast(std::vector <std::size_t> &input, std::vector <std::size_t> &output,
                                               std::vector <std::size_t>& bag, std::shared_ptr<Graph> h,
                                               std::shared_ptr<Graph> g, std::size_t n, std::size_t x) override;
};

#endif
