class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
       int m = matrix.size();
       int n = matrix[0].size();
       int maxrows = 0;
       for(auto& currrow  : matrix){
        vector<int> inverted(n);

       for(int col = 0 ; col < n ; col++){
          inverted[col] = currrow[col] == 0 ? 1 : 0;
       }

       int count = 0;
       for(auto &row  : matrix){
        if(row == currrow || row == inverted){
            count++;
        }
       }
       maxrows = max(maxrows , count);
       }
    return maxrows;
    }
};
