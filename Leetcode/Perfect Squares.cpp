class Solution {
public:
     // BOTTOM UP APPROACH
     int numSquares(int n){
     vector<int> t(n+1, 100000);
        t[0] = 0;
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j*j <= i ; j++){
                t[i] = min(t[i], t[i-j*j] + 1);
            }
        }
        return t[n];     
    }
};


class Solution {
public:
// DP + MEMO
 int arr[10001];
    int helper(int n){
        if(n==0)
            return 0;
        
        if(arr[n] != -1)
           return arr[n];

        int count = INT_MAX;
        for(int i=1 ; i*i<=n ; i++){
            int result = helper(n-i*i)+1;

            count = min(count , result);
        }
        return arr[n] = count;
    }

    int numSquares(int n) {
      memset(arr  , -1 , sizeof(arr));
      return helper(n);  

  }
};
