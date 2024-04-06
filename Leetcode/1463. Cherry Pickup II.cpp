class Solution {
public:
    int dp[3] = {0, -1, 1};
    int t[71][71][71];

    int dfs(vector<vector<int>>& grid, int i, int c1, int c2, int m, int n){
        if(i == m) return 0;
        if(c1<0 || c2<0 || c1>=n || c2>=n)  return INT_MIN;
        if(t[i][c1][c2] != -1) return t[i][c1][c2];
    

    int maxans = 0;
    for (int k=0; k<3; k++){
        for (int r=0; r<3; r++){
            maxans = max(maxans,  dfs(grid, i+1,  c1+dp[k], c2+dp[r], m, n));
        }
    }
    maxans += (c1 == c2) ? grid[i][c1] : grid[i][c1] + grid[i][c2];
    return t[i][c1][c2] = maxans;    
   }


    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        if(!m) return 0;
        int n = grid[0].size();
        memset(t , -1 , sizeof(t));
        return dfs(grid, 0,  0, n-1, m, n);
    }
};
