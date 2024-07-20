class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowsum, vector<int>& colsum) {
        int m = rowsum.size() , n = colsum.size();
        vector<vector<int>> vec(m, vector<int>(n,0));
        int i=0 , j=0;
        while(i<m && j<n){
            vec[i][j] = min(rowsum[i], colsum[j]);

            rowsum[i] -= vec[i][j];
            colsum[j] -= vec[i][j];

            if(rowsum[i] == 0){
                i++;
            }

            if(colsum[j] == 0){
                j++;
            }
        }
        return vec;
    }
};
