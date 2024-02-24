//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        int fun(int n){
            if(n==0) return 0;
            int a = max(n/2,fun(n/2));
            int b = max(n/3,fun(n/3));
            int c = max(n/4,fun(n/4));
            
            return a+b+c;
        }
        int maxSum(int n)
        {
            //code here.
            int x = fun(n);
            return max(n,x);
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
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends