/*BRUTE FORCE
class Solution {
private: 
   bool check(string &s , int i , int j  ){
    while(i < j ){
       if(s[i] != s[j]){
           return false;
       }
    i++;
    j--; 
   }
       return true;
}
public:
    string longestPalindrome(string s) {
         int n = s.size();
         vector<string> substring;
         for(int i = 0 ; i <n ; i++){
             string temp = "";

             for(int j= i ;  j<n   ;  j++){
                temp += s[j];
                  substring.push_back(temp);

             }
         }
         int max_len = 0; 
         string finalans = substring[0];
         int m = substring.size();
         for( int  i = 0 ; i < m ; i++ ){
             int s =  substring[i].size();
             if (check(substring[i] , 0 , s-1)){
            if(s > max_len){
                max_len = s;
                finalans = substring[i];
            }

         }
    }
    return finalans;
    }
};*/

/* OPTIMIZED
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n==0)
            return "";

            bool dp[n][n];

            memset(dp , 0, sizeof(dp));

            for(int i =0 ; i<n ; i++)
                dp[i][i] = true;
                
                
            string ans = "";
            ans  += s[0];
            
            for(int i=n-1; i>=0 ; i--){
                for(int j=i+1 ; j<n ; j++){
                    if(s[i] == s[j]){
                        if(j-i == 1 || dp[i+1][j-1]){
                            dp[i][j] = true;

                            if(ans.size() < j-i+1)
                               ans = s.substr(i, j-i+1);
                        }
                    }
                }
            }

        
        return ans;
    }
};*/
