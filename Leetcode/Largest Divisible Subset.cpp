class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        vector<int> t(n, 1);

        vector<int> prev_ind(n , -1);

        int Lastchosen = 0;
        int maxl = 1;

        for(int i=1 ; i<n ; i++){
            for(int j=0 ; j<i ; j++){
             if(nums[i] % nums[j] == 0){
                if(t[i] < t[j] + 1){
                    t[i] = t[j] + 1;
                    prev_ind[i] = j;
                } 
                if(t[i] > maxl){
                    maxl = t[i];
                    Lastchosen = i;
                }
             }
            }
        }
    vector<int> result;
    while(Lastchosen != -1){
        result.push_back(nums[Lastchosen]);
        Lastchosen = prev_ind[Lastchosen];
    }
    return result;
    }
};
