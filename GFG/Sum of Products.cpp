

class Solution {
  public:
    long long pairAndSum(int n, long long arr[]) {
        long long result = 0;
        for(int bit = 0 ; bit < 32 ; bit++){
            int count = 0;
            for(int i=0 ; i<n ; i++){
                if(arr[i] & (1LL << bit)) 
                  count++;
            }
            result += (count * 1LL * (count-1)/2 ) * (1LL << bit);
        }
    return result;
        
    }
};

