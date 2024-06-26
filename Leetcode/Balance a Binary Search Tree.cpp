class Solution {
public:
    void intraverse(TreeNode*root, vector<int>& inorder){
        if(!root) return;
        intraverse(root->left , inorder);
        inorder.push_back(root->val);
        intraverse(root->right, inorder);
    }
   

    TreeNode *contructBalancedBst(vector<int>& in , int low , int high){
        if(low>high) return NULL;
        int mid = low + (high - low) /2;
        TreeNode *curr = new TreeNode(in[mid]);
        curr->left = contructBalancedBst(in , low , mid-1);
        curr->right = contructBalancedBst(in , mid+1 , high);
        return curr; 
 
    }

    TreeNode* balanceBST(TreeNode* root) {
      
        if(!root ) return NULL;
        vector<int> inorder;
        intraverse(root, inorder);
        return contructBalancedBst(inorder, 0 ,inorder.size()-1);
    }
};
