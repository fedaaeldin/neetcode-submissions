class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int result = students.size();
        int size = result;

        vector<int> count(2);

        for(int i = 0; i < size; ++i) {
            count[students[i]]++;
        }

        for(int i = 0; i < size; ++i) {
            if(count[sandwiches[i]] > 0) {
                count[sandwiches[i]]--;
                result --;
            } else {
                break;
            }
        }
        return result;
    }
};