class Solution {
public:
    string reversePrefix(string word, char ch) {
        int chind = word.find(ch);
        reverse(word.begin() , word.begin() + chind  + 1 );
        return word;
    }
};
