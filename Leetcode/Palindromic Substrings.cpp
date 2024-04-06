class Solution {
     public boolean isPallindrom(String s, int left ,  int right){
      while(left < right){
            if(s.charAt(left++) != s.charAt(right--)) return false;
        }
     return true;
     }

    public int countSubstrings(String s) {
        
      int ans =0;
      int n = s.length();
      for(int i=0 ; i<n ; i++){
         for(int j=i ; j<n ; j++){
             if(isPallindrom(s, i, j)) ans++;
         }
      }
    return ans;
    }
} 
