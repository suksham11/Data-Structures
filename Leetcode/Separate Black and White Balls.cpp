class Solution {
public:
    long long minimumSteps(string s) {
        int wpos = 0;
        long long tswap = 0;

        for(int cpos = 0 ; cpos < s.size(); cpos++){
            if(s[cpos] == '0'){
                tswap += cpos - wpos;
                wpos++;
            }
        }
        return tswap;
    }
};
