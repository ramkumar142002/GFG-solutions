//{ Driver Code Starts
import java.io.*;
import java.util.*;

class gfg {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            int w = Integer.parseInt(br.readLine());

            String line = br.readLine();
            String[] tokens = line.split(" ");
            List<Integer> array = new ArrayList<>();

            // Parse the tokens into integers and add to the array
            for (String token : tokens) {
                array.add(Integer.parseInt(token));
            }

            int[] val = new int[array.size()];
            int idx = 0;
            for (int i : array) val[idx++] = i;

            String lin = br.readLine();
            String[] toke = lin.split(" ");
            List<Integer> array1 = new ArrayList<>();

            // Parse the tokens into integers and add to the array
            for (String token : toke) {
                array1.add(Integer.parseInt(token));
            }

            int[] wt = new int[array1.size()];
            idx = 0;
            for (int i : array1) wt[idx++] = i;

            // calling method knapSack() of class Solution
            System.out.println(new Solution().knapSack(w, wt, val));
        }
    }
}
// } Driver Code Ends


class Solution {
    // Function to return max value that can be put in knapsack of capacity W.
    static int knapSack(int W, int wt[], int val[]) {
        // your code here
        int[][] dp = new int[wt.length][W+1];
        for(int[] d:dp){
            Arrays.fill(d,-1);
        }
        return fun(wt,val,wt.length-1,W,dp);
    }
    static int fun(int wt[],int val[],int ind,int W,int dp[][]){
        if(W<=0) return 0;
        if(ind<0) return 0;
        
        if(dp[ind][W]!=-1) return dp[ind][W];
        int take = Integer.MIN_VALUE,notake = Integer.MIN_VALUE;
        if(wt[ind]<=W){
            take = val[ind] + fun(wt,val,ind-1,W-wt[ind],dp);
        }
        notake = fun(wt,val,ind-1,W,dp);
        
        return dp[ind][W] = Math.max(take,notake);
    }
}
