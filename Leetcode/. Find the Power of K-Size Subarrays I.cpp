class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int length =  nums.size();
        vector<int> result(length - k + 1, -1);
        for(int s = 0 ; s <= length - k ; s++){
            bool isconnect = true;
        
        for(int idx=s ; idx < s+k-1 ; idx++){
            if(nums[idx + 1] != nums[idx] + 1){
                isconnect = false;
                break;
            }
        }
        if(isconnect){
            result[s] = nums[s + k - 1];

        }
        else{
            result[s] = -1;
        }
    }

   return result;
    }
};
