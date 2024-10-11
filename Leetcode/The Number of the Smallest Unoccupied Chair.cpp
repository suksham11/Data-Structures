class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<int> targettime = times[targetFriend];
        sort(times.begin() , times.end());
        int n = times.size();
        vector<int> chairtime(n);
        for(auto time : times){
            for(int i=0 ; i<n ; i++){
                if(chairtime[i] <= time[0]){
                    chairtime[i] = time[1];
                    if(time == targettime) return i;
                    break;
                }
            }
        }
        return 0;
    }
};
