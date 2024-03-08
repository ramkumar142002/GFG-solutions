//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int fun(int arr[],int ind,int N,int prev,vector<vector<int>> &dp){
        if(ind==N) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int take = 0,notake = 0;
        if(prev==-1 || arr[ind]==prev+1){
            take = 1 + fun(arr,ind+1,N,arr[ind],dp);
        }
        notake = 0 + fun(arr,ind+1,N,prev,dp);
        return dp[ind][prev+1] = max(take,notake);
    }
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
    //   sort(arr,arr+N);
    //   vector<vector<int>> dp(N+1,vector<int> (N+1,-1));
    //   return fun(arr,0,N,-1,dp);
    
        if(N==0) return 0;
        sort(arr,arr+N);
        int maxi = 1;
        int ans = 1;
        for(int i=1;i<N;i++){
            // cout<<nums[i]<<endl;
            if(arr[i] == arr[i-1]+1){
                maxi++;
            }
            else if(arr[i] == arr[i-1]) maxi = maxi;
            else maxi = 1;
            ans = max(ans,maxi);
        }
        return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends