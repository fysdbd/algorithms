
/*
    Search Graph Nodes

    description(lintcode
                http://www.lintcode.com/en/problem/search-graph-nodes/


    Given a undirected graph, a node and a target,
    return the nearest node with given node which value is target, return NULL if can't find.
    There is hash mapping about nodes and their values.
    It's guaranteed there is only one available solution

    notes:
*/


/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    /**
     * @param graph a list of Undirected graph node
     * @param values a hash mapping, <UndirectedGraphNode, (int)value>
     * @param node an Undirected graph node
     * @param target an integer
     * @return the a node
     */
    UndirectedGraphNode* searchNode(vector<UndirectedGraphNode*>& graph,
                                    map<UndirectedGraphNode*, int>& values,
                                    UndirectedGraphNode* node,
                                    int target) {
        
        queue<UndirectedGraphNode*> searchlist;
        map<UndirectedGraphNode*, bool> visited;
        
        searchlist.push(node);
        for (auto curr : graph) { visited.emplace(curr, curr == node); }
        
        while (!searchlist.empty()) {
            auto curr = searchlist.front(); searchlist.pop();
            if (values[curr] == target) { return curr; }
            for (auto neighbor : curr->neighbors) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    searchlist.push(neighbor);
                }
            }
        }
        
        return nullptr;
    }
};

