#ifndef NICE_TREE_DECOMPOSITIOM_H_
#define NICE_TREE_DECOMPOSITIOM_H_

#include <memory>
#include <vector>

#include "tree_decomposition.h"

enum NTDNodeType { JOIN, FORGET, INTRODUCE, LEAF};

struct NTDNode {
    NTDNodeType nodeType;
    std::size_t vertex;
    std::shared_ptr<NTDNode> left;
    std::shared_ptr<NTDNode> right;
};

class NiceTreeDecomposition
{
public:
    NiceTreeDecomposition(std::shared_ptr<NTDNode> r, std::shared_ptr<Graph> g, std::size_t width) : root_(r), graph_(g), width_(width) {};
    static std::shared_ptr<NiceTreeDecomposition> FromTd(std::shared_ptr<TreeDecomposition> td);
    std::shared_ptr<NTDNode> getRoot();
    static void print(std::shared_ptr<NTDNode> node);
    std::size_t getWidth();
private:
    std::shared_ptr<NTDNode> root_;
    std::shared_ptr<Graph> graph_;
    std::size_t width_;
    static std::shared_ptr<NTDNode> convertNode(std::size_t from, std::size_t node, std::shared_ptr<TreeDecomposition> td);
    static std::shared_ptr<NTDNode> connectToChild(std::shared_ptr<NTDNode> childNode, std::unordered_set<std::size_t> childBag, std::unordered_set<std::size_t> parentBag);
    static std::shared_ptr<NTDNode> createLeaf();
    static std::shared_ptr<NTDNode> createIntroduce(std::shared_ptr<NTDNode> child, std::size_t vert);
    static std::shared_ptr<NTDNode> createForget(std::shared_ptr<NTDNode> child, std::size_t vert);
    static std::shared_ptr<NTDNode> createJoin(std::shared_ptr<NTDNode> leftChild, std::shared_ptr<NTDNode> rightChild);
};

#endif 
