class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for(auto &c : tokens) {
            if(c == "*") {
                int first = nums.top();
                nums.pop();
                int second = nums.top();
                nums.pop();
                nums.push(second * first);
            } else if( c == "/") {
                int first = nums.top();
                nums.pop();
                int second = nums.top();
                nums.pop();
                nums.push(second / first);
            } else if (c == "+") {
                int first = nums.top();
                nums.pop();
                int second = nums.top();
                nums.pop();
                nums.push(second + first);
            } else if (c == "-") {
                int first = nums.top();
                nums.pop();
                int second = nums.top();
                nums.pop();
                nums.push(second - first);
            } else {
                int n = stoi(c);
                nums.push(n);
            }
        }
        return nums.top();
    }
};
