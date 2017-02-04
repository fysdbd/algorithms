
/*
    Binary Tree Path Sum III
    
    description(lintcode
                https://www.lintcode.com/en/problem/binary-tree-path-sum-iii/
                )

    Give a binary tree, and a target number, find all path that the sum of nodes equal to target, the path could be start and end at any node in the tree.

    Example
    Given binary tree:

        1
       / \
      2   3
     /
    4
    and target = 6. Return :

    [
      [2, 4],
      [2, 1, 3],
      [3, 1, 2],
      [4, 2]
    ]

*/

/**
 * Definition of ParentTreeNode:
 * class ParentTreeNode {
 * public:
 *     int val;
 *     ParentTreeNode *parent, *left, *right;
 * }
 */
class Solution {
public:
    /**
     * @param root the root of binary tree
     * @param target an integer
     * @return all valid paths
     */
    vector<vector<int>> binaryTreePathSum3(ParentTreeNode *root, int target) {
        
        // step 1 : collect all nodes in the tree
        vector<ParentTreeNode*> nodes;
        queue<ParentTreeNode*> q; q.push(root);
        while (!q.empty()) {
            auto node = q.front(); q.pop();
            if (node == nullptr) { continue; }
            nodes.push_back(node);
            q.push(node->left);
            q.push(node->right);
        }
        
        // step 2 : use every one of them as root and traverse across the tree
        vector<vector<int>> result;
        vector<int> path;
        for (auto node : nodes) {
            traverse(node, nullptr, result, path, target);
        }
        
        return result;
    }
    
    void traverse(ParentTreeNode* root,
                  ParentTreeNode* source,
                  vector<vector<int>>& result,
                  vector<int>& path,
                  int target) {

        if (root == nullptr) { return; }
        path.push_back(root->val);
        if (root->val == target) { result.push_back(path); }
        
        vector<ParentTreeNode*> dirs = {root->left, root->right, root->parent};
        for (auto dir : dirs) {
            if (dir != source) {
                traverse(dir, root, result, path, target-root->val);
            }
        }
        
        path.pop_back();
    }
};

