
/*
    Trie Serialization

    Serialize and deserialize a trie (prefix tree, search on internet for more details).

    You can specify your own serialization algorithm, the online judge only cares about whether you can successfully deserialize the output from your own serialize function.

    You don't have to serialize like the test data, you can design your own format.

    Example
    str = serialize(old_trie)
    >> str can be anything to represent a trie
    new_trie = deserialize(str)
    >> new_trie should have the same structure and values with old_trie
    An example of test data: trie tree <a<b<e<>>c<>d<f<>>>>, denote the following structure:

         root
          /
         a
       / | \
      b  c  d
     /       \
    e         f

    notes:
*/


/**
 * Definition of TrieNode:
 * class TrieNode {
 * public:
 *     TrieNode() {}
 *     map<char, TrieNode*> children;
 * };
 */
class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a trie which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TrieNode* root) {
        string result = "";
        for (auto entry : root->children) {
            result = result + "<" + entry.first + serialize(entry.second) + ">";
        }
        return result;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TrieNode* deserialize(string data) {
        TrieNode* root = new TrieNode();
        int idx = 0;
        deserialize_helper(data, idx, root);
        return root;
    }
    
    void deserialize_helper(const string& data, int& idx, TrieNode* parent) {
        
        while (idx < data.size() && data[idx] == '<') {
            idx++; // pass the '<'
            
            char character = data[idx++];
            TrieNode* newnode = new TrieNode();
            parent->children.emplace(character, newnode);
            deserialize_helper(data, idx, newnode);
            
            idx++; // pass the '>'
        }
    }
};


