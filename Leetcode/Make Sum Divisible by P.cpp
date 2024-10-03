class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
       int n = nums.size();
       int t = 0;
       for(int n : nums){
        t = (t+n)%p;
        
       }
       int target = t % p;
       if(target == 0) return 0;

       unordered_map<int, int> modmap;
       modmap[0] = -1;
       int csum = 0, minlen = n;
       for(int i=0 ; i<n ; ++i){
        csum = (csum + nums[i]) % p;
        int needed = (csum - target + p) % p;

        if(modmap.find(needed) != modmap.end()){
            minlen = min(minlen , i- modmap[needed]);
        }
        modmap[csum] = i;
       }
       return minlen ==n ? -1 : minlen;
    }
};
