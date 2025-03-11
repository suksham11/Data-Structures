class Solution {
private:
    bool isvowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }

public:
    long long countOfSubstrings(string word, int k) {
       long long numvalidsubstring = 0;
       int start = 0, end = 0;
       unordered_map<char, int> vowelcount;
       int consonantcount = 0;

       vector<int> nextconsonant(word.size());
       int nextconsonantindex = word.size();
       for(int i=word.size()-1 ; i>=0 ; i--){
        nextconsonant[i] = nextconsonantindex;
        if(!isvowel(word[i])){
            nextconsonantindex = i;
        }
       }

       while(end < word.size()){
        char newletter  = word[end];
        if(isvowel(newletter)){
            vowelcount[newletter]++;
        }
        else{
            consonantcount++;
        }
        while(consonantcount > k){
            char startletter = word[start];
            if(isvowel(startletter)){
                vowelcount[startletter]--;
                if(vowelcount[startletter] == 0){
                    vowelcount.erase(startletter);
                }
            }
            else{
                consonantcount--;
            }
            start++;
        }
        while(start < word.size() && vowelcount.size() == 5 && consonantcount == k){
            numvalidsubstring += nextconsonant[end] - end;
            char startletter = word[start];
            if(isvowel(startletter)){
                vowelcount[startletter]--;
                if(vowelcount[startletter] == 0){
                    vowelcount.erase(startletter);
                }
            }
            else{
                consonantcount--;
            }
            start++;
        }
        end++;
       }
       return numvalidsubstring;
    }
};
