
/*

Binary Tree Path Sum

description(lintcode
            https://www.lintcode.com/en/problem/binary-tree-path-sum/
            )

 Description
 Notes
 Testcase
 Judge
Given a binary tree, find all paths that sum of the nodes in the path equals to a given number target.

A valid path is from root node to any of the leaf nodes.

Have you met this question in a real interview? Yes
Example
Given a binary tree, and target = 5:

     1
    / \
   2   4
  / \
 2   3
return

[
  [1, 2, 2],
  [1, 4]
]

*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root the root of binary tree
     * @param target an integer
     * @return all valid paths
     */
    vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) {

        vector<vector<int>> result;
        vector<int> path;
        traverse(root, result, path, target);
        return result;
    }
    
    void traverse(TreeNode* root, vector<vector<int>>& result, vector<int>& path, int target) {
        if (root == nullptr) { return; }
        path.push_back(root->val);
        if (target == root->val && root->left == nullptr && root->right == nullptr) {
            result.push_back(path);
        }
        traverse(root->left, result, path, target-root->val);
        traverse(root->right, result, path, target-root->val);
        path.pop_back();
    }
};

