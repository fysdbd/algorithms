
/*
    Minimum Subtree

    description(lintcode:
                http://www.lintcode.com/en/problem/minimum-subtree/
                )

    Given a binary tree, find the subtree with minimum sum. Return the root of the subtree.
    LintCode will print the subtree which root is your return node.
    It's guaranteed that there is only one subtree with minimum sum and the given binary tree is not an empty tree.

    notes:
    good example of pass multiple fields across nodes and levels in trees for computation needs
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
     * @return the root of the minimum subtree
     */
    
    typedef struct report {
        int sum{0};
        int min_val{0};
        TreeNode* min_index{0};
        report(int s, int val, TreeNode* i) : sum(s),
                                              min_val(val),
                                              min_index(i)
                                              {}
    } report_t;
     
    TreeNode* findSubtree(TreeNode* root) {
        return helper(root).min_index;
    }
    
    report_t helper(TreeNode* root) {
        
        if (root == nullptr) { return {0, 0, nullptr}; }
        
        auto left = helper(root->left);
        auto right = helper(root->right);
        
        std::vector<int> candicates = {(left.min_index ? left.min_val : INT_MAX),
                                       (right.min_index ? right.min_val : INT_MAX),
                                       left.sum + right.sum + root->val};
        int index = min_element(candicates.begin(), candicates.end()) - candicates.begin();
          
        if (index == 0) {
            return {left.sum + right.sum + root->val,
                    left.min_val,
                    left.min_index};
            
        } else if (index == 1) {
            return {left.sum + right.sum + root->val,
                    right.min_val,
                    right.min_index};
            
        } else { // (index == 2) 
            return {left.sum + right.sum + root->val,
                    left.sum + right.sum + root->val,
                    root};
        }
                     
    }
};

