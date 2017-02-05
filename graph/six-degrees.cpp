
/*
    Six Degrees

    description(lintcode
                http://www.lintcode.com/en/problem/six-degrees/
                )

    Six degrees of separation is the theory that everyone and everything is six or fewer steps away, by way of introduction, from any other person in the world, so that a chain of "a friend of a friend" statements can be made to connect any two people in a maximum of six steps.

    Given a friendship relations, find the degrees of two people, return -1 if they can not been connected by friends of friends.

    Example
    Gien a graph:

    1------2-----4
     \          /
      \        /
       \--3--/
    {1,2,3#2,1,4#3,1,4#4,2,3} and s = 1, t = 4 return 2

    Given a graph:

    1      2-----4
                 /
               /
              3
    {1#2,4#3,4#4,2,3} and s = 1, t = 4 return -1

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
    /**
     * @param graph a list of Undirected graph node
     * @param s, t two Undirected graph nodes
     * @return an integer
     */
    int sixDegrees(vector<UndirectedGraphNode*> graph,
                   UndirectedGraphNode* s,
                   UndirectedGraphNode* t) {
        
        if (s == t) { return 0; }

        // state variables
        std::queue<UndirectedGraphNode*> q; q.push(s);
        map<UndirectedGraphNode*, int> dist; dist[s] = 0;
        
        while (!q.empty()) {
            auto curr = q.front(); q.pop();

            for (auto neighbor : curr->neighbors) {
                if (neighbor == t) { return dist[curr]+1; }
                if (dist.find(neighbor) == dist.end()) { // new node
                    dist[neighbor] = dist[curr]+1;
                    q.push(neighbor);
                }
            }
        }

        return -1;
    }
};

