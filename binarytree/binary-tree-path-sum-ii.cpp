
/*
    Binary Tree Path Sum II

    description(lintcode:
                https://www.lintcode.com/en/problem/binary-tree-path-sum-ii/
                )

    Your are given a binary tree in which each node contains a value.
    Design an algorithm to get all paths which sum to a given value.
    The path does not need to start or end at the root or a leaf,
    but it must go in a straight line down.

    Example
    Given a binary tree:

       1
      / \
     2   3
    /   /
    4   2
    for target = 6, return
    [
      [2, 4],
      [1, 3, 2]
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
    vector<vector<int>> binaryTreePathSum2(TreeNode *root, int target) {
        vector<vector<int>> result;
        vector<int> path;
        traverse(root, result, path, target);
        return result;
    }

    void traverse(TreeNode* root, vector<vector<int>>& result, vector<int>& path, int target) {
        if (root == nullptr) { return; }
        path.push_back(root->val);

        // start going all the way back the path and check all possibilities
        int sum = 0;
        vector<int> sol;
        for (auto it = path.rbegin(); it != path.rend(); it++) {
            sum += *it;
            sol.insert(sol.begin(), *it);
            if (sum == target) { result.push_back(sol); }
        }

        traverse(root->left, result, path, target);
        traverse(root->right, result, path, target);
        path.pop_back();
    }
};
