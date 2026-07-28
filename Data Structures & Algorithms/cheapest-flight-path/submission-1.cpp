class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        for (int round = 0; round <= k; round++) {
            vector<int> temp = dist;
            for (auto& flight : flights) {
                int from = flight[0];
                int to = flight[1];
                int price = flight[2];
                if (dist[from] != INT_MAX && dist[from] + price < temp[to]) {
                    temp[to] = dist[from] + price;
                }
            }

            dist = temp;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
