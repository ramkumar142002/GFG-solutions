//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        // char *token = strtok(S,".");
        // vector<string> str;
        // while(token!=NULL){
        //     str.push_back(token);
        //     token = strtok(NULL, ".");
        // }
        // // reverse(str.begin(),str.end());
        // string ans = "";
        // for(int i = str.size()-1;i>=0;i--){
        //     ans = ans + str[i];
        //     if(i!=0) ans += '.' ;
        // }
        // return ans;
        
        stringstream str(S);
        string intermediate;
        vector<string> v;
        while(getline(str, intermediate, '.'))
        {
            v.push_back(intermediate);
        }
        
        S = "";
        for(int i = v.size()-1;i>=0;i--){
            S = S + v[i];
            if(i!=0) S += '.';
        }
        
        return S;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends