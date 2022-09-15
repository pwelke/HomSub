#ifndef HOMOMORPHISM_GRAPH_H_
#define HOMOMORPHISM_GRAPH_H_

#include <memory>
#include <set>
#include <string>
#include <unordered_set>

class Graph
{
public:
    virtual std::size_t vertCount() = 0;
    virtual std::size_t edgeCount() = 0;
    virtual void addEdge(std::size_t u, std::size_t v) = 0;
    virtual bool edgeExist(std::size_t u, std::size_t v) = 0;
    virtual std::unordered_set<std::size_t> getNeighbourhood(std::size_t v) = 0;
    virtual bool isIsomorphic(std::shared_ptr<Graph> g) = 0;
    virtual std::shared_ptr<Graph> partition(std::set<std::size_t>* parts, std::size_t size) = 0;
    virtual void clear(std::size_t v) = 0;
    virtual std::string toNautyFormat();
    
    std::string toString();
    std::string toGr();
    std::string toGraph6(bool includeG);
    void prettyPrint(std::ostream& os);
    std::string partitionNauty(std::set<std::size_t>* parts, std::size_t size);
};

#endif
