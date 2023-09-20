//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    // code here
	    set<int> s;
	    for(int i=0;i<n;i++){
	        s.insert(arr[i]);
	    }
	   // sort(s.begin(),s.end());
	   // s.erase(0);
	   // return s.begin();
	   if(s.size()==1) return -1;
	   vector<int> v(s.begin(),s.end());
	   return v[v.size()-2];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends