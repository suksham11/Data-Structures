class Solution {
public:
  /* FIRST Approach
   bool isPallindrom(const string& s){
    int left = 0 , right = s.size()-1;
    while(left < right){
        if(s[left] != s[right])
           return false;
        left++;
        right--;
        }
        return true;
    }     
    
    string firstPalindrome(vector<string>& words) {
       for(const string&word : words){
          if(isPallindrom(word))
              return word;
          
       }
    return "";
    
    }
};*/

// SECOND APPROACH

   string firstPalindrome(vector<string>& words){
       for(auto i:words){
           string s = i;
           reverse(s.begin() , s.end());
           if(s==i){
               return s;
           }
        } 
           return "";
       }
   };
