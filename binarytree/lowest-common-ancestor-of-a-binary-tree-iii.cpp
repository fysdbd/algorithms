
/*******************************************************************************

    Lowest Common Ancestor III

    description(lintcode:
                http://www.lintcode.com/en/problem/lowest-common-ancestor-iii/
                )

    Given the root and two nodes in a Binary Tree. Find the lowest common ancestor(LCA) of the two nodes.
    The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.
    Return null if LCA does not exist.

    notes:
    difference against lowest-common-ancestor-of-binary-tree (i): the target nodes could be missing
    again, as no additional information is available, you can assure yourself that a full search is necessary
    thus starting from the solution to lowest-common-ancestor-of-binary-tree (i),
    only one additional line is needed, that is,
    to check whether both targets are presented in the network after the search is completed

*******************************************************************************/


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
     * @param root: The root of the binary tree.
     * @param A and B: two nodes
     * @return: Return the LCA of the two nodes.
     */
    TreeNode *lowestCommonAncestor3(TreeNode* root, TreeNode* A, TreeNode* B) {

        if (root == nullptr) { return root; }

        vector<TreeNode*> pathA, pathB, path;
        traverse(root, A, B, pathA, pathB, path);

        // this line is the only difference compared to lowest common ancestor (i)
        if (pathA.empty() || pathB.empty()) { return nullptr; }

        int idx = 0;
        while (idx+1 < pathA.size() && idx+1 < pathB.size() && pathA[idx+1] == pathB[idx+1]) { idx++; }
        return pathA[idx];
    }

    void traverse(TreeNode* node,
                  TreeNode* A,
                  TreeNode* B,
                  vector<TreeNode*>& pa,
                  vector<TreeNode*>& pb,
                  vector<TreeNode*>& path
                  ) {

        if (node == nullptr) { return; }

        path.push_back(node);
        if (node == A) { pa = path; }
        if (node == B) { pb = path; }
        traverse(node->left,  A, B, pa, pb, path);
        traverse(node->right, A, B, pa, pb, path);
        path.pop_back();
    }
};
