

class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
       vector<int> postmax(n);
       vector<int> postmin(n);
       
       postmin[n-1] = arr[n-1];
       postmax[n-1] = arr[n-1];
       
       for(int i=n-2 ; i>=0 ; --i){
           postmax[i] = max(arr[i], postmax[i+1]);
           postmin[i] = min(arr[i], postmin[i+1]);
           
       }
       int mindiff = postmax[k] - postmin[k];
       int pmin = arr[0];
       int pmax = arr[0];
       for(int i=1; i<n-k ; i++){
           int currmin = max(pmax , postmax[i+k]) - min(pmin , postmin[i+k]);
           mindiff = min(mindiff, currmin);
           pmax = max(arr[i], pmax);
           pmin = min(arr[i], pmin);
       }
       mindiff = min(mindiff , pmax-pmin);
       
       return mindiff;
    } 
};

