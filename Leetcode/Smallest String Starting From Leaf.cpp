class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        queue<pair<TreeNode*, string>> que;
        que.push({root, string(1, char(root->val + 'a'))});
        string result = "";

        while(!que.empty()){
            auto[node , curr] = que.front();
            que.pop();
            if(!node->left && !node->right){
                if(result == "" || result > curr){
                    result = curr;
                }
            }
            if(node->left){
                que.push({node->left, string(1, char(node->left->val +  'a')) + curr});
            }
            if(node->right){
                que.push({node->right, string(1, char(node->right->val + 'a')) + curr});
            }
        }
    return result;
    }
};
