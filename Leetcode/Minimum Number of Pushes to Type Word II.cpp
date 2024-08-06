class Solution {
public:
    int minimumPushes(string word) {
        vector<int> letterfreq(26,0 );
        for(char c:word){
            letterfreq[c - 'a']++;
        }
        sort(letterfreq.rbegin() , letterfreq.rend());

        int totalpresses = 0;
        for(int i=0 ; i<26 ; i++){
            if(letterfreq[i] == 0) break;
            totalpresses += (i/8 + 1) * letterfreq[i];
        }
        return totalpresses;
    } 
};
