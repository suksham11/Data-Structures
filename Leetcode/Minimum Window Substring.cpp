class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty() || s.length() < t.length()){
            return "";
        }
        
        vector<int> map(128,0);
        int count = t.length();
        int start = 0 , end = 0, minlen = INT_MAX ,startidx = 0;

        for(char c: t){
            map[c]++;
        }
        
        while(end < s.length()){
            if(map[s[end++]]-- > 0){
                count--;
            }

            while(count == 0){
                if(end - start < minlen){
                    startidx = start;
                    minlen = end - start;
                }

                if(map[s[start++]]++ == 0){
                    count++;
                }
            }
        }
        return minlen == INT_MAX ? "" : s.substr(startidx , minlen);
    }
};
