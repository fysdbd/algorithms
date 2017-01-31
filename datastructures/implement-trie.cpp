
/*
    Implement Trie


    Implement a trie with insert, search, and startsWith methods.

    You may assume that all inputs are consist of lowercase letters a-z.

    Example
    insert("lintcode")
    search("code")
    >>> false
    startsWith("lint")
    >>> true
    startsWith("linterror")
    >>> false
    insert("linterror")
    search("lintcode)
    >>> true
    startsWith("linterror")
    >>> true

    notes:
*/


/**
 * Your Trie object will be instantiated and called as such:
 * Trie trie;
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
 */
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() { }
    
    void insert(const string& word, int idx) {
        if (idx < word.size()) {
            char c = word[idx];
            if (children.find(c) == children.end()) { // first make sure it exists
                TrieNode* newnode = new TrieNode();
                children.emplace(c, newnode);
            }
            children[c]->insert(word, idx+1);
        }
        else { // (idx == word.size())
            isword = true;
        }
    }
    
    bool search(const string& word, int idx) {
        if (idx < word.size()) {
            char c = word[idx];
            if (children.find(c) == children.end()) { return false; }
            else { return children[c]->search(word, idx+1); }
        }
        else { // (idx == word.size())
            return isword;
        }
    }
    
    bool startsWith(const string& word, int idx) {
        if (idx < word.size()) {
            char c = word[idx];
            if (children.find(c) == children.end()) { return false; }
            else { return children[c]->startsWith(word, idx+1); }
        }
        else { // (idx == word.size())
            return containsWord();
        }
    }
    
    bool containsWord() {
        if (isword) { return true; }
        for (auto entry : children) {
            if (entry.second->containsWord()) { return true; }
        }
        return false;
    }
private:
    map<char, TrieNode*> children;
    bool isword{false};
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        root->insert(word, 0);
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        return root->search(word, 0);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return root->startsWith(prefix, 0);
    }

private:
    TrieNode* root;
};

