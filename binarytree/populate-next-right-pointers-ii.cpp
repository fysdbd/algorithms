
/*
    Populating Next Right Pointers in Each Node II

    description(leetcode:
                https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
                )

    Follow up for problem "Populating Next Right Pointers in Each Node".

    What if the given tree could be any binary tree? Would your previous solution still work?

    Note:

    You may only use constant extra space.
    For example,
    Given the following binary tree,
             1
           /  \
          2    3
         / \    \
        4   5    7
    After calling your function, the tree should look like:
             1 -> NULL
           /  \
          2 -> 3 -> NULL
         / \    \
        4-> 5 -> 7 -> NULL

*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr) { return; }
        
        queue<pair<TreeLinkNode*,int>> nodes;
        nodes.push(make_pair(root, 1));
        while (!nodes.empty()) {

            TreeLinkNode* node = nodes.front().first;
            int level = nodes.front().second;
            nodes.pop();

            node->next = ( (nodes.empty() || level < nodes.front().second) ? nullptr : nodes.front().first );
            
            if (node->left != nullptr) { nodes.push(make_pair(node->left, level+1)); }
            if (node->right != nullptr) { nodes.push(make_pair(node->right, level+1)); }
        }

    }
};
