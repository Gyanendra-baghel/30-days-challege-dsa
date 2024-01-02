class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        std::vector<int> output;

        for (int i = 0; i < n; i++) {
            std::vector<std::pair<std::string, int>> trimmed;
            int k = queries[i][0];

            for (int j = 0; j < nums.size(); j++) {
                trimmed.push_back({nums[j].substr(nums[j].size() - queries[i][1]), j});
            }

            std::sort(trimmed.begin(), trimmed.end());
            output.push_back(trimmed[k - 1].second);
        }

        return output;
    }
};