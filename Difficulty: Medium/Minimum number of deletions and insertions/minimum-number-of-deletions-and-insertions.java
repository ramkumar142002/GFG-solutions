//{ Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*;
class GfG
{
    public static void main(String args[])
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    String s1 = sc.next();
                    String s2 = sc.next();
                    Solution ob = new Solution();
                    System.out.println(ob.minOperations(s1,s2));
                }
        }
}    
// } Driver Code Ends


//User function Template for Java

class Solution
{
	public int minOperations(String str1, String str2) 
	{ 
	    // Your code goes here
	   //  System.out.println(fun(str1,str2,str1.length()-1,str2.length()-1));
	    
	    return str1.length() + str2.length() -
	    (2*fun(str1,str2,str1.length(),str2.length()));
	} 
	 int fun(String s1,String s2,int n,int m)
    {
        // your code here
        // vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        int[][] dp = new int[n+1][m+1];
        for(int[] d:dp) Arrays.fill(d,0);
        // return f(n,m,s1,s2,dp);
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s1.charAt(i-1)==s2.charAt(j-1)) dp[i][j]=1+dp[i-1][j-1];
                else{
                    dp[i][j]=Math.max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
// 	public int fun(String s1, String s2,int i,int j){
	    
// 	    if(i<0 && j<0){
// 	       // System.out.println(i + " " + j);
// 	        return 0;
// 	    }
// 	    if(i<0 || j<0){
// 	        return 100000009;
// 	    }
// 	   // System.out.println(s1.charAt(i) + " " + s2.charAt(j));
// 	    if(s1.charAt(i) == s2.charAt(j)) return fun(s1,s2,i-1,j-1);
	    
// 	    int ins = 1 + fun(s1,s2,i-1,j-1);
// 	    int del = 1 + Math.min(fun(s1,s2,i-1,j-1) , fun(s1,s2,i,j-1));
	    
// 	    return Math.min(ins,del);
// 	}
}