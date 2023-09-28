//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int fun(vector<int> &arr,int i,int j,vector<vector<int>> &dp){
        if(i>j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi=INT_MIN;
        
        for(int ind=i;ind<=j;ind++){
            int cost=(arr[ind]*arr[i-1]*arr[j+1])+fun(arr,i,ind-1,dp)+fun(arr,ind+1,j,dp);
            maxi=max(maxi,cost);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(int N, vector<int> &arr) {
        // code here
        arr.push_back(1);
        arr.insert(arr.begin(),1);
        vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
        return fun(arr,1,N,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends