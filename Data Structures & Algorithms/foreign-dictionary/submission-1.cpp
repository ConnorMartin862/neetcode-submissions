class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        // Step 0: Base Case
        if (words.size() == 1) {
            string res;
            unordered_set<char> seen;
            for (char c : words[0]) {
                if (seen.insert(c).second) {
                    res += c;
                }
            }
            return res;
        }
        // Step 1: Initialize Resources
        unordered_map<char, vector<char>> adj;
        unordered_set<char> allChars;
        for (string& word : words) {
            for (char c : word) {allChars.insert(c);}
        }

        // Step 2: Create Adj List
        for (int i = 1; i < words.size(); i++) {
            string& prev = words[i - 1];
            string& curr = words[i];
            if (prev.size() > curr.size() && prev.substr(0, curr.size()) == curr) {return "";}
            int m = min(prev.size(), curr.size());
            for (int j = 0; j < m; j++) {
                if (prev[j] != curr[j]) {
                    adj[prev[j]].push_back(curr[j]);
                    break;
                }
            }
        }

        // Step 3: Initialize inDegree & queue
        unordered_map<char, int> inDegree;
        for (char c : allChars) {
            inDegree[c] = 0;
        }
        for (auto& [key, value] : adj) {
            for (char c : value) {
                inDegree[c]++;
            }
        }
        queue<char> q;
        for (auto& c : allChars) {
            if (inDegree[c] == 0) {q.push(c);}
        }

        // Step 4: Build Result String
        string result = "";
        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            result += curr;
            for (char c : adj[curr]) {
                inDegree[c]--;
                if (inDegree[c] == 0) {
                    q.push(c);
                }
            }
        }

        if (allChars.size() != result.size()) {return "";}
        return result;
    }
};
