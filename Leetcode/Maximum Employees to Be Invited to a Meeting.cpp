class Solution {
public:
    int BFS(int start, unordered_map<int, vector<int>>& adj, vector<bool>& visited) {
        queue<pair<int, int>> que; // {node, path length}
        que.push({start , 0});
        int maxDistance = 0;

        while(!que.empty()){
            auto[currNode , dist] = que.front();
            que.pop();

            for(auto &ngbr : adj[currNode]){
                if(!visited[ngbr]){
                    visited[ngbr] = true;
                    que.push({ngbr , dist+1});
                    maxDistance = max(maxDistance , dist+1);
                }
            }
        }
        return maxDistance;
    }

    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        unordered_map<int, vector<int>> adj;
        for(int i=0 ; i<n ; i++){
            int u = i;
            int v = favorite[i];
            adj[v].push_back(u); // reverse graph so that we can find the path length after traversal
        }

        int longestcycle  = 0;
        int happycouple = 0;  // cycle length2 valo ko kitna milpaega total
        vector<bool> visited(n , false);
        for(int i=0 ; i<n ; i++){
            if(!visited[i]){
                // node abtak currnode
                unordered_map<int, int> mp;
                int currNode = i;
                int currNodecount = 0;
                while(!visited[currNode]){  // until cycle is not detected
                  visited[currNode] = true;
                  mp[currNode] = currNodecount;
                  int NextNode = favorite[currNode]; // favorite node of curr node
                  currNodecount += 1;
                  if(mp.count(NextNode)){
                    int cycleLength = currNodecount - mp[NextNode];
                    longestcycle = max(longestcycle , cycleLength);

                    if(cycleLength == 2){
                        vector<bool> visitedNodes(n, false);
                        visitedNodes[currNode] = true;
                        visitedNodes[NextNode] = true;
                     happycouple += 2 + BFS(currNode, adj, visitedNodes) + BFS(NextNode, adj,  visitedNodes);

                    }
                    break;
                  }
                  currNode = NextNode;
                }
            }
        }
        return max(happycouple , longestcycle);
    }
};
