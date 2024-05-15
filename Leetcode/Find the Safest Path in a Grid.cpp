class Solution {
public:
    vector<int> row = {0,0,-1,1};
    vector<int> col = {-1,1,0,0};
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& score, int n){
        queue<pair<int, int>> q;

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j]){
                    score[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto t = q.front();
            q.pop();

            int x = t.first, y = t.second;
            int s = score[x][y];
            for(int i=0 ; i<4; i++){
                int newx = x  + row[i];
                int newy = y  + col[i];

                if(newx >= 0 && newx<n && newy >=0 && newy < n && score[newx][newy] > 1+s){
                  score[newx][newy] = 1 + s;
                q.push({newx , newy});
            }
        }
        }
    }



    int maximumSafenessFactor(vector<vector<int>>& grid) {
     ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
     int n = grid.size();
     if(grid[0][0] || grid[n-1][n-1]) return 0;
     vector<vector<int>> score(n, vector<int>(n,INT_MAX));
     bfs(grid, score , n);
     vector<vector<bool>> vis(n, vector<bool>(n,false));
     priority_queue<pair<int, pair<int, int>>>pq;
     pq.push({score[0][0] , {0,0}});

     while(!pq.empty()){
        auto temp = pq.top().second;
        auto safe = pq.top().first;
        pq.pop();

        if(temp.first == n-1 && temp.second == n-1) return safe;
        vis[temp.first][temp.second] = true;

        for(int i=0 ; i<4; i++){
            int newx = temp.first + row[i];
            int newy = temp.second + col[i];

            if(newx >= 0 && newx < n && newy >=0 && newy < n && !vis[newx][newy]){
                int s = min(safe, score[newx][newy]);
                pq.push({s, {newx , newy}});
                vis[newx][newy] = true;
            }
        }
     }
     return -1;
    }
};
