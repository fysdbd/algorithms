
/*
    Topological Sorting

    description(lintcode
                http://www.lintcode.com/en/problem/topological-sorting/
                )

    Given an directed graph, a topological order of the graph nodes is defined as follow:

    For each directed edge A -> B in graph, A must before B in the order list.
    The first node in the order can be any node in the graph with no nodes direct to it.
    Find any topological order for the given graph.

    You can assume that there is at least one topological order in the graph.


    notes:

    following is the solution to this classical problem by adopting breadth-first-search(bfs)

*/


/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */


class Solution {
public:
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {

        map<DirectedGraphNode*, int> prerequisites;
        for (auto node : graph) { prerequisites[node] = 0; }
        vector<DirectedGraphNode*> actives, next_batch, result;

        // create our needed lookup directionary of "pre-requisites"
        for (auto node : graph) {
            for (auto neighbor : node->neighbors) {
                prerequisites[neighbor]++;
            }
        }

        // initial batch
        for (auto node : graph) {
            if (prerequisites[node] == 0) {
                actives.push_back(node);
                result.push_back(node);
            }
        }

        // propogation
        while (!actives.empty()) {
            for (auto active : actives) {
                for (auto neighbor : active->neighbors) {
                    if (--prerequisites[neighbor] == 0) {
                        next_batch.push_back(neighbor);
                        result.push_back(neighbor);
                    }
                }
            }
            actives = next_batch;
            next_batch.clear();
        }

        return result;
    }
};

