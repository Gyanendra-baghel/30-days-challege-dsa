class Solution {
    static bool cmp(pair<char, int>& a, pair<char, int>& b) {
        return a.second > b.second;
    }
public:
    string frequencySort(string s) {
        map<char, int> m;
        for(char c: s) {
            m[c]++;
        }
        vector<pair<char, int>> v;
        for(auto it: m) {
            v.emplace_back(make_pair(it.first, it.second));
        }
        sort(v.begin(), v.end(), cmp);
        
        string temp;
        for(auto it: v) {
            for(int i = 0; i < it.second; i++) {
                temp += it.first;
            }
        }
        return temp;
    }
};