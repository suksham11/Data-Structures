class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxleftscore = values[0];
        int maxscore = 0;

        for(int i=1 ; i<n ; i++){
            int currRightscore = values[i] - i;
            maxscore = max(maxscore, maxleftscore + currRightscore);

            int currleftscore = values[i] + i;
            maxleftscore = max(maxleftscore, currleftscore);
        }
        
        return maxscore;
    }
};
