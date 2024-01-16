class Solution {
public:
    int incremovableSubarrayCount(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<std::vector<int>> subarrays;

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                std::vector<int> temp;
                for (int hi = 0; hi < n; ++hi) {
                    if (hi < i || hi > j) {
                        temp.push_back(nums[hi]);
                    }
                }
                subarrays.push_back(temp);
            }
        }

        int ans = 0;
        for (auto subarray : subarrays) {
            if (isIncreasing(subarray)) {
                ans++;
            }
        }

        return ans;
    }

private:
    bool isIncreasing(const std::vector<int>& arr) {
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] <= arr[i - 1]) {
                return false;
            }
        }
        return true;
    }
};