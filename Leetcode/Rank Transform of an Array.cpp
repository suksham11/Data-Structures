class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int> numtorank;
        set<int> nums(arr.begin() , arr.end());
        int rank = 1;
        for(auto num : nums){
            numtorank[num] = rank;
            rank++;
        }
        for(int i=0 ; i<arr.size() ; i++){
            arr[i] = numtorank[arr[i]];
        }
        return arr;
    }
};
