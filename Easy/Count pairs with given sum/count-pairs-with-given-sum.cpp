//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int fun(int arr[],int ind,int tim,int k){
        if(ind==0){
            return (k==arr[0] && tim==1);
        }
        // if(k==arr[ind] && tim==1) return 1;
        
        int take=0,notake=0;
        if(tim>0 && arr[ind]<=k) take+=fun(arr,ind-1,tim-1,k-arr[ind]);
        notake+=fun(arr,ind-1,tim,k);
        
        return take+notake;
    }
    int getPairsCount(int arr[], int n, int k) {
        // code here
        // return fun(arr,n-1,2,k);
        vector<int> a;
        for(int i=0;i<n;i++)a.push_back(arr[i]);
        sort(a.begin(),a.end());
        map<int,int> m;
        for(int i=0;i<n;i++)
        {
            m[a[i]]++;
        }
        int i=0,j=n-1;
        int c=0;
        while(i<j){
            bool check=false;
            if(a[i]+a[j]==k)
            {
                check=true;
            }
            if(check){
            int l=i;
            while(l<j && a[l]+a[j]==k)
            {
                  c++;
                  l++;
            }
            j--;
            continue;
            }
            else if(a[i]+a[j]>k) j--;
            else if(a[i]+a[j]<k) i++;
        }
        return c;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends