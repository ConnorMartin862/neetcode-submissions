class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        if (words.size() == 1) {
            return words[0];
        }
        unordered_map<char, vector<char>> adj;
        unordered_set<char> allChars;
        for (string& w : words) {
            for (char c : w) {allChars.insert(c);}
        }

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

        unordered_map<char, int> inDegree;
        for (char c : allChars) {inDegree[c] = 0;}
        for (auto& [from, neighbors] : adj) {
            for (char to : neighbors) {inDegree[to]++;}
        }
        queue<char> q;
        for (char c : allChars) { if(inDegree[c] == 0) {q.push(c);}}

        string result = "";
        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            result += curr;
            for (char neighbor : adj[curr]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if (result.size() != allChars.size()) {return "";}
        return result;
    }
};
