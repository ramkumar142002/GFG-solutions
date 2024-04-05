//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int min_operations(vector<int>& nums) {
        // Code here
        int n=nums.size();

        vector<int> dp(n,1);
        int LIS = 1;
        for(int ind=1;ind<n;ind++){
            for(int prev=0;prev<ind;prev++){

                if(nums[ind]-nums[prev] >= (ind-prev)){
                    dp[ind]=max(dp[ind],1+dp[prev]);
                    LIS = max(LIS,dp[ind]);
                }
            }
        }
        return nums.size() - LIS;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.min_operations(nums);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends