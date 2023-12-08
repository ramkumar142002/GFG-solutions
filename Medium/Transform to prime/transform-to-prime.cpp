//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    int minNumber(int arr[],int N)
    {
        int sum = 0;
        for(int i = 0;i<N;i++) sum+=arr[i];
        
        int i = sum;
        
        int flag = 0;
        while(flag==0){
            for(int j = 1;j<=i/2;j++){
                if(i%j==0) flag++;
            }
            if(flag==1){
                if(sum==i) return 0;
                if(i>sum) return i-sum;
            }
            i++;
            flag = 0;
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends