//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  long long int mod = 1e9+7;
    long long fun(int n,vector<long long> &dp){
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = (fun(n-1,dp) + fun(n-2,dp))%mod;
    }
    int nthFibonacci(int n){
        // code here
        vector<long long> dp(n+1,-1);
        return fun(n,dp)%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends