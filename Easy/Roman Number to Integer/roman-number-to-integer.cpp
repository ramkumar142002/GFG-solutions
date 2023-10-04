//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int fun(char c){
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return -1;
    }
    int romanToDecimal(string &str) {
        // code here
        int res=0;
        for(int i=0;i<str.size();i++){
            int s1=fun(str[i]);
            
            if(i+1<str.size()){
                int s2=fun(str[i+1]);
                if(s1>=s2) res=res+s1;
                else{ 
                    res=res+s2-s1;
                    i++;
                }
                
            }
            else res+=s1;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends