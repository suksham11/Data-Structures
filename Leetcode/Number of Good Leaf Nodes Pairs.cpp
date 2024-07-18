class Solution {
public:
    void makegraph(TreeNode* root, TreeNode* prev, unordered_map<TreeNode*, vector<TreeNode*>> & adj, 
        unordered_set<TreeNode*>& st){
            if(root == NULL){
                return;
            }

            if(root->left == NULL && root->right == NULL){
                st.insert(root);
            }

            if(prev != NULL){
                adj[root].push_back(prev);
                adj[prev].push_back(root);
            }
            
            makegraph(root->left, root, adj, st);
            makegraph(root->right, root, adj , st);
        }


    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode* , vector<TreeNode*>> adj;
        unordered_set<TreeNode*> st;

        makegraph(root, NULL , adj , st);

        int count = 0;
        for(auto &leaf : st){

            queue<TreeNode*> que;
            unordered_set<TreeNode*> visited;
            que.push(leaf);
            visited.insert(leaf);


            for(int level = 0 ; level <= distance ; level++){
            int size = que.size();
            while(size--){  // level process
            TreeNode* curr = que.front();
            que.pop();

            if(curr != leaf && st.count(curr)){ 
                count++;
            }
            for(auto &ngbr : adj[curr]){
                if(!visited.count(ngbr)){
                   que.push(ngbr);
                   visited.insert(ngbr);
                }
            }
          }
         }
        }
        return count/2;
    }
};
