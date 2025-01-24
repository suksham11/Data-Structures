class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int, bool> memo;
        int n = graph.size();
        vector<int> res;
        for(int i=0 ; i<n ; i++){
            if(dfs(i, graph , memo)){
                res.push_back(i);
            }
        }
        return res;
    }
    private:
     bool dfs(int node , vector<vector<int>>& graph, unordered_map<int, bool>& memo){
     if(memo.find(node) != memo.end()){
        return memo[node];
     }
     memo[node] = false;
     for(int neighbor : graph[node]){
        if(!dfs(neighbor, graph , memo)){
            return false;
        }

     }
     memo[node] = true;
     return true;
     }
};
