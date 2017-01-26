
/*
    Clone Graph

    decription(leetcode
	       https://leetcode.com/problems/clone-graph/
	       )


    Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
    How we serialize an undirected graph:
    Nodes are labeled uniquely.
    We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
    As an example, consider the serialized graph {0,1,2#1,2#2,2}.
    The graph has a total of three nodes, and therefore contains three parts as separated by #.

    First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
    Second node is labeled as 1. Connect node 1 to node 2.
    Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
    Visually, the graph looks like the following:

	   1
	  / \
	 /   \
	0 --- 2
	     / \
	     \_/


    notes:
*/


/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {

        if (node == nullptr) { return nullptr; }
        UndirectedGraphNode* result = new UndirectedGraphNode(node->label);

        // state variables to maintain during cloning
        std::map<UndirectedGraphNode*, UndirectedGraphNode*> old_to_new = {{node, result}};
        std::queue<UndirectedGraphNode*> to_clone; to_clone.push(node);

        while (!to_clone.empty()) {
            auto clone_target = to_clone.front(); to_clone.pop();
            auto cloned = old_to_new[clone_target];
            for (auto neighbor : clone_target->neighbors) {
                // if this is an unseen node, register it first
                if (old_to_new.find(neighbor) == old_to_new.end()) {
                    UndirectedGraphNode* new_node = new UndirectedGraphNode(neighbor->label);
                    old_to_new.emplace(neighbor, new_node);
                    to_clone.push(neighbor);
                }
                cloned->neighbors.push_back(old_to_new[neighbor]);
            }
        }

        return result;
    }
};

