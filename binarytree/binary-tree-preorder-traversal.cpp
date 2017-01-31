
/*
    Binary Tree Preorder Traversal

    Given a binary tree, return the preorder traversal of its nodes' values.

    notes:
    iterative example of tree traversal instead of recursive ones
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
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {

        if (root == nullptr) { return {}; }
        
        vector<int> path;
        std::stack<std::pair<TreeNode*, bool>> s;
        s.push(std::make_pair(root, false));
        while (!s.empty()) {
            TreeNode* node = s.top().first;
            bool expanded = s.top().second;
            s.pop();
            
            if (node == nullptr) { continue; }
            if (expanded) {
                path.push_back(node->val);
            } else {
                s.push(std::make_pair(node->right, false));
                s.push(std::make_pair(node->left, false));
                s.push(std::make_pair(node, true));
            }
        }
        
        return path;
    }
};


