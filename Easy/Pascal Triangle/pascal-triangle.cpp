//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#define ll long long
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        // code here
        long long mod = 1e9+7;
        if(n==0) return {1};
        int i=1;
        vector<ll> prev(1,1),cur(1,1);
        while(i<n){
            // cout<<i<<endl;
            
            cur.clear();
            cur.push_back(1);
            for(int j=0;j<prev.size()-1;j++){
                cur.push_back((prev[j]%mod+prev[j+1]%mod)%mod);
                // cout<<prev[j]+prev[j+1]<<endl;
            }
            cur.push_back(1);
            prev=cur;
            
            i++;
        }
        
        return cur;
    }
};



//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends