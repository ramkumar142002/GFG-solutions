//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod = 1003;
    int fun(int i,int j,string s,int istrue,vector<vector<vector<int>>> &dp){
        if(i>j) return 0;
        if(i==j){
            if(istrue) return (s[i]=='T');
            else return (s[i]=='F');
        }
        
        if(dp[i][j][istrue]!=-1) return dp[i][j][istrue];
        int maxi = 0;
        for(int ind = i+1;ind<=j-1;ind+=2){
            
            int lt = fun(i,ind-1,s,1,dp);
            int lf = fun(i,ind-1,s,0,dp);
            int rt = fun(ind+1,j,s,1,dp);
            int rf = fun(ind+1,j,s,0,dp);
            
            
            if(s[ind]=='&'){
                if(istrue){
                    maxi = (maxi + (lt*rt)%mod)%mod;
                }
                else maxi = (maxi + (lt*rf)%mod + (lf*rt)%mod + (lf*rf)%mod)%mod;
            }
            else if(s[ind]=='|'){
                if(istrue) maxi = (maxi + (lt*rt)%mod + (lt*rf)%mod + (lf*rt)%mod)%mod;
                else maxi = maxi + (lf*rf);
            }
            else{
                if(istrue) maxi = (maxi + (lt*rf)%mod + (lf*rt)%mod)%mod;
                else maxi = (maxi + (lt*rt)%mod + (lf*rf)%mod)%mod;
            }
        }
        return dp[i][j][istrue] = maxi;
    }
    int countWays(int N, string S){
        // code here
        vector<vector<vector<int>>> dp(N,vector<vector<int>> (N,vector<int> (2,-1)));
        return fun(0,N-1,S,1,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends