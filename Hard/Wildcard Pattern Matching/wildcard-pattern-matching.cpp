//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
   int fun(string pattern, string str,int i,int j,vector<vector<int>> &dp){
        if(j==0 && i==0) return true;
        if(i==0 && j>0) return false;
        if(j==0 && i>0){
            for(int ii=1;ii<=i;ii++) {
                if(pattern[ii-1]!='*') return false;
            }
            return true;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(pattern[i-1]==str[j-1] || pattern[i-1]=='?') return dp[i][j]=fun(pattern,str,i-1,j-1,dp);
        if(pattern[i-1]=='*'){
            return dp[i][j]=fun(pattern,str,i-1,j,dp) | fun(pattern,str,i,j-1,dp);
        }
        return dp[i][j]=false;
    }
    int wildCard(string pattern,string str)
    {
        int m=pattern.size(),n=str.size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        return fun(pattern,str,m,n,dp);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends