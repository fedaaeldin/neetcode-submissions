class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> groups(nums.size() + 1);
        for(auto& n : nums) {
            count[n]++;
        }

        for(auto &[n, freq] : count) {
            groups[freq].push_back(n);
        }

        vector<int> result;

        for(int i = nums.size(); i > 0; --i) {
            for(int j = 0; j < groups[i].size(); ++j) {
                result.push_back(groups[i][j]);
                if(result.size() == k) {
                    return result;
                }
            }
        }


        return result;

    }
};
