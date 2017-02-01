
/*
    Binary Tree Serialization

    description(lintcode:
                http://www.lintcode.com/en/problem/binary-tree-serialization/
                )

    Design an algorithm and write code to serialize and deserialize a binary tree. Writing the tree to a file is called 'serialization' and reading back from the file to reconstruct the exact same binary tree is 'deserialization'.

    There is no limit of how you deserialize or serialize a binary tree, you only need to make sure you can serialize a binary tree to a string and deserialize this string to the original structure.

    Example
    An example of testdata: Binary tree {3,9,20,#,#,15,7}, denote the following structure:

      3
     / \
    9  20
      /  \
     15   7
    Our data serialization use bfs traversal. This is just for when you got wrong answer and want to debug the input.

    You can use other method to do serializaiton and deserialization.


    notes:
    the key to an efficient implementation lies in level order traversal
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
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        queue<TreeNode*> nodes;
        nodes.push(root);
        
        string result = "";
        while (!nodes.empty()) {
            auto node = nodes.front();
            nodes.pop();
            
            result = result + (node == nullptr ? "null" : std::to_string(node->val)) + " ";
            if (node == nullptr) { continue; }
            nodes.push(node->left);
            nodes.push(node->right);
        }
        
        result.pop_back();
        return result;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        
        vector<TreeNode*> nodes;
        stringstream ss(data); string str;
        while (!ss.eof()) {
            ss >> str;
            TreeNode* newnode = (str == "null" ? nullptr : new TreeNode(std::stoi(str)));
            nodes.push_back(newnode);          
        }
        
        int slow = 0, fast = 1;
        while (fast < nodes.size()) {
            nodes[slow]->left = nodes[fast++];
            nodes[slow]->right = nodes[fast++];
            do { slow++; } while (slow < nodes.size() && nodes[slow] == nullptr);
        }
        
        return nodes[0];
    }
};


