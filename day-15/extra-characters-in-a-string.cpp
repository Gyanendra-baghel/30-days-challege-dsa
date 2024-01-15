class Solution {

    unordered_set<string> dict;

    int helper(int start, string s, vector<int>& dp) {
        if(s.size() == start) {
            return 0;
        }
        if(dp[start] != -1) {
            return dp[start];
        }
        int value = INT_MAX;
        string temp = "";
        for(int i = start; i < s.size(); i++) {
            temp += s[i];
            int stringNotFoundLen = dict.count(temp) ? 0 : (i-start+1);
            value = min(value, stringNotFoundLen+helper(i+1, s, dp));
        }

        return dp[start] = value;
    }

public:
    int minExtraChar(string s, vector<string>& dictionary) {
        for(auto word: dictionary) {
            dict.insert(word);
        }

        vector<int> dp(s.size(), -1);
        
        return helper(0, s, dp);
    }
};