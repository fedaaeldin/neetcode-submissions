class Solution {
public:
    // vector<vector<int>> subsets(vector<int>& nums) {
    //     int sz = nums.size();
    //     vector<vector<int>> result;
    //     for(int msk = 0; msk < (1 << sz); ++msk) {
    //         vector<int> current;
    //         for(int bit = 0; bit < sz; ++bit) {
    //             if(msk & (1 << bit)) {
    //                 current.push_back(nums[bit]);
    //             }
    //         }
    //         result.push_back(current);
    //     }
    //     return result;
    // }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        solve(nums, 0, subset, result);
        return result;
    }

    private:
    void solve(const vector<int> &nums, int i, vector<int>& subset, vector<vector<int>>& result) {
        if(i >= nums.size()) {
            result.push_back(subset);
            return;
        }

        // pick
        subset.push_back(nums[i]);
        solve(nums, i + 1, subset, result);
        subset.pop_back();

        // leave
        solve(nums, i + 1, subset, result);
    }


};
