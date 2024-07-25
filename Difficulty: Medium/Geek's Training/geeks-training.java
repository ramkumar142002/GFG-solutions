//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int N = sc.nextInt();
            int[][] arr = new int[N][3];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < 3; j++) {
                    arr[i][j] = sc.nextInt();
                }
            }
            Solution obj = new Solution();
            int res = obj.maximumPoints(arr, N);
            System.out.println(res);
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    public int maximumPoints(int arr[][], int N) {
        // code here
        int[][] dp = new int[N][4];
        for(int[] a:dp){
            Arrays.fill(a,-1);
        }
        return fun(arr,N-1,-1,dp);
    }
    public int fun(int arr[][],int ind,int prev,int[][] dp){
        if(ind<0) return 0;
        
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int maxi = 0;
        for(int j = 0;j<arr[0].length;j++){
            if(prev==-1 || j!=prev){
                int points = arr[ind][j] + fun(arr,ind-1,j,dp);
                maxi = Math.max(maxi,points);
            }
            
        }
        return dp[ind][prev+1] = maxi;
    }
}