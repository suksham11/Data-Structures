class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans= 0;
        long long currsum =0 ;
        int begin = 0 , end  = 0;
        unordered_map<int, int> numtoindex;
        while(end < nums.size()){
            int currnum = nums[end];
            int lastocc = (numtoindex.count(currnum) ? numtoindex[currnum] : -1);
            
            while(begin <= lastocc || end-begin+1 > k){
            currsum -= nums[begin];
            begin++;
            }
        numtoindex[currnum] = end;
        currsum += nums[end];
        if(end - begin + 1 == k ){
            ans = max(ans, currsum);
        }
        end++;
        }
    return ans;
    }
    
};
