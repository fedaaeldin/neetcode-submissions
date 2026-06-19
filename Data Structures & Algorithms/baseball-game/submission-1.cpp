class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> numbers;
        int result = 0;
        for(auto& ch : operations) {
            if(! numbers.empty() && ch == "+") {
                int top = numbers.top();
                numbers.pop();
                if(! numbers.empty()) {
                    int sum = numbers.top() + top;
                    numbers.push(top);
                    numbers.push(sum);
                    result += sum;
                }
            } else if (! numbers.empty() &&  ch == "D") {
                numbers.push(numbers.top() * 2);
                result += numbers.top();
            } 
            else if (! numbers.empty() && ch == "C") {
                result -= numbers.top();
                numbers.pop();
            }
            else {
                numbers.push(stoi(ch));
                result += numbers.top();
            }
        }
        return result;
    }
};