class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while (high - low > 1) {
            int middle = low + (high - low) / 2;
            if (determine(piles, h, middle)) {
                high = middle;
            } else {
                low = middle;
            }
        }
        if (determine(piles, h, low)) {return low;}
        else {return high;}
    }

    bool determine(vector<int>& piles, int h, int value) {
        int counter = 0;
        for (int pile : piles) {
            int num = (pile + value - 1) / value;
            counter += num;
            if (counter > h) {return false;}
        }
        return true;
    }
};
