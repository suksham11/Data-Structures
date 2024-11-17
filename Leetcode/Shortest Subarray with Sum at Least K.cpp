class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<int, long long>> dq; 
        long long prefixsum = 0;
        int minlength = INT_MAX;
        for(int i=0 ; i<n ; ++i){
            prefixsum += nums[i];

            while(!dq.empty() && prefixsum - dq.front().second >= k){
                minlength = min(minlength, i - dq.front().first);
                dq.pop_front();
            }
            while(!dq.empty()  && dq.back().second >= prefixsum){
                dq.pop_back();
            }
            dq.emplace_back(i , prefixsum);
            if(prefixsum >= k){
                minlength = min(minlength , i+1);
            }
        }
        return minlength == INT_MAX ? -1 : minlength;
    }
};
