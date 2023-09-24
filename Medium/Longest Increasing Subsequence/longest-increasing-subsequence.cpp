//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int fun(int ind,int n,int a[],int prev,vector<vector<int>> &dp){
        if(ind==n) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        
        int len=0+fun(ind+1,n,a,prev,dp);
        if(prev==-1 || a[prev]<a[ind]){
            len=max(len,1+fun(ind+1,n,a,ind,dp));
        }
        
        return dp[ind][prev+1]=len;
    }
    int longestSubsequence(int n, int a[])
    {
       // your code here
    //   vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
    //   return fun(0,n,a,-1,dp);
    
        vector<int> temp;
        temp.push_back(a[0]);
        for(int i=1;i<n;i++){
            if(a[i]>temp.back()){
                temp.push_back(a[i]);
            }
            else{
                int ind=lower_bound(temp.begin(),temp.end(),a[i])-temp.begin();
                temp[ind]=a[i];
            }
        }
        
        return temp.size();
    
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends