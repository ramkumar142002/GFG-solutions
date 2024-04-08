//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long fun(int arr[],int i,int j,int turn,vector<vector<int>>  &dp){
        if(i>j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(turn){
            return max(arr[i]+fun(arr,i+1,j,0,dp) , arr[j]+fun(arr,i,j-1,0,dp));
        }
        return dp[i][j] = min(fun(arr,i+1,j,1,dp),fun(arr,i,j-1,1,dp));
    }
    long long maximumAmount(int n, int arr[]){
        // Your code here
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return fun(arr,0,n-1,1,dp);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends