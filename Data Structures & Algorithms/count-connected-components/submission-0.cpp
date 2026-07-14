class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parents(n);
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }
        for (auto& edge: edges) {
            unite(edge[0], edge[1], parents);
        }

        unordered_set<int> roots;
        for (int i = 0; i < n; i++) {
            roots.insert(find(i, parents));
        }
        return roots.size();
    }

    int find(int x, vector<int>& parents) {
        if (parents[x] != x) {
            parents[x] = find(parents[x], parents);
        }
        return parents[x];
    }

    void unite(int x, int y, vector<int>& parents) {
        int rootX = find(x, parents);
        int rootY = find(y, parents);
        parents[rootX] = rootY;
        return;
    }
};
