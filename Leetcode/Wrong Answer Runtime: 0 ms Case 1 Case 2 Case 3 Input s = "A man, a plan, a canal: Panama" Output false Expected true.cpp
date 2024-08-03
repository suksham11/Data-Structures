class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
       unordered_map<int, int> arrfreq;
       for(int num : arr){
        arrfreq[num]++;
       }

       unordered_map<int, int> targetfreq;
       for(int num : target){
        targetfreq[num]++;
       }

       if(arrfreq.size() != targetfreq.size()){
        return false;
       }

       for(auto it: arrfreq){
        if(targetfreq[it.first] != it.second){
            return false;
        }
       }
    return true;
    }
};
