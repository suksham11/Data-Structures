class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int res = 0;
        string top, bot;
        int topscore , botscore;

        if(y>x){
            top = "ba";
            topscore = y;
            bot = "ab";
            botscore  = x;
        }else{
            top = "ab";
            topscore = x;
            bot = "ba";
            botscore = y;
        }
            vector<char> stack;
            for(char ch: s){
                if(ch == top[1] && !stack.empty() && stack.back() == top[0]){
                    res+=topscore;
                    stack.pop_back();
                }
                else{
                    stack.push_back(ch);
                }
            }
            vector<char> newstack;
            for(char ch: stack){
                if(ch == bot[1] && !newstack.empty() && newstack.back() == bot[0]){
                    res+=botscore;
                    newstack.pop_back();
                }
                else{
                    newstack.push_back(ch);
                }
            }
        return res;
        }
};
