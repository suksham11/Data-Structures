class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int  n = arr.size();
        vector<int> dp(n+1 , 0);
        for(int i=0 ; i<n ; i++){
            int currmax = 0 , currsum = 0;
            for(int j=i ; j>= max(0,i-k+1)  ; j--){
                currmax = max(currmax ,arr[j]);

                int cur = currmax * (i-j+1) + dp[j];

                currsum = max(currsum , cur);
            }
            dp[i + 1] = currsum ;
        }
        return dp[n];
    }
};
