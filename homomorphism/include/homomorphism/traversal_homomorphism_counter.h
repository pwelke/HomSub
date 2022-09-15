#ifndef TRAVERSAL_HOMOMORPHISM_COUNTER_H
#define TRAVERSAL_HOMOMORPHISM_COUNTER_H

#include <memory>
#include <unordered_set>
#include <vector>

#include "homomorphism/edge_set_graph.h"

class TraversalHomomorphismCounter {
 public:
    static int64_t Count(std::shared_ptr<EdgeSetGraph> h, std::shared_ptr<EdgeSetGraph> g);
 private:
    static bool CheckHomomorphism(std::shared_ptr<EdgeSetGraph> h,
                                  std::shared_ptr<EdgeSetGraph> g,
                                  std::vector<std::size_t> hTraversal,
                                  std::vector<std::size_t> gTraversal);
    static int64_t TestKTraversals(std::shared_ptr<EdgeSetGraph> h,
                                   std::shared_ptr<EdgeSetGraph> g,
                                   std::vector<std::size_t> hTraversal,
                                   std::vector<std::size_t> gTraversal);
    static std::vector<std::size_t> GetFirstTraversal(std::shared_ptr<EdgeSetGraph> g);
    static std::unordered_set<std::size_t> GetOpenNeighbourhood(std::shared_ptr<EdgeSetGraph> g,
                                                           std::vector<std::size_t> verts);
};


#endif /* traversal_homomorphism_counter_h */
