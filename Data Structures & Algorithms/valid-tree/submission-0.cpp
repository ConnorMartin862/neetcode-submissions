class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {return false;}

        vector<int> parents(n);
        for (int i = 0; i < parents.size(); i++) {
            parents[i] = i;
        }

        for (auto& edge : edges) {
            if (!unite(edge[0], edge[1], parents)) {return false;}
        }
        return true;
    }

    int find(int x, vector<int>& parents) {
        if (parents[x] != x) {
            parents[x] = find(parents[x], parents);
        }
        return parents[x];
    }

    bool unite(int x, int y, vector<int>& parents) {
        int rootX = find(x, parents);
        int rootY = find(y, parents);
        if (rootX == rootY) {return false;}
        parents[rootX] = rootY;
        return true;
    }
};
