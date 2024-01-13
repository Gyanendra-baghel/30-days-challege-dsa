class Solution {
public:
    int findLength(vector<int>& s1, vector<int>& s2) {
        int x=s1.size();
        int y=s2.size();
        vector<vector<int>> dp(x+1,vector<int>(y+1,0));
        //a 2d vector of size x+1 and y+1 
        for(int j=0;j<=y;j++){
            dp[0][j]=0;
        }
        //storing value 0 for 1st column
        for(int i=0;i<=x;i++){
            dp[i][0]=0;
            
        }
        
        int ans = 0;
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                //if vectors consecutive element are matched the adding 1 to previous //diagonally stored value
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];

                    ans=max(ans,dp[i][j]);
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return ans;
    }
    
};

