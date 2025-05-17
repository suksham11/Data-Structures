class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        long long totalsum = 0;
       
        for(int i=0 ; i<m ; ++i){
            for(int j=0; j<n ; ++j){
                totalsum += grid[i][j];
            }
        }
        if(totalsum % 2 != 0) return false;
        
        long long rowsum = 0;
        for(int i=0 ; i<m-1; ++i){
            for(int j=0 ; j<n ; ++j){
                rowsum += grid[i][j];
            }
            if(rowsum * 2 == totalsum) 
              return true;
        }
        vector<long long> colSums(n,0);
        for(int i=0 ; i<m ; ++i){
            for(int j=0 ; j<n ; ++j){
                colSums[j] += grid[i][j];
            }
        }
        long long colSum = 0;
        for(int j=0 ; j<n-1; ++j){
            colSum += colSums[j];
            if(colSum * 2 == totalsum)
              return true;
        }
        return false;
    }
};
