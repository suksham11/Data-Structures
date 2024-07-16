class Solution {
public:
    TreeNode* lowestcommonancestor(TreeNode* root , int src , int dest){
        if(!root) 
           return NULL;

        if(root->val == src || root->val == dest)
          return root;

        TreeNode* l = lowestcommonancestor(root->left , src,  dest);
        TreeNode* r = lowestcommonancestor(root->right , src, dest);

        if(l && r) return root;

        return  l ? r : r;

    }
   

    findpath(TreeNode* lca , int target ,string& pathg)


    string getDirections(TreeNode* root, int startvalue, int destvalue) {
        TreeNode* LCA = lowestcommonancestor(root, startvalue , destvalue);
        string lcatosrc = "";
        string lcatodest = "";

        findpath(lca , startvalue , destvalue);
        findpath(lca , destvalue , startvalue);

        string result = "";

        for(int i=0 ; i<lcatosrc.length() ; i++){
            result.push_back('U');
        }

        result += lcatodest;

        return result;
    }
};
