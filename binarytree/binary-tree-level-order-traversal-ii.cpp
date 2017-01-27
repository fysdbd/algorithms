/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        vector<vector<int>> result; vector<vector<TreeNode*>> generator;
        if (root == NULL) return result;
        
        vector<int> r_level;
        vector<TreeNode*> g_level; g_level.push_back(root); generator.push_back(g_level); g_level.clear();
        
        int curr_level = 0;
        while(true)
        {
            if (generator.at(curr_level).empty()) break;
            for (auto ptr = generator.at(curr_level).begin(); ptr != generator.at(curr_level).end(); ptr++)
            {
                r_level.push_back((*ptr)->val);
                if ((*ptr)->left != NULL) g_level.push_back((*ptr)->left);
                if ((*ptr)->right != NULL) g_level.push_back((*ptr)->right);
                
            }
            result.push_back(r_level);
            generator.push_back(g_level);
            
            r_level.clear(); g_level.clear();
            curr_level++;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
