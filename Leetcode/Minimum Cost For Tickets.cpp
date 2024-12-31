class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lstday = days[days.size() -  1];
        vector<int> dp(lstday + 1, 0);
        int i=0;
        for(int day = 1; day <= lstday ; day++){
            if(day < days[i]){
                dp[day] = dp[day - 1];
            }else{
                i++;
                dp[day] = min({dp[day-1] + costs[0], dp[max(0, day - 7)] + costs[1] , dp[max(0, day - 30)]+ costs[2]});
            }
        }
        return dp[lstday];
    }
};
