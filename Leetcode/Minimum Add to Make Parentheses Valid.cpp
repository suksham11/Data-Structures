class Solution {
public:
    int minAddToMakeValid(string s) {
        int openb = 0;

        int minadd = 0;
        for(char c: s){
            if(c == '('){
                openb++;
            }
            else{
                openb > 0? openb-- : minadd++;
            }
        }
        return minadd + openb;
    }
};
