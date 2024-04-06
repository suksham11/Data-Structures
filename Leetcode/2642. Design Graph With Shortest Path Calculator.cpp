lass Graph {
public:
    vector<vector<int>> adjmatrix;
    int N;
    Graph(int n, vector<vector<int>>& edges) {
        N = n;
       adjmatrix = vector<vector<int>>(n, vector<int>(n,1e9));
       for(auto &edge: edges){
           int u = edge[0];
           int v = edge[1];
           int cost = edge[2];

           adjmatrix[u][v] = cost;
       }

       for(int i=0 ; i<n ; i++){
           adjmatrix[i][i] = 0;
       }

       for(int via = 0 ; via<n ; via++){
       for(int i = 0; i<n ; i++){
           for(int j=0 ; j<n ; j++){
               adjmatrix[i][j] = min(adjmatrix[i][j] , adjmatrix[i][via] + adjmatrix[via][j]);
           }
       } 
    }
    }

    
    void addEdge(vector<int> edge) {
         int u = edge[0];
         int v = edge[1];
         int cost = edge[2];


         for(int i=0; i<N ; i++){
             for(int j=0 ; j<N ; j++){
                 adjmatrix[i][j] = min(adjmatrix[i][j], adjmatrix[i][u] + cost + adjmatrix[v][j]);
             }
         }
    }
    
    int shortestPath(int node1, int node2) {
        return adjmatrix[node1][node2] == 1e9 ? -1 : adjmatrix[node1][node2];
    }
};
