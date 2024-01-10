class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> output(nums.size());

        sort(nums.begin(), nums.end());

        int p1 = 1, p2 = nums.size()-1;

        while(p1 < nums.size()) {
            output[p1] = nums[p2];
            p1+=2;
            p2--;
        }

        p1 = 0;

        while(p1 < nums.size()) {
            output[p1] = nums[p2];
            p1+=2;
            p2--;
        }

        nums = output;
    }
};