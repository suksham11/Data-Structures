class Solution {
public:
    long long maximumValueSum(vector<int>& v, int k, vector<vector<int>>& edges) {
        long long total = accumulate(v.begin() , v.end() , 0ll);

        long long totaldiff = 0;
        long long diff;
        int positive = 0;
        long long min_abs_diff = numeric_limits<int>:: max();
        for(auto p : v){
            diff = (p^k) - p;
            if(diff > 0 ){
                totaldiff += diff;
                positive++;
            }
            min_abs_diff = min(min_abs_diff , abs(diff));
        }
        if(positive % 2 == 1){
            totaldiff = totaldiff - min_abs_diff;
        }
        return total + totaldiff;
    }
};
