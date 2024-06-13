//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countNumberswith4(int n) {
        // code here
        int fours = 0;
        for(int i = 1;i<=n;i++){
            int curr = i;
            while(curr!=0){
                if(curr%10==4){
                    fours++;
                    break;
                }
                curr /= 10;
            }
        }
        return fours;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends