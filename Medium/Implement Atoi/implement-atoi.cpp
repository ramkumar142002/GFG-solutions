//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int ans = 0;
        if(s[0]=='-'){
           
            for(int i = 1;i<s.size();i++){
                if(!isdigit(s[i])) return -1;
                ans = ans*10 + s[i]-'0';
            }
            return -1 * ans;
        }
        else{
            
            for(int i = 0;i<s.size();i++){
                if(!isdigit(s[i])) return -1;
                ans = ans*10 + s[i]-'0';
            }
            return ans;
        }
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
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends