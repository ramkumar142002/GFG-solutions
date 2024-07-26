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
            int M = sc.nextInt();

            int[][] grid = new int[N][M];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    grid[i][j] = sc.nextInt();
                }
            }

            Solution obj = new Solution();
            long res = obj.solve(N, M, grid);
            System.out.println(res);
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    public int solve(int n, int m, int grid[][]) {
        // Code here
        int[][][] dp  =new int[n][m][m];
        for(int[][] a:dp){
            for(int[] b:a){
                Arrays.fill(b,-1);
            }
        }
        return fun(grid,0,0,m-1,dp);
    }
    
    public int fun(int grid[][],int row,int i1,int i2,int dp[][][]){
        if(i1<0 || i1>=grid[0].length || i2<0 || i2>=grid[0].length) return -1000000009;
        // if(row>=grid.size()) return 1000000009;
        if(row == grid.length-1){
            if(i1 == i2) return grid[row][i1];
            else return grid[row][i1] + grid[row][i2];
        }
        
        if(dp[row][i1][i2]!=-1) return dp[row][i1][i2];
        int maxi = -1000000009;
        for(int del1 = -1;del1<2;del1++){
            for(int del2 = -1;del2<2;del2++){
                // i1 = i1+del1;
                // i2 = i2+del2;
                int total = 0;
                if(i1==i2) total = grid[row][i1] + fun(grid,row+1,i1+del1,i2+del2,dp);
                else{
                    total = grid[row][i1] + grid[row][i2] + fun(grid,row+1,i1+del1,i2+del2,dp);
                }
                
                maxi = Math.max(maxi,total);
            }
        }
        return dp[row][i1][i2] = maxi;
    }
}