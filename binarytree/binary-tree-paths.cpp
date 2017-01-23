
/*
    Binary Tree Paths

    description(leetcode:
                https://leetcode.com/problems/binary-tree-paths/
                )

    Given a binary tree, return all root-to-leaf paths.
    For example, given the following binary tree:
       1
     /   \
    2     3
     \
      5
    All root-to-leaf paths are:
    ["1->2->5", "1->3"]

    notes:
    the most classical example of DFS(depth first search)
    easiest implementation would be to do it by recursion

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
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<int> path;
        vector<string> results;

        if (root == nullptr) { return results; }

        traverse(root, path, results);
        return results;
    }

    string to_string_representation(vector<int>& nums) {
        string result;
        if (nums.empty()) { return result; }
        for (auto num : nums) { result = result + to_string(num) + "->"; }
        return result.substr(0, result.size()-2);  // remove last "->"
    }

    void traverse(TreeNode* node,
                  vector<int>& path,
                  vector<string>& results
                  ) {

        if (node == nullptr) { return; }

        path.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            results.push_back(to_string_representation(path));
        }
        traverse(node->left, path, results);
        traverse(node->right, path, results);
        path.pop_back();
    }
};
