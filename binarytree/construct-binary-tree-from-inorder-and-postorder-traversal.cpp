
/*
    Construct Binary Tree from Inorder and Postorder Traversal

    description(lintcode
                http://www.lintcode.com/en/problem/construct-binary-tree-from-inorder-and-postorder-traversal/
                )

    Given inorder and postorder traversal of a tree, construct the binary tree.
    You may assume that duplicates do not exist in the tree.

    Example
    Given inorder [1,2,3] and postorder [1,3,2], return a tree:

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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:
    void build(vector<int> &inorder,
               vector<int> &postorder,
               vector<int>::iterator in_start,
               vector<int>::iterator in_end,
               vector<int>::iterator post_start,
               vector<int>::iterator post_end,
               TreeNode** src
               ) {
        if (in_end <= in_start) { return; }
        
        int val = *(post_end-1);
        (*src) = new TreeNode(val);
        auto it = find(in_start, in_end, val);
        int left = it-in_start, right = in_end-it;
        
        build(inorder,
              postorder,
              in_start,
              it,
              post_start,
              post_start+left,
              &((*src)->left));
    
        build(inorder,
              postorder,
              it+1,
              in_end,
              post_start+left,
              post_end-1,
              &((*src)->right));               
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.empty()) { return nullptr; }
        
        TreeNode** src;
        build(inorder,
              postorder,
              inorder.begin(),
              inorder.end(),
              postorder.begin(),
              postorder.end(),
              src);
        return *src;
    }
};

