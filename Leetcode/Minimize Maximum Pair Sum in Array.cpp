class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int maxpair = 0;
        sort(nums.begin() , nums.end());
        int n = nums.size();
        for(int i=0; i<n/2 ; ++i){
            int pairsum = nums[i] + nums[n-i-1];
            maxpair = max(maxpair, pairsum);  
        }
    return maxpair;
    }
};
