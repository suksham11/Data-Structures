class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(q.size()){
            int cnt = q.size(), prev = level % 2 == 0 ? 0 : INT_MAX;
            while(cnt--){
                auto node = q.front();
                q.pop();
                if(level%2 == 0){
                    if(node->val % 2 == 0 || node->val <= prev) return false;
                }   
                else{
                    if(node->val % 2 || node->val >= prev) return false;
                }
                prev = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ++level;
        }
        return true;
        
    }
};
