class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lislength(n, 1);
        vector<int> ldslength(n, 1);

        for(int i=0 ; i<n ; i++){
            for(int j=i-1 ; j>=0 ; j--){
                if(nums[i] > nums[j]){
                    lislength[i] = max(lislength[i] , lislength[j] + 1);
                }
            }
        }

        for(int i=n-1 ; i>=0 ; i--){
            for(int j=i+1 ; j<n ; j++){
                if(nums[i] > nums[j]){
                    ldslength[i] = max(ldslength[i], ldslength[j] + 1);
                }
            }
        }
        int minremovals = INT_MAX;
        for(int i=0 ; i<n ; i++){
            if(lislength[i] > 1 && ldslength[i] > 1){
            minremovals  = min(minremovals, n-lislength[i] - ldslength[i] + 1);
            }
        }
        return minremovals;
    }
};
