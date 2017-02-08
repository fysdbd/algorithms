
/*
    Unique Binary Search Trees II

    Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

    For example,
    Given n = 3, your program should return all 5 unique BST's shown below.

       1         3     3      2      1
        \       /     /      / \      \
         3     2     1      1   3      2
        /     /       \                 \
       2     1         2                 3
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
    vector<TreeNode*> generateTrees(int start, int end) {
        if (start > end) { return {nullptr}; }
        if (start == end) { return { new TreeNode(start) }; }

        vector<TreeNode*> result;
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> lefts = generateTrees(start, i-1);
            vector<TreeNode*> rights = generateTrees(i+1, end);
            for (auto l : lefts) {
                for (auto r : rights) {
                    auto node = new TreeNode(i);
                    node->left = l;
                    node->right = r;
                    result.push_back(node);
                }
            }
        }

        return result;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) { return {}; }
        return generateTrees(1, n);
    }
};

