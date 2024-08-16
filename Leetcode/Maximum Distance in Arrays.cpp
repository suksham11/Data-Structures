class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int Min = arrays[0].front();
        int Max = arrays[0].back();

        int result = 0;
        for(int i=1 ; i<arrays.size() ; i++){
            int currMin = arrays[i].front();
            int currMax = arrays[i].back();

            result = max({result ,  abs(currMin - Max), abs(currMax - Min)});
            Max = max(Max , currMax);
            Min = min(Min , currMin);
        }
    return result;
    }
};
