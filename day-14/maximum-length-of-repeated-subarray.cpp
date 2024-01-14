class Solution {
public:
    int findLength(vector<int>& s1, vector<int>& s2) {
        int x=s1.size();
        int y=s2.size();
        vector<vector<int>> dp(x+1,vector<int>(y+1,0));
        int ans = 0;

        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];

                    ans=max(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
    
};

