
/*******************************************************************************
 *
    Lowest Common Ancestor of a Binary Tree II

    description(lintcode:
                http://www.lintcode.com/en/problem/lowest-common-ancestor-ii/
                )

    Given the root and two nodes in a Binary Tree. Find the lowest common ancestor(LCA) of the two nodes.
    The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.
    The node has an extra attribute parent which point to the father of itself. The root's parent is null.

    notes:

    the key difference of this problem against lowest common ancestor (i) but the difference lies in the parent pointer
    thus we can easily get the depth of a node in the whole tree structure

*******************************************************************************/

/**
 * Definition of ParentTreeNode:
 * class ParentTreeNode {
 * public:
 *     int val;
 *     ParentTreeNode *parent, *left, *right;
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of the tree
     * @param A, B: Two node in the tree
     * @return: The lowest common ancestor of A and B
     */

    inline int depth(ParentTreeNode* root, ParentTreeNode* node) {
        int depth = 0;
        while (node != root) { node = node->parent; depth++; }
        return depth;
    }

    ParentTreeNode *lowestCommonAncestorII(ParentTreeNode *root,
                                           ParentTreeNode *A,
                                           ParentTreeNode *B) {

        int diff = depth(root, A) - depth(root, B);

        if (diff > 0) {
            while (diff--) { A = A->parent; }
        } else if (diff < 0) {
            while (diff++) { B = B->parent; }
        }

        while (A != B) { A = A->parent; B = B->parent; }

        return A;
    }
};

