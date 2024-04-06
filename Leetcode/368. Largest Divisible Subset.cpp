class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        vector<int>groupsize (n,1) , prevele(n,-1);
        int maxidx = 0;

        for(int i=0 ; i<n; ++i){
            for(int j=0 ; j<i ; ++j){
                if(nums[i] % nums[j] == 0 && groupsize[i] < groupsize[j]+1){
                    groupsize[i] = groupsize[j] + 1;
                    prevele[i] =  j;
                }
            }
            if(groupsize[i] > groupsize[maxidx]){
                maxidx = i;
            }
        }
        vector<int> res;
        for(int i=maxidx ; i!=-1 ; i=prevele[i]){
            res.insert(res.begin() , nums[i]);
        }
        return res;
    }
};
