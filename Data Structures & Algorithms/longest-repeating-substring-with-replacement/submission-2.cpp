class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> storage(26, 0);
        int left = 0;
        int storMax = 0;
        int result = 0;
        for (int right = 0; right < s.size(); right++) {
            int a = s[right] - 'A';
            storage[a]++;
            storMax = max(storMax, storage[a]);
                
            while ((right - left + 1) - storMax > k) {
                storage[s[left] - 'A']--;
                left++;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};
