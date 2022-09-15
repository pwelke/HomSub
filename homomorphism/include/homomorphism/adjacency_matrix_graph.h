#ifndef HOMOMORPHISM_ADJACENCY_MATRIX_GRAPH_H_
#define HOMOMORPHISM_ADJACENCY_MATRIX_GRAPH_H_

#include "homomorphism/graph.h"

#include <memory>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

typedef std::vector<unsigned char> Matrix;

class AdjacencyMatrixGraph : public Graph
{
public:
    AdjacencyMatrixGraph(std::size_t v) : vertices_(v), edges_(0), matrix_(Matrix(v * v, 0)) { };
    AdjacencyMatrixGraph(std::size_t v, std::size_t e) : vertices_(v), edges_(e), matrix_(Matrix(v * v,  0 )) { };
    AdjacencyMatrixGraph(std::size_t v, std::size_t e, Matrix a) : vertices_(v), edges_(e), matrix_(a) { };
    
    static std::shared_ptr<AdjacencyMatrixGraph> fromGraph6(std::string graph6, bool includeG);
    static std::shared_ptr<AdjacencyMatrixGraph> fromFile(std::string path);
    static std::shared_ptr<AdjacencyMatrixGraph> testGraph();
    static std::shared_ptr<AdjacencyMatrixGraph> parseNautyFormat(const std::string& nauty, std::size_t n);
    static std::shared_ptr<AdjacencyMatrixGraph> FromGraph(std::shared_ptr<Graph> gr);
    
    void clear(std::size_t v) override;
    std::size_t vertCount() override;
    std::size_t edgeCount() override;
    void addEdge(std::size_t u, std::size_t v) override;
    bool edgeExist(std::size_t u, std::size_t v) override;
    std::unordered_set<std::size_t> getNeighbourhood(std::size_t v) override;
    bool isIsomorphic(std::shared_ptr<Graph> g) override;
    std::shared_ptr<Graph> partition(std::set<std::size_t>* parts, std::size_t size) override;
    std::vector<unsigned char>::iterator GetRowIterator(std::size_t row);

private:
    std::size_t vertices_;
    std::size_t edges_;
    Matrix matrix_;

    bool isIsomorphism(std::shared_ptr<Graph> g, std::size_t* permutation);
};

#endif 
