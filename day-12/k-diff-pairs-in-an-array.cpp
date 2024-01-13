class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        set<pair<int, int>> uniquePair;

        sort(nums.begin(), nums.end());

        for(int num: nums) {
            if(map[num+k] == 1) {
                uniquePair.insert(make_pair(num, num+k));
            }
            if(map[num-k] == 1) {
                uniquePair.insert(make_pair(num, num-k));
            }

            map[num] = 1;
        }

        return uniquePair.size();
    }
};