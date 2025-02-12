#include "homomorphism/edge_consistency_precomputation.h"

#include "homomorphism/adjacency_matrix_graph.h"

std::shared_ptr<EdgeConsistencyPrecomputation> EdgeConsistencyPrecomputation::InitializeLeast(std::shared_ptr<Graph> gr, int maxEdges) {
    std::vector<std::vector<unsigned char>> storage;
    std::size_t n = gr->vertCount();

    // AdjacencyMatrixGraph is preferred to simplify inner loop
    auto g = std::dynamic_pointer_cast<AdjacencyMatrixGraph>(gr);
    if(g == nullptr) {
        g = AdjacencyMatrixGraph::FromGraph(gr);
    }

    storage.emplace_back(n, 1);

    for(int e = 0; e < maxEdges; e++) {
        storage.emplace_back((*storage.rbegin()).size() * n);

        auto prev = storage.rbegin() + 1;

        auto nextIt = storage.rbegin()->begin();

        for(int idx = 0; idx < n; idx++) {
            auto prevIt = prev->begin();
            while(prevIt != prev->end()) {
                auto row = g->GetRowIterator(idx);
                for (int i = 0; i < n; ++i) {
                    *(nextIt++) = *(prevIt++) * *(row++);
                }
            }
        }
    }

    return std::make_shared<EdgeConsistencyPrecomputation>(storage);
}

std::shared_ptr<EdgeConsistencyPrecomputation> EdgeConsistencyPrecomputation::InitializeSecond(std::shared_ptr<Graph> g, int maxEdges) {
    std::vector<std::vector<unsigned char>> storage;
    std::size_t n = g->vertCount();

    storage.emplace_back(n, 1);

    // Add first vector
    storage.emplace_back(n * n);
    auto nextIt = storage.rbegin()->begin();
    auto prev = storage.rbegin() + 1;

    for(int idx = 0; idx < n; idx++) {
        auto prevIt = prev->begin();
        while(prevIt != prev->end()) {
            for (int i = 0; i < n; ++i) {
                *(nextIt++) = *(prevIt++) * g->edgeExist(idx, i);
            }
        }
    }

    for(int e = 1; e < maxEdges; e++) {
        storage.emplace_back(storage.rbegin()->size() * n);

        nextIt = storage.rbegin()->begin();

        prev = storage.rbegin() + 1;

        for(int idx = 0; idx < n; idx++) {
            auto prevIt = prev->begin();
            while(prevIt != prev->end()) {
                for (int i = 0; i < n; ++i) {
                    if(g->edgeExist(idx, i)) {
                        std::copy(prevIt, prevIt + n, nextIt);
                    } else {
                        std::fill(nextIt, nextIt + n, 0);
                    }
                    nextIt += n;
                    prevIt += n;
                }
            }
        }
    }

    return std::make_shared<EdgeConsistencyPrecomputation>(storage);
}

std::vector<unsigned char>::iterator EdgeConsistencyPrecomputation::GetIterator(std::size_t edges) {
    return storage_[edges].begin();
}
