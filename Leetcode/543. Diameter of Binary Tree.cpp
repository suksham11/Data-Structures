class Solution {
public:
    int ans = 0;
    int height(TreeNode* root){
        if(!root) return 0;
        int lheight = height(root->left);
        int rheight = height(root->right);
        ans = max(ans , 1 + lheight + rheight);
        return 1 + max(lheight,  rheight);
    }
    

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        height(root);
        return ans-1;
    }
};
