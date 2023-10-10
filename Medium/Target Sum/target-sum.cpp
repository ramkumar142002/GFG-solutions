//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int fun(vector<int> &A,int ind,int target){
        if(ind==-1){
            return (target==0);
        }
        
        int add=fun(A,ind-1,target+A[ind]);
        int sub=fun(A,ind-1,target-A[ind]);
        return add+sub;
    }
    int findTargetSumWays(vector<int>&A ,int target) {
        //Your code here
        int n=A.size();
        return fun(A,n-1,target);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends