class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> results;
        int top = 0;
        int left = 0;
        int bottom = matrix.size() - 1;
        int right = matrix[0].size() - 1;
        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) {
                results.push_back(matrix[top][i]);
            }
            top++;
            if (bottom < top) {break;}
            for (int i = top; i <= bottom; i++) {
                results.push_back(matrix[i][right]);
            }
            right--;
            if (right < left) {break;}
            for (int i = right; i >= left; i--) {
                results.push_back(matrix[bottom][i]);
            }
            bottom--;
            if (bottom < top) {break;}
            for (int i = bottom; i >= top; i--) {
                results.push_back(matrix[i][left]);
            }
            left++;
        }
        return results;
    }
};
