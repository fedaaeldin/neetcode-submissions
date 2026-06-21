class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        stack<int> s;

        for(auto &i : students) {
            q.push(i);
        }

        for(int i = sandwiches.size() - 1; i >= 0; --i) {
            s.push(sandwiches[i]);
        }

        int loops = 0;
        while(! q.empty()) {
            if(q.front() == s.top()) {
                q.pop(); s.pop();
                loops = 0;
            } else {
                q.push(q.front());
                q.pop();
                ++loops;
            }
            if(loops > q.size()) {
                return q.size();
            }
        }
        return 0;
    }
};