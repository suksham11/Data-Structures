class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> storepairs;
        for(int i=0 ; i<nums.size() ;  ++i){
            int mapped = 0;
            int temp = nums[i];
            int place = 1;
            if(temp == 0){
                storepairs.push_back({mapping[0], i});
                continue;
            }
            while(temp != 0){
                mapped = place* mapping[temp%10] + mapped;
                place*=10;
                temp /= 10;
            }
            storepairs.push_back({mapped , i});
        }
        sort(storepairs.begin() , storepairs.end());
        vector<int> ans;
        for(auto pair: storepairs){
            ans.push_back(nums[pair.second]);
        }
        return ans;
    }
};
