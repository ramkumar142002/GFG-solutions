//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sentence) {

        // code here
        vector<string> strings;
        stringstream stream(sentence);
        string intermediate;
        
        while(getline(stream, intermediate, ' '))
        {
            strings.push_back(intermediate);
        }
        
        vector<long long> nums;
        for(int i = 0;i<strings.size();i++){
            if(!isalpha(strings[i][0]) && strings[i].find('9')==string::npos){
                nums.push_back(stoll(strings[i]));
            }
        }
        sort(nums.begin(),nums.end());
        if(nums.size()>0) return nums[nums.size()-1];
        return -1;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends