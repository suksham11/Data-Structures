class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int consistentcount = 0;
        for(string& word : words){
            bool iswordconsistent = true;
        
            for(int i=0 ; i<word.length() ; i++){
                char currentchar = word[i];
                bool isCharAllowed = false;
                
 
            for(int j=0 ; j < allowed.size() ; j++){
                if(allowed[j] == currentchar){
                    isCharAllowed = true;
                    break;
                }
            }

               if(!isCharAllowed){
                    iswordconsistent = false;
                    break;
                }
            }
            if(iswordconsistent){
                consistentcount++;
            }
        }
        return consistentcount;
    }
};
