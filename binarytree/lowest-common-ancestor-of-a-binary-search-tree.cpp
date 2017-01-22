
/*******************************************************************************

    Lowest Common Ancestor of a Binary Search Tree

    description(leetcode:
                https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
                )
    Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
    According to the definition of LCA on Wikipedia:
    “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants
    (where we allow a node to be a descendant of itself).”
            _______6______
           /              \
        ___2__          ___8__
       /      \        /      \
       0      _4       7       9
             /  \
             3   5
    For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2,
    since a node can be a descendant of itself according to the LCA definition.

    notes:

    making full use of binary search tree properties
    thus solution very different from lowest common ancestor of binary tree
    we do not need a full search here anymore, since we can know which branch to go in to futher search
    based on comparison on target1, target2 and node

*******************************************************************************/


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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* A, TreeNode* B) {

        if (root == nullptr) { return root; }

        bool same_side = (root->val - A->val) * (root->val - B->val) > 0;
        if (!same_side) { return root; }
        return (root->val - A->val > 0 ? lowestCommonAncestor(root->left, A, B)
                                       : lowestCommonAncestor(root->right, A, B) );
    }

};
