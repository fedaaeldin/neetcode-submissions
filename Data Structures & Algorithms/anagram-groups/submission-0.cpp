class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        int strsSize = strs.size();
        unordered_set<int> seen;
        for(int i = 0; i < strsSize; ++i) {
            if(seen.count(i)) {
                continue;
            }
            seen.insert(i);
            vector<string> group;
            group.push_back(strs[i]);
            for(int j = i + 1; j < strsSize; ++j) {
                if(isAnagram(strs[i], strs[j]) && ! seen.count(j)) {
                    seen.insert(j);
                    group.push_back(strs[j]);
                }
            }
            result.push_back(group);
        }
        return result;
    }

    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }

        vector<int> count(26, 0);
        for(int i = 0; i < s.length(); ++i) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for(auto &i : count) {
            if (i != 0) {
                return false;
            }
        }
        return true;
    }
};
