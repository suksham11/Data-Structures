class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        if(root == nullptr) return result;
        stack<Node*> nodestack;
        nodestack.push(root);
        while(!nodestack.empty()){
            Node* currentNode = nodestack.top();
            nodestack.pop();
            result.push_back(currentNode->val);
            for(Node* child: currentNode->children) nodestack.push(child);

        }
        reverse(result.begin() , result.end());
        return result;
    }
};
