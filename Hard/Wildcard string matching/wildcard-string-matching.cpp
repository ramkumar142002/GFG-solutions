//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool fun(string wild, string pattern,int i,int j){
        if(i==-1 && j==-1) return true;
        if(i==-1 && j>-1) return false;
        if(j==-1 && i>-1){
            for(int k = 0;k<=i;k++){
                if(wild[k]!='*') return false;
            }
            return true;
        }
        
        if(wild[i]==pattern[j] || wild[i]=='?') return fun(wild,pattern,i-1,j-1);
        if(wild[i]=='*'){
            return fun(wild,pattern,i-1,j) | fun(wild,pattern,i,j-1);
        }
        return false;
    }
    bool match(string wild, string pattern)
    {
        // code here
        return fun(wild,pattern,wild.size()-1,pattern.size()-1);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends