#include "homomorphism/join_handler.h"

std::vector<std::size_t> & JoinHandler::join(std::vector<std::size_t> &first, std::vector<std::size_t> &second) {
    for (std::size_t i = 0; i < first.size(); ++i) {
        first[i] *= second[i];
    }

    return first;
}