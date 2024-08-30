#include <vector> 
using namespace std;

class Solution {
public:
    typedef long long ll;
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<pair<int, int>>> g(n);
        vector<long long> d(n, LLONG_MAX);

        for(int i=0 ; i<edges.size() ; ++i){
           auto& e = edges[i];
           if(e[2] == -1){
            continue;
           }
           int u = e[0] , v = e[1] , w = e[2];
           g[u].push_back({v,w});
           g[v].push_back({u,w});
        }

        auto bfs = [&](int start){
            vector<long long> dist(n, LLONG_MAX);
            queue<int> q;
            dist[start] = 0;
            q.push(start);
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(auto& p : g[u]){
                    int nxt = p.first, w = p.second;
                    if(dist[nxt] > dist[u] + w){
                        dist[nxt] = dist[u] + w;
                        q.push(nxt);
                    }
                }
            }
            return dist;
        };

        d = bfs(source);

        if(d[destination] < target){
            return {};
        }

        if(d[destination] == target){
            for(auto& e : edges){
                if(e[2] == -1){
                    e[2] = 1e9;
                }
            }
            return edges;
        }

        for(int i=0 ; i<edges.size() ; ++i){
            auto& e = edges[i];
            int u = e[0] , v = e[1] , w = e[2];
            if(w == -1){
                e[2] = 1;
                g[u].push_back({v, 1});
                g[v].push_back({u, 1});

                d = bfs(source);

                if(d[destination] <= target){
                    e[2] += (target - d[destination]);
                    for(int j=i+1 ; j<edges.size() ; ++j){
                        if(edges[j][2] == -1){
                            edges[j][2] = 1e9;
                        }
                    }
                    return edges;
                }
            }
        }
        return {};
    }
};
