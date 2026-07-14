class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 26; i++) {children[i] = nullptr;}
        isEnd = false;
    }
};

class PrefixTree {
public:
    TrieNode* root;

    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int a = c - 'a';
            if (!curr->children[a]) {
                curr->children[a] = new TrieNode();
            }
            curr = curr->children[a];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int a = c - 'a';
            if (!curr->children[a]) {
                return false;
            }
            curr = curr->children[a];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            int a = c - 'a';
            if (!curr->children[a]) {
                return false;
            }
            curr = curr->children[a];
        }
        return true;
    }
};
