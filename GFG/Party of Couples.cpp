

class Solution{
  public:
    int missingNumber(vector<int>& array, int n) {
      int reqsum = (n*(n+1))/2;
      int currsum = 0;
      for(int i=0 ; i<n-1; i++)
        currsum += array[i];
        return reqsum - currsum;
    }
};

