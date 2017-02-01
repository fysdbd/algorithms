
/*
    Construct Binary Tree from Preorder and Inorder Traversal

    description(lintcode
                http://www.lintcode.com/en/problem/construct-binary-tree-from-preorder-and-inorder-traversal/
                )

    Given preorder and inorder traversal of a tree, construct the binary tree.
    You may assume that duplicates do not exist in the tree.

    Example
    Given in-order [1,2,3] and pre-order [2,1,3], return a tree:

      2
     / \
    1   3

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
    /**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    void build(vector<int> &preorder,
               vector<int> &inorder,
               vector<int>::iterator pre_start,
               vector<int>::iterator pre_end,
               vector<int>::iterator in_start,
               vector<int>::iterator in_end,
               TreeNode** src
               ) {
        if (in_end <= in_start) { return; }
        
        int val = *pre_start;
        (*src) = new TreeNode(val);
        auto it = find(in_start, in_end, val);
        int left = it-in_start, right = in_end-it;
        
        build(preorder,
              inorder,
              pre_start+1,
              pre_start+left,
              in_start,
              it,
              &((*src)->left));
    
        build(preorder,
              inorder,
              pre_start+left+1,
              pre_end,
              it+1,
              in_end,
              &((*src)->right));               
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty()) { return nullptr; }
        
        TreeNode** src;
        build(preorder,
              inorder,
              preorder.begin(),
              preorder.end(),
              inorder.begin(),
              inorder.end(),
              src);
        return *src;
    }
};

