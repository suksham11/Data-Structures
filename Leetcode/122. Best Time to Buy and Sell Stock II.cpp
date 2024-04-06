class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int maxprofit = 0;
    int n = prices.size();
    for(int i=1 ; i<n ; i++){
        int diff = prices[i] - prices[i-1];
        maxprofit = max(maxprofit , maxprofit + diff);
    }
    return maxprofit;
    }
};
