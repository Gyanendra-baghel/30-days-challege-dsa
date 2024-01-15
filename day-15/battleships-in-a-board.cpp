class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        if(n == 0) {
            return 0;
        }
        int m = board[0].size();
        if(m == 0) {
            return 0;
        }
        int i, j, left, top;
        int total = 0;
        for(i = 0; i < n; i++) {
            top = i - 1;
            for(j = 0; j < m; j++) {
                left = j - 1;
                if(board[i][j] == 'X' && (left < 0 || board[i][left] == '.') && (top < 0 || board[top][j] == '.')) {
                    total++;
                }
            }
        }

        return total;
    }
};