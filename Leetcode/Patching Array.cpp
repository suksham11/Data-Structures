class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int cnt = 0, i=0;
        long long maxnum=0;
        while(maxnum<n){
            if(i<nums.size() && nums[i]<=maxnum+1)
                maxnum += nums[i++];
            else{
                maxnum+=maxnum+1,cnt++;
            }
        }
        return cnt;
    }
};
