class Solution {
public:
    vector<int> countfreq(string& word){
        vector<int> freq(26);
        for(auto& c: word) freq[c - 'a']++;
        return freq;
    }
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
     vector<int> maxfreq(26);
     vector<string> ans;
     for(auto& word : B){
        vector<int> freq = countfreq(word);
        for(int i=0 ; i<26 ; i++) maxfreq[i] = max(maxfreq[i] , freq[i]);
     }
      for(auto& word : A){
        vector<int> freq = countfreq(word);
        int i=0;
        for(;i<26 ; i++) if(freq[i] < maxfreq[i]) break;
        if(i==26) ans.push_back(word);
     }
     return ans;
    }
};
