class Solution{   
public:
    string printMinNumberForPattern(string S){
        int n = S.length();
        string result;
        vector<int> digits;
        
        for (int i = 0; i <= n; i++) {
            digits.push_back(i + 1);
        
            if (i == n || S[i] == 'I') {
                while (!digits.empty()) {
                    result += to_string(digits.back());
                    digits.pop_back();
                }
            }
        }
        
        return result;
    }
};
