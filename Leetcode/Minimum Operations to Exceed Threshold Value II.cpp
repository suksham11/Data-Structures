class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(auto n:nums) pq.push(n);
        int ans = 0;
        while(pq.size() && pq.top() < k){
            long minnum = pq.top(); pq.pop();
            long nextminnum = pq.top(); pq.pop();
            pq.push(2*minnum + nextminnum);
            ans++;
        }
        return ans;
    }
};
