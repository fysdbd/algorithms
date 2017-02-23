
/*
    Trapping Rain Water

    description(leetcode:
                https://leetcode.com/problems/trapping-rain-water/?tab=Description
                )

    Given n non-negative integers representing an elevation map where the width of each bar is 1,
    compute how much water it is able to trap after raining.

    For example,
    Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

*/

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) { return 0; }
        int peak_idx = max_element(height.begin(), height.end()) - height.begin();
        int peak = height[peak_idx], result = 0, barrier, left_peak, right_peak, i = 0;


        i = 0; barrier = height[0];
        while (height[i] < peak) {
            result += (barrier > height[i] ? barrier-height[i] : 0);
            barrier = std::max(barrier, height[i]);
            i++;
        }
        left_peak = i;

        i = height.size()-1;
        barrier = height.back();
        while (height[i] < peak) {
            result += (barrier > height[i] ? barrier-height[i] : 0);
            barrier = std::max(barrier, height[i]);
            i--;
        }
        right_peak = i;


        for (int i = left_peak; i <= right_peak; i++) {
            result += (peak > height[i] ? peak-height[i] : 0);
        }

        return result;
    }
};
