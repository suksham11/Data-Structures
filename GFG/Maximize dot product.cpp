//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	public:
	int help(int *a , int *b , int i , int j , vector<vector<int>>&memo){
	    if(j<0)
	        return 0;
	    
	    if(i<0) return -1e9;
	    
	    if(memo[i][j] != -1)
	      return memo[i][j];
	      
	      int nottake = 0+help(a, b , i-1, j, memo);
	      int take = a[i]*b[j]+help(a, b , i-1 , j-1 , memo);
	      
	      return memo[i][j] = max(take, nottake);
	}
	
	
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
     vector<vector<int>> memo(n,vector<int> (m,-1));
     int ans = help(a, b , n-1 , m-1, memo);
     return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
