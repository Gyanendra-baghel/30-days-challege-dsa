class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int output = 0;
        int start = 0;

        for (int end = 0; end < s.size(); ++end) {
            maxCost -= abs(s[end] - t[end]);

            // If maxCost becomes negative, move the window forward
            while (maxCost < 0) {
                maxCost += abs(s[start] - t[start]);
                ++start;
            }

            // Update the maximum length of the substring
            output = max(output, end - start + 1);
        }

        return output;
    }
};
