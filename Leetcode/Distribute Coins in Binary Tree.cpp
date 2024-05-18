class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        dfs(root , moves);
        return moves;
    }

private: 
    int dfs(TreeNode* node, int& moves){
        if(!node){
            return 0;
        }

        int left_moves = dfs(node->left, moves);
        int right_moves = dfs(node->right, moves);

        moves += abs(left_moves) + abs(right_moves);

        return node->val - 1 + left_moves + right_moves;
        
    }
};
