//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int mod = 1e9+7;
    int fun(string a,string b,int i,int j,vector<vector<int>> &dp){
        if(j == b.size()) return 1;
        if(i == a.size()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(a[i] == b[j]){
            return dp[i][j] = (fun(a,b,i+1,j+1,dp)%mod + fun(a,b,i+1,j,dp)%mod)%mod;
        }
        return dp[i][j] = (fun(a,b,i+1,j,dp))%mod;
    }
    int countWays(string s1, string s2) {
        // code here
        vector<vector<int>> dp(s1.size(),vector<int> (s2.size() , -1));
        return fun(s1,s2,0,0,dp)%mod;
    }
    
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends