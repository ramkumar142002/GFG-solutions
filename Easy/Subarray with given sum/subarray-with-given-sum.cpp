//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> fun(vector<int> &arr,int n,int i,long long s,vector<int> &a){
        if(s==0){
            a.push_back(i);
            return a;
        }
        if(i==n) return a;
        // cout<<s<<endl;
        
        // if(dp[i][s]!=-1) return dp[i][s];
        
        if(arr[i]<=s) return fun(arr,n,i+1,s-arr[i],a);
        return a;
    }
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        if(s==0) return {-1};
        // vector<vector<int>> dp(n+1,vector<int> (s+1,-1));

       int i=0,j=0;
       long long sum=0;
       while(i<arr.size() && j<arr.size())
       {
           sum+=arr[j];
           while(sum>=s)
           {
               if(sum==s)
               {
                   return {i+1,j+1};
               }
               sum-=arr[i];
               i++;
           }
           j++;
       }
        return {-1};
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
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends