class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> results;
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        while (bottom >= top && right >= left) {
            for (int i = left; i <= right; i++) {
                results.emplace_back(matrix[top][i]);
            }
            top++;
            if (top > bottom) {continue;}
            for (int i = top; i <= bottom; i++) {
                results.emplace_back(matrix[i][right]);
            }
            right--;
            if (left > right) {continue;}
            for (int i = right; i >= left; i--) {
                results.emplace_back(matrix[bottom][i]);
            }
            bottom--;
            if (top > bottom) {continue;}
            for (int i = bottom; i >= top; i--) {
                results.emplace_back(matrix[i][left]);
            }
            left++;
        }
        return results;
    }
};
