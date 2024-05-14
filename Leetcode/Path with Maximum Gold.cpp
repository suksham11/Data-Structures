class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
      
        int maxgold = 0;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
              if(grid[i][j] > 0){
                int currentgold = dfs(grid, i, j , m , n);
                maxgold = max(maxgold , currentgold);
              }
            }
        }
        return maxgold;
    }

private:
    int dfs(vector<vector<int>>& grid , int i, int j, int m , int n){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] == 0){
            return 0;
        }

        int original = grid[i][j];
        grid[i][j] = 0;
          
        int up     =  dfs(grid, i-1 , j , m , n);
        int down   =  dfs(grid, i+1 , j, m , n);
        int left   =  dfs(grid, i , j-1, m , n);
        int right  =  dfs(grid, i , j+1 , m , n);

        grid[i][j] = original;


        return original + max({up, down , left , right});
    }
};
