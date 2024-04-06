class Solution {
public:
    int minSteps(string s, string t) {
       int cnt= 0;
       unordered_map<char , int> mp;
       for(char c : s){
           mp[c]++;
       }

       for(char c : t){
         if(mp.find(c) != mp.end()  && mp[c] > 0){
             mp[c]--;
         }
         else{
             cnt++;
         }
       }
       return cnt;
    }
};
