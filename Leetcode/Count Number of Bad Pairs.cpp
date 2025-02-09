class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
      long long badpairs = 0;
      int n = nums.size();
      unordered_map<int, int> diffcount;
      for(int i=0 ; i<n ; i++){
        int diff = i - nums[i];

        //count of previous pos with same difference 
        int goodpairscount = diffcount[diff];
        
        // total possible pairs minus good pairs
        badpairs +=  i - goodpairscount;

        //update count of position with diff
        diffcount[diff] = goodpairscount + 1;
      }
      return badpairs;
    }
};
