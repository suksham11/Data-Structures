class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int, TreeNode*> res;
        unordered_set<int> to_delete_set(to_delete.begin() , to_delete.end());
        res[root->val] = root;

        function<void(TreeNode* , TreeNode*, bool)> recursion = [&](TreeNode* parent,
        TreeNode* curr , bool isleft){
            if(curr == nullptr) return;

            recursion(curr , curr->left, true);
            recursion(curr, curr->right , false);
            if(to_delete_set.find(curr->val) != to_delete_set.end()){
                if(res.find(curr->val) != res.end()){
                    res.erase(curr->val);
                }

                if(parent){
                    if(isleft){
                        parent->left = nullptr;

                    }
                    else{
                        parent->right = nullptr;
                    }
                }
                if(curr->left){
                    res[curr->left->val] = curr->left;
                }
                if(curr->right){
                    res[curr->right->val] = curr->right;
                }
            }
        };
        recursion(nullptr, root , false);
        vector<TreeNode*> result;
        for(auto& pair : res){
            result.push_back(pair.second);
        }
        return result;
    }
};
