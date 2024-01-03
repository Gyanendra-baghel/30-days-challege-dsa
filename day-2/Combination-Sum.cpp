class Solution {
    void findCombinations(int k, int n, int start, vector<int>& current, vector<vector<int>>& result) {
        if (k == 0 && n == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i <= 9; ++i) {
            if (i > n) break;
            current.push_back(i);
            findCombinations(k - 1, n - i, i + 1, current, result);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> combinations;
        vector<int> current;

        findCombinations(k, n, 1, current, combinations);

        return combinations;
    }
};