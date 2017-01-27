
/*
    Binary Tree Right Side View

    Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

    For example:
    Given the following binary tree,
       1            <---
     /   \
    2     3         <---
     \     \
      5     4       <---
    You should return [1, 3, 4].

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> result;
        queue<pair<TreeNode*,int>> nodes;
        nodes.push(make_pair(root, 1));

        while (!nodes.empty()) {
            auto node = nodes.front().first;
            auto level = nodes.front().second;
            nodes.pop();

            if (node == nullptr) { continue; }
            if (node->left != nullptr) { nodes.push(make_pair(node->left, level+1)); }
            if (node->right != nullptr) { nodes.push(make_pair(node->right, level+1)); }
            if (nodes.empty() || nodes.front().second != level) { result.push_back(node->val); }
        }

        return result;
    }
};

