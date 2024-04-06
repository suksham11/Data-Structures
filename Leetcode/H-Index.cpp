class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();
        sort(c.begin() , c.end());
        int ans = 0;
        int start = 0 , end = n-1;
        while(start<=end){
          int mid = start + (end - start)/2;
          if(c[mid] >= n-mid){
              ans = max(ans , n-mid);
              end = mid-1;
          }
          else{
             start = mid+1;
          }
        }
        return ans;
    }
    
};
