//{ Driver Code Starts
import java.io.*;
import java.util.*;

class IntArray {
    public static int[] input(BufferedReader br, int n) throws IOException {
        String[] s = br.readLine().trim().split(" ");
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = Integer.parseInt(s[i]);

        return a;
    }

    public static void print(int[] a) {
        for (int e : a) System.out.print(e + " ");
        System.out.println();
    }

    public static void print(ArrayList<Integer> a) {
        for (int e : a) System.out.print(e + " ");
        System.out.println();
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {

            int n;
            n = Integer.parseInt(br.readLine());

            int w;
            w = Integer.parseInt(br.readLine());

            int[] cost = IntArray.input(br, n);

            Solution obj = new Solution();
            int res = obj.minimumCost(n, w, cost);

            System.out.println(res);
        }
    }
}

// } Driver Code Ends



class Solution {
    public static int minimumCost(int n, int w, int[] cost) {
        // code here
        int[][] dp = new int[n+1][w+1];
        for(int i = 0;i<n+1;i++){
            for(int j = 0;j<w+1;j++){
                dp[i][j] = -1;
            }
        }
        int ans = fun(0,n,w,cost,dp);
        return ans>=1000000000 ? -1 : ans;
    }
    public static int fun(int i,int n,int w,int[] cost,int[][] dp){
        if(w == 0) return 0;
        if(i >= n || w<0){
            return 1000000000;
        }
        
        if(dp[i][w]!=-1) return dp[i][w];
        int take = 1000000000;
        if(i+1 <= w){
            take = cost[i] + fun(i,n,w-(i+1),cost,dp);
        }
        return dp[i][w] = Math.min(take , fun(i+1,n,w,cost,dp));
    }
}
