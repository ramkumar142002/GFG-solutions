//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
class GfG
{
    public static void main (String[] args)
    {
        
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            String s = sc.next();

    		System.out.println (new Solution().countSubstr (s));
        }
        
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


//User function Template for Java

class Solution
{
    int countSubstr (String S)
    {
        // your code here
        int count = 0;
        for(int i = 0;i<S.length();i++){
            if(S.charAt(i) == '1'){
                // for(int j = i+1;j<S.length();j++){
                //     if(S.charAt(j) == '1') count++;
                // }
                count++;
            }
        }
        return count * (count-1)/2;
    }
}