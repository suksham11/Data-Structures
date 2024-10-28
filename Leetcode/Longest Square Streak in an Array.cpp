class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> numset(nums.begin(), nums.end());
        int maxstreak  = -1;

        for(int num : nums){
           if(numset.count(num)){
            long long current = num; 
            int streak = 1;
             
            while(numset.count(current * current) && current * current <= INT_MAX){
                current = current * current;
                streak++;
            }
            if(streak >= 2){
                maxstreak = max(maxstreak, streak);
            }
           }
        }
        return maxstreak;
    }
};
