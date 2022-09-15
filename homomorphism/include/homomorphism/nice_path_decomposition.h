#ifndef HOMOMORPHISM_NICE_PATH_DECOMPOSITION_H
#define HOMOMORPHISM_NICE_PATH_DECOMPOSITION_H

#include <utility>

#include "homomorphism/tree_decomposition.h"

struct NPDNode {
    bool introduce;
    std::size_t vertex;
    //std::size_t index;
    //std::vector<std::size_t> bag;
};

class NicePathDecomposition
{
public:
    NicePathDecomposition(std::vector<NPDNode> decomp, std::size_t width) :
        decomposition_(std::move(decomp)), width_(width) {};
    static std::shared_ptr<NicePathDecomposition> FromTd(std::shared_ptr<TreeDecomposition> td);
    std::size_t getWidth();

    std::vector<NPDNode> decomposition_;
private:
    std::size_t width_;
};



#endif
