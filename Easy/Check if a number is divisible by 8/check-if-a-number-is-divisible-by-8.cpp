//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        //code here
        if(s.size()<4){
            int x = stoi(s);
            if(x%8 == 0) return 1;
        }
        int ind = s.size()-3;
        string temp = s.substr(ind,3);
        int x = stoi(temp);
        if(x==0 || x%8==0) return 1;
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends