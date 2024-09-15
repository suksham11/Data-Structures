class Solution {
public:
    int findTheLongestSubstring(string s) {
        int prefixxor = 0;
        int charactermap[26] = {0};
        charactermap['a'- 'a'] = 1;
        charactermap['e' - 'a'] = 2;
        charactermap['i' - 'a'] = 4;
        charactermap['o' - 'a'] = 8;
        charactermap['u' - 'a'] = 16;

        vector<int> mp(32, -1);
        int longestsubstring = 0;
        for(int i=0 ; i<s.length() ; i++){
            prefixxor ^= charactermap[s[i] - 'a'];
            if(mp[prefixxor] == -1 and prefixxor != 0) mp[prefixxor] = i;
            longestsubstring = max(longestsubstring, i-mp[prefixxor]);
        }
        return longestsubstring;
    }
};
