class LetterNode {
public:
    LetterNode* children[26];
    bool isEnd;

    LetterNode() {
        for (int i = 0; i < 26; i++) {children[i] = nullptr;}
        isEnd = false;
    }
};

class WordDictionary {
public:
    LetterNode* root;

    WordDictionary() {
        root = new LetterNode();
    }
    
    void addWord(string word) {
        LetterNode* curr = root;
        for (char c : word) {
            int a = c - 'a';
            if (!curr->children[a]) {
                curr->children[a] = new LetterNode();
            }
            curr = curr->children[a];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        LetterNode* curr = root;
        return searchHelper(word, 0, curr);
    }

    bool searchHelper (string& word, int index, LetterNode* curr) {
        if (index == word.size()) {return curr->isEnd;}

        if (word[index] == '.') {
            for (int i = 0; i < 26; i++) {
                if (curr->children[i] && searchHelper(word, index + 1, curr->children[i])) {
                    return true;
                }
            }
            return false;
        } else {
            int a = word[index] - 'a';
            if (!curr->children[a]) {
                return false;
            }
            return searchHelper(word, index + 1, curr->children[a]);
        }
    }
};
