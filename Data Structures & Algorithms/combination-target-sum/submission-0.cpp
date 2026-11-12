class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> current;
        solve(nums, target, 0, current, result);
        
        return result;
    }

    private:
    void solve(const vector<int>& nums, int target, int i, vector<int> &current, vector<vector<int>> &result) {
        if(target == 0) {
            result.push_back(current);
            return;
        }

        if(i >= nums.size()) {
            return;
        }

        if(target - nums[i] >= 0) {
            current.push_back(nums[i]);
            solve(nums, target - nums[i], i, current, result);
            current.pop_back();
        }
        
        solve(nums, target, i + 1, current, result);

    
    }
};
