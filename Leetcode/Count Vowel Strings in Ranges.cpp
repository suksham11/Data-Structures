class Solution {
public:
    bool isVowel(char ch){
        return  ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'||
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> is_vowel_word(n, 0);
        for(int i=0 ; i<n ;  ++i){
            string &word = words[i];
            if(isVowel(word[0]) && isVowel(word[word.length() - 1])){
            is_vowel_word[i] = 1;
        }
        } 
 
        vector<int> prefix(n+1, 0);
        for(int i=0 ; i<n ; ++i){
            prefix[i+1] = prefix[i] + is_vowel_word[i];
        }
       

        vector<int> result;
        for(const auto& query : queries){
            int start = query[0], end = query[1];
            result.push_back(prefix[end + 1] - prefix[start]);
        }
            return result;
        }

    
};.
