class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int>count;
        stringstream ss1(A), ss2(B);
        string word;

        while(ss1>>word){
            count[word]++;
        }

        while(ss2>>word){
            count[word]++;
        }

        vector<string> ans;
        for(const auto&entry : count){
            if(entry.second == 1){
                ans.push_back(entry.first);
            }
        }
        return ans;
    }
};
