
#include <iostream>
#include <fstream>
#include <sstream>
#include "homomorphism/graph.h"
#include <sstream>

std::shared_ptr<Graph> Graph::fromGraph6(std::string graph6) {
    return testGraph();
}

bool has_suffix(const std::string& str, const std::string& suffix)
{
    return str.size() >= suffix.size() &&
        str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

void Graph::addEdge(size_t u, size_t v) {
    if (!matrix_[u * vertices_ + v]) edges_++;
    matrix_[u * vertices_ + v] = true;
    matrix_[v * vertices_ + u] = true;
}

std::shared_ptr<Graph> parseGr(std::ifstream& input) {
    std::string line;
    do {
        if(!std::getline(input, line)) return nullptr;
    } while (line[0] == 'c');
    
    size_t n, m;
    if (!std::sscanf(line.c_str(), "p tw %zd %zd", &n, &m)) return nullptr;
    std::shared_ptr <Graph> G = std::make_shared<Graph>(n);

    size_t u, v;
    while (getline(input, line)) {
        if (line.empty() || line[0] == 'c') continue;

        if (!std::sscanf(line.c_str(), "%zd %zd", &u, &v)) return nullptr;

        G->addEdge(u - 1, v - 1);
    }

    return G;
}

std::shared_ptr<Graph> Graph::fromFile(std::string path) {
    std::ifstream input (path);
    
    if (input.is_open()) {
        if (has_suffix(path, ".gr")) {
            return parseGr(input);
        }
        else {
            std::cerr << "ERROR: Unknown graph format for file " << path 
                << "\n Current supported formats are: .gr" << std::endl;
            return nullptr;
        }
    }
    else {
        std::cerr << "ERROR: Unable to open file: " << path << std::endl;
        return nullptr;
    }
}

std::shared_ptr<Graph> Graph::testGraph()
{
    size_t v = 4;
    size_t e = 5;
    return std::make_shared<Graph>(v, e);
}

bool Graph::edgeExist(size_t u, size_t v)
{
    return matrix_[u * vertices_ + v];
}

bool Graph::isIsomorphic(std::shared_ptr<Graph> g)
{
    //TODO: implement
    return false;
}

size_t Graph::vertCount()
{
    return vertices_;
}

size_t Graph::edgeCount()
{
    return edges_;
}

std::string Graph::toString()
{
    std::ostringstream out;
    out << "Graph of size (" << vertices_ << "," << edges_ << ")";
    return out.str();
}

std::string Graph::toGraph6()
{
    //TODO: implement
    return "";
}

std::shared_ptr<Graph> Graph::partition(std::set<size_t>* parts, size_t size) {
    std::shared_ptr<Graph> newGraph = std::make_shared<Graph>(size);

    bool edgeFound;
    std::set<size_t>::iterator uit, uend, vit, vend;

    for(size_t u = 0; u < size; u++)
    {
        uend = parts[u].end();
        
        for (size_t v = u + 1; v < size; v++)
        {
            edgeFound = false;
            uit = parts[u].begin();
            vend = parts[v].end();

            while (!edgeFound && uit != uend) {
                vit = parts[v].begin();

                while (vit != vend) {
                    if (edgeExist(*uit, *vit)) {
                        edgeFound = true;
                        break;
                    }
                    vit++;
                }
                uit++;
            }

            if (edgeFound) {
                newGraph->addEdge(u, v);
            }
        }
    }

    return newGraph;
}

void Graph::prettyPrint(std::ostream& os) 
{
    os << "Graph with " << vertices_ << " vertices and " << edges_ << " edges:\n";
    for (size_t u = 0; u < vertices_; u++) {
        os << "[ ";
        for (size_t v = 0; v < vertices_; v++) {
            os << edgeExist(u, v) << " ";
        }
        os << "]" << std::endl;
    }
}

