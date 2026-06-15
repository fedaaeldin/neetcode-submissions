class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maximum = 0;
        int current = 0;
        for (auto &num : nums) {
            current = num ? current + 1 : 0;
            maximum = max(maximum, current);
        }
        return maximum;
    }
};