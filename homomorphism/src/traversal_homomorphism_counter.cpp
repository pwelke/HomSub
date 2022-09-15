#include "homomorphism/traversal_homomorphism_counter.h"
#include <unordered_set>
#include <algorithm>
#include <stdio.h>


bool TraversalHomomorphismCounter::CheckHomomorphism(std::shared_ptr<EdgeSetGraph> h, std::shared_ptr<EdgeSetGraph> g, std::vector<std::size_t> hTraversal, std::vector<std::size_t> gTraversal) {
    int k = hTraversal.size();
    
    //Create mapping
    std::vector<std::size_t> mapping(k, 0);
    for(int i = 0; i < k; i++) {
        mapping[hTraversal[i]] = gTraversal[i];
    }
    
    //For all verts in h
    for(int i = 0; i < k; i++) {
        //Check that edges in mapping er preserved
        for(std::size_t nei : h->getNeighbourhood(i)) {
            if(!g->edgeExist(mapping[i], mapping[nei])) {
                return false;
            }
        }
    }
    
    return true;
}

long TraversalHomomorphismCounter::Count(std::shared_ptr<EdgeSetGraph> h, std::shared_ptr<EdgeSetGraph> g) {
    long result = TestKTraversals(h, g, GetFirstTraversal(h), std::vector<std::size_t>());
    
    return result;
}

long TraversalHomomorphismCounter::TestKTraversals(std::shared_ptr<EdgeSetGraph> h, std::shared_ptr<EdgeSetGraph> g, std::vector<std::size_t> hTraversal, std::vector<std::size_t> gTraversal)
{
    //These choices contain the open neighbourhood
    std::unordered_set<std::size_t> choices;
    choices.clear();
    
    if(gTraversal.size() == 0) {
        //Add all verts to first choice
        for(int i = 0; i < g->vertCount(); i++) {
            choices.insert(i);
        }
    } else {
        //Add open neighbourhood
        choices = GetOpenNeighbourhood(g, gTraversal);
        for(std::size_t v : gTraversal) {
            choices.insert(v);
        }
    }
    
    //try each available choice
    long result = 0;
    for(std::size_t choice : choices) {
        std::vector<std::size_t> withChoice = gTraversal;
        withChoice.push_back(choice);

        if(withChoice.size() == h->vertCount()) {
            if(CheckHomomorphism(h, g, hTraversal, withChoice)) result++;
        } else {
            result += TestKTraversals(h, g, hTraversal, withChoice);//Recurse if still not finished
        }
    }
    return result;
}

std::vector<std::size_t> TraversalHomomorphismCounter::GetFirstTraversal(std::shared_ptr<EdgeSetGraph> g)
{
    std::vector<std::size_t> traversal {0};
    for(int i = 1; i < g->vertCount(); i++) {
        std::unordered_set<std::size_t> on = GetOpenNeighbourhood(g, traversal);
        for(std::size_t v : on) {
            if(std::find(traversal.begin(), traversal.end(), v) == traversal.end()) {
                traversal.push_back(v);
                break;
            }
        }
        
    }
    return traversal;
}

std::unordered_set<std::size_t> TraversalHomomorphismCounter::GetOpenNeighbourhood(std::shared_ptr<EdgeSetGraph> g, std::vector<std::size_t> verts)
{
    std::unordered_set<std::size_t> on;
    on.clear();
    
    for(std::size_t v : verts) {
        for(std::size_t vn : g->getNeighbourhood(v)) {
            on.insert(vn);
        }
    }
    
    return on;
}
