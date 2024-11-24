class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalsum = 0;
        int minabsval = INT_MAX;
        int negativecount = 0;
        for(auto &row : matrix){
            for(int val : row){
                totalsum += abs(val);
                if(val < 0){
                    negativecount++;
                }
                minabsval = min(minabsval , abs(val));
            }
        }
        if(negativecount % 2 != 0){
         totalsum -= 2 * minabsval;
        }
        return totalsum;
    }
};
