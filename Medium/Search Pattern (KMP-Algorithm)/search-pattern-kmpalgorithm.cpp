//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code hee.
            vector<int> ans;
            // string comp = txt.substr(0,pat.size());
            // if(comp == pat) ans.push_back(1);
            // for(int i = 0;i<=txt.size()-pat.size();i++){
                
            //     comp.erase(0,1); comp+= txt[i+pat.size()];
                
            //     if(comp == pat){
            //         ans.push_back(i+2);
            //     }
                
            // }
            
            for(int i = 0;i<txt.size();i++){
                if(txt[i] == pat[0]){
                    if(txt.substr(i,pat.size()) == pat) ans.push_back(i+1);
                }
            }
            if(ans.size()==0) return {-1};
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends