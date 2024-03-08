//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    set<string> st;
	    void fun(string s,vector<int> &f,string str){
	        if(s.size() == str.size()){
	            st.insert(str);
	            return;
	        }
	        
	        for(int i = 0;i<s.size();i++){
	            if(f[i]==0){
	                str = str + s[i];
	                f[i] = 1;
	                fun(s,f,str);
	                str.pop_back();
	                f[i] = 0;
	            }
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<int> f(S.size(),0);
		    string str = "";
		    fun(S,f,str);
		    vector<string> ans(st.begin(),st.end());
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends