#include "homomorphism/tree_decomposition.h"

#include <iostream>
#include <sstream>

std::shared_ptr<TreeDecomposition> TreeDecomposition::parseTd(std::istream& input) {
    std::string line;
    do {
        if(!std::getline(input, line)) return nullptr;
    } while (line[0] == 'c');
    size_t bagN, width, n;
    if (!std::sscanf(line.c_str(), "s td %zd %zd %zd", &bagN, &width, &n)) return nullptr;
    //TODO: Specific Graph. Maybe this should maybe be generic
    std::shared_ptr <EdgeSetGraph> G = std::make_shared<EdgeSetGraph>(n);
 
    std::vector<std::unordered_set<size_t>> bags;
    bags.resize(bagN);
    for(size_t i = 0; i < bagN; i++) {
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
    size_t u, v, edges = bagN - 1;
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
    str << "s td " << bags.size() << " " << width_ << " " << graph->vertCount() << "\n";

    for (size_t i = 0; i < bags.size(); i++)
    {
        str << "b " << (i + 1);

        for (const auto& idx : bags[i]) {
            str << " " << idx;
        }

        str << "\n";
    }

    for (size_t u = 1; u < graph->vertCount(); u++)
    {
        for (size_t v = 0; v < u; v++)
        {
            if (graph->edgeExist(u, v)) {
                str << (u + 1) << " " << (v + 1) << "\n";
            }
        }
    }

    return str.str();
}

std::shared_ptr<EdgeSetGraph> TreeDecomposition::getGraph()
{
    return graph;
}

std::unordered_set<size_t> TreeDecomposition::getBag(size_t bag)
{
    return bags[bag];
}

size_t TreeDecomposition::getWidth()
{
    return width_;
}
