//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
// 	int fun(string s,string t,int m,int n){
// 	    if(m<0 || n<0) return 0;
	    
// 	    if(s[m]==t[n]) return 1+fun(s,t,m-1,n-1);
// 	    return max(fun(s,t,m-1,n),fun(s,t,m,n-1));
// 	}
	int isPalindrome(string S)
	{
	    // Your code goes here
	   // string t=S;
	   // reverse(t.begin(),t.end());
	    int m=S.size();
	   // int a= fun(S,t,m-1,m-1);
	   // if(a==m) return true;
	   // return false;
	   for(int i=0;i<m/2;i++){
	       if(S[i]!=S[m-i-1]) return 0;
	   }
	   return true;
	}

};

//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends