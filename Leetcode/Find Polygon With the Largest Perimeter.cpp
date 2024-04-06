class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        long long perimeter = 0;
        long long remainingsidesum = 0;

        for(int i=0 ; i<n ; i++){
            if(nums[i] < remainingsidesum){
                perimeter = remainingsidesum +  nums[i];
            }
            remainingsidesum  += nums[i];
        }
        return perimeter == 0 ? -1 : perimeter;
    }
};
