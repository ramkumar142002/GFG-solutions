//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        string ans = "";
        int minLength  = INT_MAX;
        for(int i = 0;i<N;i++){
            if(minLength > arr[i].size()){
                minLength = arr[i].size();
            }
        }
        
        for(int j = 0;j<minLength;j++){
            char temp = arr[0][j];
            int flag = 0;
            for(int i = 1;i<N;i++){
                if(arr[i][j] != temp) flag = 1;
            }
            if(flag == 0) ans += temp;
        }
        return ans.size()>0 ? ans : "-1";
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends