class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& candidates, int target, int i, int currsum, vector<int> temp){
        if(currsum > target){
            return;
        }
        if(i == candidates.size()){
            if(currsum == target){
            ans.push_back(temp);
            }
        return;
        }

        //inclusion 
        currsum += candidates[i];
        temp.push_back(candidates[i]);
        helper(candidates, target, i, currsum , temp);
        currsum -= candidates[i];
        temp.pop_back();
   
        //exclusion
        helper(candidates, target, i+1, currsum, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        helper(candidates, target, 0, 0 , temp);
        return ans;
    }
};
