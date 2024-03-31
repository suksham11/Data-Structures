class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0;
        int badind = -1, leftind = -1 , rightind = -1;
        for(int i=0 ;  i<nums.size() ; ++i){
            if(!(minK <= nums[i] && nums[i] <= maxK)){
                badind = i;
            }

            if(nums[i] == minK){
                leftind = i;
            }
            if(nums[i] == maxK) {
                rightind = i;
            }
            res += max(0 , min(leftind , rightind) - badind);
        }
    return res;
    }
};
