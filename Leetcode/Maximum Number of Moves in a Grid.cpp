class Solution {
public:
    int m , n;
    vector<int> directions = {-1, 0 , 1};
    int DFS(int row, int col , vector<vector<int>>& grid , vector<vector<int>>& t){
      
      if(t[row][col] != -1){
        return t[row][col];
      }

      int moves = 0;
      for(int &dir : directions){
        int newrow = row+dir;
        int newcol = col+1;

        if(newrow >= 0 && newrow < m && newcol>=0 && newcol < n && grid[newrow][newcol] > grid[row][col]){
            moves = max(moves , 1+DFS(newrow , newcol, grid, t));
        }
      }
      return t[row][col] = moves;
    }


    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int result = 0;
        vector<vector<int>> t(m , vector<int>(n, -1));
        for(int row = 0 ; row < m ; row++){
            result = max(result , DFS(row , 0 , grid, t));
        }
        return result;
    }
};
