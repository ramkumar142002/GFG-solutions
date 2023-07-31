//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool fun(int i,vector<int> &arr,int sum,vector<vector<int>> &dp){
        if(sum==0)
        {
            return true;
        }
        if(sum<0)
        {
            return false;
        }
        if(i==arr.size()){
           if(sum==0)
        {
            return true;
        }
        
            return false;
        
        }
         if(dp[i][sum]!=-1)
         {
             return dp[i][sum];
         }
           return dp[i][sum]=fun(i+1,arr,sum-arr[i],dp)||fun(i+1,arr,sum,dp);
        
       //return fun(i+1,arr,sum);
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        //vector<int> a;
        sort(arr.begin(),arr.end());
        vector<vector<int>> dp(arr.size()+1,vector<int>(sum+1,-1));
        return fun(0,arr,sum,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends