#ifndef HOMOMORPHISM_EDGE_SET_GRAPH_H_
#define HOMOMORPHISM_EDGE_SET_GRAPH_H_

#include <memory>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

#include "homomorphism/graph.h"

class EdgeSetGraph : public Graph {
 public:
    explicit EdgeSetGraph(std::size_t verts) : verts_(verts), edges_(0) {
        neighbours_.resize(verts);
    }
    EdgeSetGraph(std::size_t verts,
                 std::size_t edges,
                 const std::vector<std::unordered_set<std::size_t>> &neighbours)
        : verts_(verts), edges_(edges), neighbours_(neighbours) {}
    static std::shared_ptr<EdgeSetGraph> FromGraph(std::shared_ptr<Graph> g);
    void clear(std::size_t v) override;
    std::size_t vertCount() override;
    std::size_t edgeCount() override;
    static std::shared_ptr<EdgeSetGraph> fromFile(std::string path);
    static std::shared_ptr<EdgeSetGraph> parseGr(std::ifstream& input);
    void addEdge(std::size_t u, std::size_t v) override;
    bool edgeExist(std::size_t u, std::size_t v) override;
    std::unordered_set<std::size_t> getNeighbourhood(std::size_t v) override;
    bool isIsomorphic(std::shared_ptr<Graph> g) override;
    std::shared_ptr<Graph> partition(std::set<std::size_t>* parts, std::size_t size) override;
    std::vector<std::unordered_set<std::size_t>> getNeighbourList();

 private:
    std::size_t verts_;
    std::size_t edges_;
    std::vector<std::unordered_set<std::size_t>> neighbours_;
};

#endif
