class Solution {
    int mod = 1e9 + 7;
    
public:
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(3000,vector<int>(k+1,-1));
        return topDownApproach(startPos,endPos,k,dp)%mod;
    }
    long long topDownApproach(int curr, int endPos, int k, vector<vector<int>>& dp){
        if(k == 0){
            return curr==endPos;
        }
        if(dp[999+curr][k] != -1){
            return dp[999+curr][k];
        }
        long long forw = topDownApproach(curr+1,endPos,k-1,dp)%mod;
        long long back = topDownApproach(curr-1,endPos,k-1,dp)%mod;
        return dp[999+curr][k] = (forw+back)%mod;
    }
};