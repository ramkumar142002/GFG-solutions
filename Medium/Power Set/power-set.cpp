//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    vector<string> ans;
	    void fun(string s,string temp,int ind,int n){
	        if(ind == n){
	            if(temp.size()!=0){
	                ans.push_back(temp);
	            }
	            return ;
	            
	        }
	        
            temp = temp + s[ind];
            fun(s,temp,ind+1,n);
            temp.pop_back();
	        fun(s,temp,ind+1,n);
	        
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    string temp = "";
		  //  sort(s.begin(),s.end());
		    fun(s,temp,0,s.size());
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends