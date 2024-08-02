class Solution {
public:
    int minSwaps(vector<int>& nums) {
       int minimumswaps = INT_MAX;
       int totalones = accumulate(nums.begin() , nums.end() , 0);
       int onescount = nums[0];
       int end = 0;
       for(int start = 0 ; start < nums.size() ; ++start){
        if(start != 0){
            onescount -= nums[start - 1];
        }

        while(end-start+1 < totalones){
            end++;
            onescount += nums[end % nums.size()];
        }
        minimumswaps = min(minimumswaps , totalones - onescount);
       }
       return minimumswaps;
    }
};
