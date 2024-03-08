//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int fun(int coins[],int N,int sum,vector<vector<long long int>> &dp){
        if(N<0) return 0;
        if(sum == 0) return 1;
        if(sum<0) return 0;
        
        if(dp[N][sum]!=-1) return dp[N][sum];
        
        long long int take = fun(coins,N,sum-coins[N],dp);
        long long int notake = fun(coins,N-1,sum,dp);
        
        return dp[N][sum] = take+notake;
    }
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long int>> dp(N,vector<long long int>(sum+1,-1));
        return fun(coins,N-1,sum,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends