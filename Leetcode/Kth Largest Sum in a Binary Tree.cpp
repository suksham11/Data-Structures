class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long> pq;
        queue<TreeNode*> bfsqueue;
        bfsqueue.push(root);
        while(!bfsqueue.empty()){
            long size = bfsqueue.size();
            long sum = 0;
            for(int i=0; i<size ; i++){
                TreeNode* poppedNode = bfsqueue.front();
                bfsqueue.pop();
                sum += poppedNode->val;
                if(poppedNode->left != nullptr){
                  bfsqueue.push(poppedNode->left);
            }
            if(poppedNode->right != nullptr){
                bfsqueue.push(poppedNode->right);
            }
        }
        pq.push(sum);
        } 
        if(pq.size() < k) return -1;
        for(int i=0 ; i<k-1 ; i++)
         pq.pop();
        return pq.top();
    }
};
