class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
       int n = nums.size();
       vector<int> vec = nums;
       sort(begin(vec) , end(vec));
       int groupnum = 0;
       unordered_map<int, int> numtog;
       numtog[vec[0]] = groupnum;
       unordered_map<int, list<int>> grouptolist;
       grouptolist[groupnum].push_back(vec[0]);

       for(int i=1 ; i<n ; i++){
        if(abs(vec[i] - vec[i-1]) > limit){
            groupnum += 1;
        }
        numtog[vec[i]] = groupnum;
        grouptolist[groupnum].push_back(vec[i]);
       } 
       vector<int> result(n);
       for(int i=0 ; i<n ; i++){
        int num = nums[i];
        int group = numtog[num];
        result[i] = *(grouptolist[group].begin());
        grouptolist[group].pop_front();
       }
       return result;
    }
};
