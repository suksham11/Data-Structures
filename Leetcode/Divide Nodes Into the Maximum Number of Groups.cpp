class Solution {
public:
    bool isBipartite(unordered_map<int, vector<int>> &adj, int curr , vector<int>& colors , int currcolor){
        colors[curr] = currcolor;
        for(int &ngbr : adj[curr]){
            if(colors[ngbr] == colors[curr]){
                return false;
            }
            if(colors[ngbr] == -1){
                if(isBipartite(adj , ngbr, colors , 1- currcolor) == false){
                    return false;
                }
            }
        }
        return true;
    }

    int bfs(unordered_map<int, vector<int>> &adj, int currnode, int n){
        queue<int> q;
        vector<bool> visited(n , false);
        q.push(currnode);
        visited[currnode] = true;

        int level = 1; // maxgroup in that component
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int curr = q.front();
                q.pop();
                for(int &ngbr: adj[curr]){
                    if(visited[ngbr])
                      continue;

                    q.push(ngbr);
                    visited[ngbr] = true;
                }
            }
            level++; // 1 extra will increment
        }
        return level-1;
    }

    int getmaxfromeachcomp(unordered_map<int, vector<int>>&adj , int curr, vector<bool>& visited, vector<int>& levels){
        int maxgrp = levels[curr];
        visited[curr] = true;
        for(int &ngbr : adj[curr]){
            if(!visited[ngbr]){
                maxgrp = max(maxgrp , getmaxfromeachcomp(adj, ngbr, visited, levels));
            }
        }
        return maxgrp;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for(auto& edge : edges){
            int v = edge[0] - 1; // converting 0-based
            int u = edge[1] - 1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Bipartite graph
        vector<int> colors(n, -1);
        for(int node = 0; node < n ; node++){
           if(colors[node] == -1){
            if(isBipartite(adj, node , colors, 1) == false){
                return -1;
            }
           }
        }
        
        // BFS karke max 
     
        vector<int> levels(n,0);
        for(int node = 0 ; node < n ; node++){
            levels[node] = bfs(adj, node,  n);
        }
        int maxgroup = 0;
        vector<bool> visited(n, false);
        for(int node = 0 ; node < n ; node++){
           if(!visited[node]){
             maxgroup += getmaxfromeachcomp(adj, node , visited , levels);

             
           }
        }
        return maxgroup;
    }
};
