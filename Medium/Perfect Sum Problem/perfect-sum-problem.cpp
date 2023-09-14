//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int fun(int arr[], int ind, int sum,vector<vector<int>> &dp){
	    if(ind==0){
	        if(sum==0 && arr[0]==0) return 2;
	        if(sum==0 || sum==arr[0]) return 1;
	        return 0;
	    }
	    
	    if(dp[ind][sum]!=-1) return dp[ind][sum];
	        
	    int take=0; 
        if(arr[ind]<=sum) take= fun(arr,ind-1,sum-arr[ind],dp);
        int notake=fun(arr,ind-1,sum,dp);
        
        int mod=1e9+7;
        return dp[ind][sum]=(take+notake)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        return fun(arr,n-1,sum,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends