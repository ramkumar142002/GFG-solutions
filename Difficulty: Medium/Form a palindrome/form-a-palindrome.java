//{ Driver Code Starts
import java.io.*;
import java.util.*; 

class GFG{
    public static void main(String args[]) throws IOException { 
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        
        while(t-- > 0){
            String str = read.readLine();

            Solution ob = new Solution();
            
            System.out.println(ob.countMin(str));
        }
    } 
} 
// } Driver Code Ends


//User function Template for Java

class Solution{
    static int countMin(String str)
    {
        // code here
        StringBuffer sbr = new StringBuffer(str);
        sbr.reverse();
        String r = sbr.toString();
        
        int[][] dp = new int[str.length()+1][str.length()+1];
        for(int[] a:dp){
            Arrays.fill(a,-1);
        }
        int temp = fun(str.length(),r.length(),str,r,dp);
        return str.length() - temp;
    }
    
     static int fun(int i,int j,String s,String r,int dp[][]){
        if(i==0 || j==0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(s.charAt(i-1) == r.charAt(j-1)){
            return dp[i][j] = 1 + fun(i-1,j-1,s,r,dp);
        }
        return dp[i][j] = Math.max(fun(i-1,j,s,r,dp),fun(i,j-1,s,r,dp));
    }
}