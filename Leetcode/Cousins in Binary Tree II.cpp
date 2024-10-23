class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root == NULL){
            return root;
        }

        queue<TreeNode*> que;
        que.push(root);
        int levelsum = root->val;

        while(!que.empty()){
            int n = que.size();
            int nextlevelsum = 0;

            while(n--){
                TreeNode* curr = que.front();
                que.pop();

                curr->val = levelsum - curr->val;

                int siblingsum = (curr->left != NULL ? curr->left->val : 0);
                siblingsum += (curr->right != NULL ? curr->right->val : 0);

                if(curr->left){
                    nextlevelsum += curr->left->val;
                    curr->left->val = siblingsum;
                    que.push(curr->left);
                }
                if(curr->right){
                    nextlevelsum += curr->right->val;
                    curr->right->val = siblingsum;
                    que.push(curr->right);
                }
            }
            levelsum = nextlevelsum;
        }
        return root;
    }
};
