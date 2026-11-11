class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int sz = nums.size();
        vector<vector<int>> result;
        for(int msk = 0; msk < (1 << sz); ++msk) {
            vector<int> current;
            for(int bit = 0; bit < sz; ++bit) {
                if(msk & (1 << bit)) {
                    current.push_back(nums[bit]);
                }
            }
            result.push_back(current);
        }
        return result;
    }


};
