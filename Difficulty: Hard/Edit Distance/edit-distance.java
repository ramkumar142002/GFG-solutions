//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            String s1 = br.readLine();
            String[] S = s1.split(" ");
            String s = S[0];
            String t = S[1];
            Solution ob = new Solution();
            int ans = ob.editDistance(s, t);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


class Solution {
    public int editDistance(String str1, String str2) {
        // Code here
        int[][] dp = new int[str1.length()][str2.length()];
        for(int[] a:dp){
            Arrays.fill(a,-1);
        }
        return fun(str1,str2,str1.length()-1,str2.length()-1,dp);
    }
    
    public int fun(String s1,String s2,int i,int j,int[][] dp){
        if(j<0) return i+1;
        if(i<0) return j+1;
        
        if(dp[i][j] != -1) return dp[i][j];
        if(s1.charAt(i) == s2.charAt(j)){
            return 0 + fun(s1,s2,i-1,j-1,dp);
        }
        int ins = 1 + fun(s1,s2,i,j-1,dp);
        int rep = 1 + fun(s1,s2,i-1,j-1,dp);
        int rem = 1 + fun(s1,s2,i-1,j,dp);
        
        return dp[i][j] = Math.min(rem , Math.min(ins,rep));
    }
}