class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (auto& p : prerequisites) {
            adj[p[0]].push_back(p[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0 && !dfs(i, adj, visited)) {
                return false;
            }
        }
        return true;
    }

    bool dfs(int index, vector<vector<int>>& adj, vector<int>& visited) {
        visited[index] = 1;

        for (int i : adj[index]) {
            if (visited[i] == 1) {return false;}
            if (visited[i] == 0 && !dfs(i, adj, visited)) {return false;}
        }
        visited[index] = 2;
        return true;
    }
};
