class Solution {
public:
    int trapRainWater(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        vector<vector<int>> vis(R,vector<int>(C,0));
        priority_queue<pair<int, pair<int, int>>,vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int,int>>>>pq;
        int vol = 0;

        for(int i=0 ; i<R; i++){
            for(int j=0 ; j<C ; j++){
            if(i==0 || i==R-1 || j==0 || j==C-1){
                pq.push({grid[i][j], {i,j}});
                vis[i][j] = true;
            }
        }
    }
    int minbdht = 0;
    while(!pq.empty()){
        int currht = pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        minbdht = max(currht, minbdht );
        pq.pop();
        int dr[4] = {0,0,-1,1};
        int dc[4] = {1,-1,0,0};
        for(int i=0 ; i<4 ; i++){
            int rr = r+dr[i];
            int cc = c+dc[i];
            if(rr >= 0 && rr<R && cc>=0 && cc<C && vis[rr][cc] == false){
                pq.push({grid[rr][cc], {rr,cc}});
                vis[rr][cc] = true;
                if(grid[rr][cc] < minbdht){
                    vol += minbdht - grid[rr][cc];
                }
            }
        }
    }
        return vol;
    }
};
