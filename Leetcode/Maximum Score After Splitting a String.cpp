class Solution {
public:
    int maxScore(string s) {
        int maxscore = INT_MIN;
        int ones = 0;
        int zeros = 0;
        for(int i=0 ; i<s.size() - 1; i++){
            if(s[i] == '1'){
                ones++;
            }
            else{
                zeros++;
            }

                maxscore = max(maxscore , zeros - ones);
            }
            if(s[s.size()-1] == '1'){
                ones++;
            }
        
        return maxscore + ones;
    } 
};
