
/*******************************************************************************
    Lowest Common Ancestor of a Binary Tree

    description(leetcode:
                https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
                )

    Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
    According to the definition of LCA on Wikipedia:
    “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has
    both v and w as descendants (where we allow a node to be a descendant of itself).”
            _______3______
           /              \
        ___5__          ___1__
       /      \        /      \
       6      _2       0       8
             /  \
             7   4
    For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3.
    Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

    notes:
    worst case analysis: since a binary tree is just a tree without any other information available,
    then one do have to a full search in order to locate the targets

    folowing code can be used as a basic template for traversing through binary trees
    thus it may be helpful in many other problems where a DFS(depth-first-search)
    is needed. Other computation needs can be easily fulfilled through slight modification,
    e.g. changing parameters passed into recursion function

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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {

        if (root == nullptr) { return root; }

        vector<TreeNode*> pathA, pathB, path;
        traverse(root, A, B, pathA, pathB, path);

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

