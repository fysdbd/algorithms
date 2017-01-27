
/*
    Binary Tree Level Order Traversal II

    Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

    For example:
    Given binary tree [3,9,20,null,null,15,7],
        3
       / \
      9  20
        /  \
       15   7
    return its bottom-up level order traversal as:
    [
      [15,7],
      [9,20],
      [3]
    ]

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        queue<pair<TreeNode*,int>> nodes;
        nodes.push(make_pair(root, 1));
        
        while (!nodes.empty()) {
            auto node = nodes.front().first;
            auto level = nodes.front().second;
            nodes.pop();
            
            if (node == nullptr) { continue; }
            if (level > result.size()) { result.push_back(vector<int>()); }
            result.back().push_back(node->val);
            nodes.push(make_pair(node->left, level+1));
            nodes.push(make_pair(node->right, level+1));
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
