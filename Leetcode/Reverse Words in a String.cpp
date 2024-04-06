class Solution {
public:
    string reverseWords(string s) {
        istringstream  iss(s); 
        vector<string> words;
        string word;
        while(iss >> word){
            words.push_back(word);
        }
        reverse(words.begin() , words.end());
        string reversed;
        for(const auto& w: words){
            reversed += w + " ";
        }
        if(!reversed.empty()){
            reversed.pop_back();
        }
    return reversed;
    }
};
