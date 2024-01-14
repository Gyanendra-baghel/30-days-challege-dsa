class Solution {
    static bool cmp(pair<string, int>& a, pair<string, int>& b) {
        if (a.second == b.second) {
            return a.first.compare(b.first) < 0;
        }
        return a.second > b.second;
    }

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for (auto word : words) {
            m[word]++;
        }
        vector<pair<string, int>> temp;
        for (auto it : m) {
            temp.push_back(make_pair(it.first, it.second));
        }

        sort(temp.begin(), temp.end(), cmp);

        vector<string> output(k);
        for (int i = 0; i < k; i++) {
            output[i] = temp[i].first;
        }
        return output;
    }
};
