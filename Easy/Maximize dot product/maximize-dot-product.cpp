//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	public:
	int fun(int a[],int b[],int i,int j,int difLen,vector<vector<int>> &dp){
	    if(i<0 || j<0) return 0;
	    
	    if(dp[i][j]!=-1) return dp[i][j];
	    int prod = 0;
	    if(difLen>0) prod = 0 + fun(a,b,i-1,j,difLen-1,dp);
	    return dp[i][j] = max(prod,(a[i]*b[j]) + fun(a,b,i-1,j-1,difLen,dp));
	}
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
		// Your code goes here
		vector<vector<int>> dp(n,vector<int> (m,-1));
		return fun(a,b,n-1,m-1,n-m,dp);
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