class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        unordered_map<int, int> freq;
        int res = students.size();
        for(auto &s : students) {
            freq[s]++;
        }

        for(auto &s : sandwiches) {
            if(freq[s] > 0) {
                freq[s]--;
                res--;
            } else {
                break;
            }
        }
        return res;
    }
};