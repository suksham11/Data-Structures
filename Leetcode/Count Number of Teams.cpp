class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();

        int teams = 0;
        for(int j=1 ; j<n-1  ; j++){
            int countsmallerleft = 0;
            int countlargerright = 0;
            int countlargerleft = 0;
            int countsmallerright = 0;
            
            for(int i=0 ; i<j ; i++){
                if(rating[i] < rating[j]){
                    countsmallerleft++;
                }
                else if(rating[i] > rating[j]){
                    countlargerleft++;
                }
            }

            for(int k=j+1 ; k<n ; k++){
                if(rating[j] < rating[k]){
                    countlargerright++;
                }
                else if(rating[j] > rating[k]){
                    countsmallerright++;
                }
            }
        teams += (countlargerleft * countsmallerright)  + (countsmallerleft * countlargerright);
        }
    return teams;
    }
};
