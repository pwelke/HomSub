#include "homomorphism/tree_decomposition.h"

#include <iostream>
#include <sstream>

std::shared_ptr<TreeDecomposition> TreeDecomposition::parseTd(std::istream& input) {
    std::string line;
    do {
        if(!std::getline(input, line)) return nullptr;
    } while (line[0] == 'c');
    std::size_t bagN, width, n;
    if (!std::sscanf(line.c_str(), "s td %zd %zd %zd", &bagN, &width, &n)) return nullptr;
    width--;
    //TODO: Specific Graph. Maybe this should be generic
    std::shared_ptr <EdgeSetGraph> G = std::make_shared<EdgeSetGraph>(bagN);
 
    std::vector<std::unordered_set<std::size_t>> bags;
    bags.resize(bagN);
    for(std::size_t i = 0; i < bagN; i++) {
        int bagI = -1;
        getline(input, line);
        std::stringstream ss;
        ss << line;
        std::string temp;
        while(!ss.eof())
        {
            ss >> temp;
            
            if(std::stringstream(temp) >> n)
            {
                if(bagI < 0) bagI = n - 1;
                else bags[bagI].insert(n);
            }
            
            temp="";
        }
        bagI = -1;
    }
    std::size_t u, v, edges = bagN - 1;
    while (edges && getline(input, line)) {
        if (line.empty() || line[0] == 'c') continue;
        if (!std::sscanf(line.c_str(), "%zd %zd", &u, &v)) {
            return nullptr;
        }

        edges--;
        G->addEdge(u - 1, v - 1);
    }
    return std::make_shared<TreeDecomposition>(G, bags, width);
}

std::string TreeDecomposition::toTd() 
{
    std::ostringstream str;
    str << "s td " << bags.size() << " " << (width_ + 1) << " " << graph->vertCount() << "\n";

    for (std::size_t i = 0; i < bags.size(); i++)
    {
        str << "b " << (i + 1);

        for (const auto& idx : bags[i]) {
            str << " " << idx;
        }

        str << "\n";
    }

    for (std::size_t u = 0; u < graph->vertCount(); u++)
    {
        for (std::size_t v = u + 1; v < graph->vertCount(); v++)
        {
            if (graph->edgeExist(u, v)) {
                str << (u + 1) << " " << (v + 1) << "\n";
            }
        }
    }

    return str.str();
}

bool TreeDecomposition::IsPathDecomposition() {
    for(auto & v : graph->getNeighbourList()) {
        if(v.size() > 2) {
            return false;
        }
    }
    return true;
}

std::shared_ptr<EdgeSetGraph> TreeDecomposition::getGraph()
{
    return graph;
}

std::unordered_set<std::size_t> TreeDecomposition::getBag(std::size_t bag)
{
    return bags[bag];
}

std::size_t TreeDecomposition::getWidth()
{
    return width_;
}
