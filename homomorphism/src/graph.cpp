#include "homomorphism/graph.h"

#include <bitset>
#include <sstream>

#include "homomorphism/graph6helper.h"

std::string Graph::toGraph6(bool includeG) {
    std::ostringstream str;
    if(includeG) {
        str << "G";
    }
    str << Graph6helper::N(vertCount());
    std::bitset<6> buffer;
    int idx = 6;
    for (std::size_t u = 1; u < vertCount(); u++)
    {
        for (std::size_t v = 0; v < u; v++)
        {
            buffer.set(--idx, edgeExist(u, v));
            if (!idx) {
                str << Graph6helper::R(buffer.to_ulong());
                idx = 6;
            }
        }
    }

    if (idx != 6) {
        while (idx) {
            buffer.set(--idx, false);
        }
        str << Graph6helper::R(buffer.to_ulong());
    }

    return str.str();
}

std::string Graph::toGr() 
{
    std::ostringstream str;
    str << "p tw " << vertCount() << " " << edgeCount() << "\n";
    
    // Add edges in lexicographic order
    for (std::size_t u = 0; u < vertCount() - 1; u++)
    {
        for (std::size_t v = u + 1; v < vertCount(); v++)
        {
            if (edgeExist(u, v)) {
                str << u + 1 << " " << v + 1 << "\n";
            }
        }
    }

    return str.str();
}

std::string Graph::toString()
{
    std::ostringstream out;
    out << "Graph of size (" << vertCount() << "," << edgeCount() << ")";
    return out.str();
}

void Graph::prettyPrint(std::ostream& os)
{
    os << "Graph with " << vertCount() << " vertices and " << edgeCount() << " edges:\n";
    for (std::size_t u = 0; u < vertCount(); u++) {
        os << "[ ";
        for (std::size_t v = 0; v < vertCount(); v++) {
            os << edgeExist(u, v) << " ";
        }
        os << "]" << std::endl;
    }
}

std::string Graph::toNautyFormat() {
    std::ostringstream str;
    
    for (std::size_t u = 0; u < vertCount(); u++) {
        for (std::size_t v = u + 1; v < vertCount(); v++) {
            if (edgeExist(u, v)) {
                str << " " << v;
            }
        }
        str << " ; ";
    }

    return str.str();
}

std::string Graph::partitionNauty(std::set<std::size_t>* parts, std::size_t size) {
    std::ostringstream str;

    bool edgeFound;
    std::set<std::size_t>::iterator uit, uend, vit, vend;

    for(std::size_t u = 0; u < size; u++)
    {
        uend = parts[u].end();

        for (std::size_t v = u + 1; v < size; v++)
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
                str << " " << v;
            }
        }

        str << " ; ";
    }

    return str.str();
}
