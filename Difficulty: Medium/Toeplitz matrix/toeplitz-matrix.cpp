//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isToepliz(vector<vector<int>> &mat);

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }

        bool b = isToepliz(a);

        if (b == true)
            cout << "true";
        else
            cout << "false";

        cout << endl;
    }
    return 0;
}
// } Driver Code Ends



bool isToepliz(vector<vector<int>>& mat) {
    // code here
    if(mat.size() == mat[0].size()){
        int i = 0,j = 0;
        int cur = mat[i][j];
        while(i<mat.size() && j<mat[i].size()){
            if(mat[i][j]!=cur) return false;
            i++,j++;
        }
    }
    int i = 0,j = 0;
    int cur = mat[i][j];
    while(i<mat.size() && j<mat[i].size()){
        if(mat[i][j]!=cur) return false;
        i++,j++;
    }
    i = mat.size()-1;
    j = mat[i].size()-1;
    cur = mat[i][j];
    while(i>-1 && j>-1){
        if(mat[i][j]!=cur) return false;
        i--,j--;
    }
    return true;
}