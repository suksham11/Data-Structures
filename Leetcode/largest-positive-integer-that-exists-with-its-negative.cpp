class Solution {
public:
    int findMaxK(vector<int>& nums) {
      int maxk = -1;
      unordered_set<int> numSet(nums.begin() , nums.end());

      for(int num : nums){
        if(numSet.count(-num)){
            maxk = max(maxk, num);
        }
      }
      return maxk;
    }
};
