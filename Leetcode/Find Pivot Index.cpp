class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int tsum = 0;
        int lsum = 0;
        for(int ele: nums)
           tsum += ele;
        for(int i=0 ; i<nums.size() ; lsum += nums[i++])
            if(lsum * 2 == tsum - nums[i])
               return i;
        return -1;
    }
};
