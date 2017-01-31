
/*
    Trie Service

    Build tries from a list of pairs. Save top 10 for each node.

    Example
    Given a list of

    <"abc", 2>
    <"ac", 4>
    <"ab", 9>
    Return <a[9,4,2]<b[9,2]<c[2]<>>c[4]<>>>, and denote the following tree structure:

             Root
             / 
           a(9,4,2)
          /    \
        b(9,2) c(4)
       /
     c(2)

    notes:
*/


/**
 * Definition of TrieNode:
 * class TrieNode {
 * public:
 *     TrieNode() {}
 *     map<char, TrieNode*> children;
 *     vector<int> top10;
 * };
 */
class TrieService {
private:
    TrieNode* root;

public:
    TrieService() {
        root = new TrieNode();
    }

    TrieNode* getRoot() {
        // Return root of trie root, and 
        // lintcode will print the tree struct.
        return root;
    }

    void insert(string& word, int frequency) {
        
        auto node = root;
        for (char c : word) {
            
            // make sure node exists and continue
            if (node->children.find(c) == node->children.end()) {
                TrieNode* newnode = new TrieNode();
                node->children.emplace(c, newnode);
            }
            node = node->children[c];
            
            // frequency update
            if (node->top10.size() < 10) {
                node->top10.push_back(frequency);
            }
            else {
                auto it = std::min_element(node->top10.begin(), node->top10.end());
                *it = std::max(*it, frequency);
            }
            sort(node->top10.begin(), node->top10.end(), std::greater<int>());
            
        }
        
    }
};



