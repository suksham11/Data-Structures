class Solution {
public:
    bool canfindcandies(vector<int>& candies, int mid , long long k){
        int n = candies.size();
        for(int i=0 ; i<n ; i++){
             k -= candies[i]/mid;
        if(k<=0){
            return true;
        }
        }
    return k<=0;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int maxc  = 0;
        long long total = 0;
        for(int i=0;  i<n ; i++){
            total += candies[i];
            maxc = max(maxc , candies[i]);
        }
        if(total < k){
            return 0;
        }   
        
        int l=1 , r=maxc;
        int result = 0;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(canfindcandies(candies, mid, k)){
                result = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return result;

    }
};
