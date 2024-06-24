class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int curr = 0, res = 0 , n = nums.size();
        for(int i=0 ; i<n ; i++){
            if(i>=k && nums[i-k] > 1){
                curr--;
                nums[i-k] -= 2;
            }
            if(curr % 2 == nums[i]){
                if(i+k > n) return -1;
                nums[i] += 2;
                curr++;
                res++;
            }
        }
        return res;
    }
};
