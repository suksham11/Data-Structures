class Solution {
private:
    void update(vector<int>& bits , int x , int change){
        for(int i=0 ; i<32; i++){
            if((x >> i) & 1){
                bits[i] += change;
            }
        }
    }

    int bitsToNum(vector<int>& bits){
        int res = 0;
        for(int i=0 ; i<32 ; i++){
            if(bits[i]){
                res |= 1 << i;
            }
        }
        return res;
    }
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
      int e;
      int n = nums.size(), res = n+1;
      vector<int> bits(32);
      for(int s=0 , end=0 ; end<n ; end++){
        update(bits,  nums[end] , 1);
        while(s <= end && bitsToNum(bits) >= k){
            res = min(res , end-s+1);
            update(bits, nums[s++], -1);
        }
      }
      return res != n+1 ? res : -1;
    }
};
