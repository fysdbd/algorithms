
/* 
    Subtree With Maximum Average

    description(lintcode:
                http://www.lintcode.com/en/problem/subtree-with-maximum-average/
                )

    Given a binary tree, find the subtree with maximum average. Return the root of the subtree.

    LintCode will print the subtree which root is your return node.
    It's guaranteed that there is only one subtree with maximum average.

    notes:
    good example of passing multiple fields across nodes and levels in trees for computation needs
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right>;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right> = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root the root of binary tree
     * @return the root of the maximum average of subtree 
     */
     
    typedef struct report {
        int sum{0};
        int cnt{0}; // number of nodes
        float max_val{0.0};
        TreeNode* max_index{0};
        report(int s, int c, float val, TreeNode* i) : sum(s),
                                                       cnt(c),
                                                       max_val(val),
                                                       max_index(i)
                                                       {}
    } report_t;

    TreeNode* findSubtree2(TreeNode* root) {
        return helper(root).max_index;
    }
    
    report_t helper(TreeNode* root) {
        
        if (root == nullptr) { return {0, 0, 0, nullptr}; }
        
        auto left = helper(root->left);
        auto right = helper(root->right);
        
        int sum = left.sum + right.sum + root->val;
        int cnt = left.cnt + right.cnt + 1;
        auto val = ((float)sum) / cnt;
        std::vector<float> candicates = {(left.max_index ? left.max_val : INT_MIN),
                                         (right.max_index ? right.max_val : INT_MIN),
                                         val};
        int index = max_element(candicates.begin(), candicates.end()) - candicates.begin();
          
        if (index == 0) {
            return {sum,
                    cnt,
                    left.max_val,
                    left.max_index};
            
        } else if (index == 1) {
            return {sum,
                    cnt,
                    right.max_val,
                    right.max_index};
            
        } else { // (index == 2) 
            return {sum,
                    cnt,
                    val,
                    root};
        }
                     
    }
    
};

