#ifndef HOMOMORPHISM_GRAPH_H_
#define HOMOMORPHISM_GRAPH_H_

#include <memory>
#include <set>
#include <string>
#include <unordered_set>

class Graph
{
public:
    virtual size_t vertCount() = 0;
    virtual size_t edgeCount() = 0;
    virtual void addEdge(size_t u, size_t v) = 0;
    virtual bool edgeExist(size_t u, size_t v) = 0;
    virtual std::unordered_set<size_t> getNeighbourhood(size_t v) = 0;
    virtual bool isIsomorphic(std::shared_ptr<Graph> g) = 0;
    virtual std::shared_ptr<Graph> partition(std::set<size_t>* parts, size_t size) = 0;
    
    std::string toString();
    std::string toGr();
    std::string toGraph6();
    void prettyPrint(std::ostream& os);
};

#endif
