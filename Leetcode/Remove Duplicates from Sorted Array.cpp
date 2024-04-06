class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
       /* vector<int> ans;
        unordered_map<int, int> mp;
        for(int i=0 ; i<n ; i++){
            if(mp.find(nums[i]) == mp.end()){
                ans.push_back(nums[i]);
                mp[nums[i]]++;
            }
            
        }
        nums = ans;
    return ans.size();*/
    //two pointer
    int j=1;
    for(int i=1; i<n  ; i++ ){
        if(nums[i] != nums[i-1]){
            nums[j] = nums[i];
            j++;
        }
    }
    return j;
    }
};
