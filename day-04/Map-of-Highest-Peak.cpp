class Solution {
public:
    std::vector<std::vector<int>> highestPeak(std::vector<std::vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        std::vector<int> dirs = {0, 1, 0, -1, 0};
        std::vector<std::vector<int>> ans(m, std::vector<int>(n, -1));
        std::deque<std::pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    q.push_back({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop_front();

            for (int k = 0; k < 4; k++) {
                int x = i + dirs[k];
                int y = j + dirs[k + 1];

                if (x < 0 || x == m || y < 0 || y == n || ans[x][y] != -1) {
                    continue;
                }

                ans[x][y] = ans[i][j] + 1;
                q.push_back({x, y});
            }
        }

        return ans;
    }
};
