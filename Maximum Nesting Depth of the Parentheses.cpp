class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int maxnum = 0;
        for(char c: s){
            if(c == '('){
                count++;
                if(maxnum < count)
                   maxnum = count;
            }else if(c == ')'){
                count--;
            }
        }
    return maxnum;
    }
};
