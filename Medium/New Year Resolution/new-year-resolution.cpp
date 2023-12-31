//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
    public:
    int fun(int ind,int n,int coins[],int sum,vector<vector<int>> &dp){
        if(ind==n){
            if(sum>0){
                if(sum%20==0 || sum%24==0 || sum==2024) return 1;
            }
            return 0;
        }
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        return dp[ind][sum] = fun(ind+1,n,coins,sum+coins[ind],dp) | fun(ind+1,n,coins,sum,dp);
    }
    int isPossible(int N , int coins[]) 
    {
        vector<vector<int>> dp(N+1,vector<int> (2025,-1));
        return fun(0,N,coins,0,dp);
    }
    
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends