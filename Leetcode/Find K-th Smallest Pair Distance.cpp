class Solution {
public:
    int slidingwindow(vector<int>& nums, int D){
        int i=0 , j=1;
        int n= nums.size();
        int paircount = 0;

        while(j<n ){
            while(nums[j] - nums[i] > D){
                i++;
            }

            paircount += (j-i);
            j++;
        }
        return paircount;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        int l = 0;
        int r = nums[n-1] - nums[0];

        int result = 0;
        
        while(l <= r){
            int mid = l + (r-l) / 2;
            int countpair = slidingwindow(nums, mid);
            if(countpair < k){
                l = mid + 1;
            }
            else{
                result = mid;
                r = mid - 1;
            }
        }

    return result;
    }
};
