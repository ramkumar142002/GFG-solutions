//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int fun1(int N,vector<int> &ans){
        if(N<=0) return N;
        ans.push_back(N);
        fun1(N-5,ans);
    }
    void fun2(int N,int X,vector<int> &ans){
        if(X==N){
            ans.push_back(N);
            return;
        }
        ans.push_back(X);
        fun2(N,X+5,ans);
    }
    vector<int> pattern(int N){
        // code here
        if(N==0) return {0};
        vector<int> ans;
        int X = N;
        if(N>0) X = fun1(X,ans);
        if(X<=0) fun2(N,X,ans);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends