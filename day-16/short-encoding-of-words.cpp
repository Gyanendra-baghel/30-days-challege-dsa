class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> s1(words.begin(), words.end());
        set<string> s2 = s1;

        for(auto parts: s1) {
            for(int i = 1; i< parts.size(); i++) {
                s2.erase(parts.substr(i));
            }
        }
        int count = 0;
        for(auto parts: s2) {
            count += parts.size()+1;
        }
        return count;
    }
};