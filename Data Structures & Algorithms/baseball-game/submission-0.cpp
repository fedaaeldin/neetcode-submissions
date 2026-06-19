class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> numbers;
        for(auto& ch : operations) {
            if(! numbers.empty() && ch == "+") {
                int top = numbers.top();
                numbers.pop();
                if(! numbers.empty()) {
                    int sum = numbers.top() + top;
                    numbers.push(top);
                    numbers.push(sum);
                }
            } else if (! numbers.empty() &&  ch == "D") {
                numbers.push(numbers.top() * 2);
            } 
            else if (! numbers.empty() && ch == "C") {
                numbers.pop();
            }
            else {
                numbers.push(stoi(ch));
            }
        }
        int result = 0;
        while(! numbers.empty()) {
            result += numbers.top();
            numbers.pop();
        }
        return result;
    }
};