
/*
    Graph Valid Tree

    description(lintcode
                http://www.lintcode.com/en/problem/graph-valid-tree/
                )

    Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

    You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

    Example
    Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.
    Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

*/

class Solution {
public:
    /**
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.empty()) { return n == 1; }

        vector<vector<bool>> adjmatrix(n, vector<bool>(n, false));
        for (auto edge : edges) {
            adjmatrix[edge[0]][edge[1]] = true;
            adjmatrix[edge[1]][edge[0]] = true;
        }

        // state variables to maintain
        vector<bool> stepped(n, false); stepped[0] = true;
        vector<int> prevs(n);
        queue<int> q; q.push(0);
        int cnt = 1;

        while (!q.empty()) {
            auto curr = q.front(); q.pop();
            for (int adj = 0; adj < n; adj++) {
                if (adj == curr || !adjmatrix[curr][adj]) { continue; }

                // case1 : it is a new node
                if (!stepped[adj])  {
                    stepped[adj] = true;
                    prevs[adj] = curr;
                    q.push(adj);
                    cnt++;
                    continue;
                }

                // case2 : old node
                // if just the previous one then no surprise
                // but if not the previos one - this indicates loop in graph structure
                if (prevs[curr] != adj) { return false; }
            }
        }

        return cnt == n;
    }
};

