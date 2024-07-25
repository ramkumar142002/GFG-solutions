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
            int K = sc.nextInt();
            int[] arr = new int[N];
            for (int i = 0; i < N; i++) {
                arr[i] = sc.nextInt();
            }
            Solution obj = new Solution();
            int res = obj.minimizeCost(arr, N, K);
            System.out.println(res);
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    public int minimizeCost(int arr[], int N, int K) {
        // code here
        int[] dp = new int[N];
        Arrays.fill(dp,-1);
        return fun(arr,N-1,K,dp);
    }
    public int fun(int arr[],int ind,int k,int[] dp){
        if(ind==0) return 0;
        
        if(dp[ind] != -1) return dp[ind];
        int total = Integer.MAX_VALUE;
        for(int j = 1;j<=k;j++){
            if(ind-j>-1){
                int cost = Math.abs(arr[ind] - arr[ind-j]) + fun(arr,ind-j,k,dp);
                total = Math.min(total,cost);
            }
        }
        return dp[ind] = total;
    }
}
