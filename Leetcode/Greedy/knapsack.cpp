class Solution {
  public:
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        int n=wt.size();
        vector<vector<int>>dp(2,vector<int>(capacity+1,0));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=capacity;j++)
            {
                if(j<wt[i-1])
                dp[1][j]=dp[0][j];
                else
                dp[1][j]=max(val[i-1]+dp[0][j-wt[i-1]],dp[0][j]);
            }
            for(int j=1;j<=capacity;j++)
            swap(dp[0][j],dp[1][j]);
        }
        
        return dp[0][capacity];
    }
};

